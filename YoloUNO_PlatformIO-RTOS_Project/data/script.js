// ==================== WEBSOCKET ====================
var gateway = `ws://${window.location.hostname}/ws`;
var websocket;

// Device state store
var devices = {
  LED1: { state: false, gpio: 2,  name: "LED 1", desc: "Status Indicator" },
  LED2: { state: false, gpio: 4,  name: "LED 2", desc: "Alert Indicator"  }
};

window.addEventListener('load', () => {
  initWebSocket();
});

function initWebSocket() {
  console.log('Opening WebSocket…');
  websocket = new WebSocket(gateway);
  websocket.onopen    = onOpen;
  websocket.onclose   = onClose;
  websocket.onmessage = onMessage;
}

function onOpen() {
  console.log('WS connected');
  setWsStatus(true);
}

function onClose() {
  console.log('WS disconnected – retrying in 2 s');
  setWsStatus(false);
  setTimeout(initWebSocket, 2000);
}

function setWsStatus(connected) {
  const dot   = document.getElementById('wsDot');
  const label = document.getElementById('wsLabel');
  dot.className   = 'ws-dot ' + (connected ? 'connected' : 'disconnected');
  label.textContent = connected ? 'Connected' : 'Disconnected';
}

function Send_Data(data) {
  if (websocket && websocket.readyState === WebSocket.OPEN) {
    websocket.send(data);
    console.log('📤 Sent:', data);
  } else {
    console.warn('WS not ready');
    showToast('⚠️ WebSocket not connected');
  }
}

/**
 * onMessage – handles incoming JSON from ESP32
 * Expected payloads:
 *   { "page": "sensor",  "value": { "temp": 26.5, "humi": 62 } }
 *   { "page": "device",  "value": { "name": "LED1", "status": "ON" } }
 */
function onMessage(event) {
  console.log('📩 Received:', event.data);
  try {
    var data = JSON.parse(event.data);

    if (data.page === 'sensor' && data.value) {
      updateSensorUI(data.value.temp, data.value.humi);
    }

    if (data.page === 'device' && data.value) {
      var id = data.value.name;        // "LED1" or "LED2"
      var st = data.value.status === 'ON';
      if (devices[id] !== undefined) {
        devices[id].state = st;
        refreshDeviceCard(id);
        refreshQuickBtn(id);
      }
    }

  } catch (e) {
    console.warn('Non-JSON message:', event.data);
  }
}


// ==================== NAVIGATION ====================
function showSection(id, event) {
  document.querySelectorAll('.section').forEach(s => s.style.display = 'none');
  document.getElementById(id).style.display = 'block';
  document.querySelectorAll('.nav-item').forEach(i => i.classList.remove('active'));
  event.currentTarget.classList.add('active');
}


// ==================== SENSOR UI ====================
function updateSensorUI(temp, humi) {
  if (temp !== undefined && temp !== null) {
    document.getElementById('tempValue').textContent = parseFloat(temp).toFixed(1);
    // Bar: map -10…50 → 0…100%
    var pct = Math.min(100, Math.max(0, ((temp + 10) / 60) * 100));
    document.getElementById('tempBar').style.width = pct + '%';
    var status = temp >= 35 ? '🔴 Critical' : temp >= 28 ? '🟡 Warning' : '🟢 Normal';
    document.getElementById('tempStatus').textContent = status;
  }
  if (humi !== undefined && humi !== null) {
    document.getElementById('humiValue').textContent = parseFloat(humi).toFixed(1);
    document.getElementById('humiBar').style.width = Math.min(100, Math.max(0, humi)) + '%';
    var hStatus = humi > 80 ? '🟡 High' : humi < 30 ? '🟡 Low' : '🟢 Comfortable';
    document.getElementById('humiStatus').textContent = hStatus;
  }
}


// ==================== DEVICE CONTROL ====================

/**
 * Send a device command over WebSocket
 * page: "device"
 * value: { name, status, gpio }
 */
function sendDeviceCommand(id, status) {
  var dev = devices[id];
  var payload = JSON.stringify({
    page: "device",
    value: {
      name:   id,
      status: status,
      gpio:   dev.gpio
    }
  });
  Send_Data(payload);
}

/** Toggle a device ON/OFF */
function toggleDevice(id) {
  var dev = devices[id];
  dev.state = !dev.state;
  sendDeviceCommand(id, dev.state ? 'ON' : 'OFF');
  refreshDeviceCard(id);
  refreshQuickBtn(id);
  showToast((dev.state ? '💡 ' : '🌑 ') + dev.name + ' turned ' + (dev.state ? 'ON' : 'OFF'));
}

/** Quick-toggle from dashboard card */
function quickToggle(id) {
  toggleDevice(id);
}

/** Blink command – turns ON then OFF after 500 ms (handled on ESP32 side) */
function blinkDevice(id) {
  var dev = devices[id];
  var payload = JSON.stringify({
    page: "device",
    value: {
      name:   id,
      status: 'BLINK',
      gpio:   dev.gpio
    }
  });
  Send_Data(payload);
  showToast('✨ Blink sent to ' + dev.name);
}

/** Bulk control */
function bulkControl(status) {
  Object.keys(devices).forEach(id => {
    devices[id].state = (status === 'ON');
    sendDeviceCommand(id, status);
    refreshDeviceCard(id);
    refreshQuickBtn(id);
  });
  showToast(status === 'ON' ? '💡 All devices ON' : '🌑 All devices OFF');
}

/** Refresh a device card DOM */
function refreshDeviceCard(id) {
  var dev = devices[id];
  var btn   = document.getElementById('btn-' + id);
  var ring  = document.getElementById('ring-' + id);
  var label = document.getElementById('state-' + id);
  if (!btn) return;

  if (dev.state) {
    btn.classList.add('on');
    ring.classList.add('on');
    label.textContent = 'ON';
    label.classList.add('on');
  } else {
    btn.classList.remove('on');
    ring.classList.remove('on');
    label.textContent = 'OFF';
    label.classList.remove('on');
  }
}

/** Refresh quick-control buttons on Dashboard */
function refreshQuickBtn(id) {
  var btn = document.getElementById('q' + id); // qLed1, qLed2
  if (!btn) return;
  if (devices[id].state) {
    btn.classList.add('on');
  } else {
    btn.classList.remove('on');
  }
}

/** Device info modal */
function deviceInfo(id) {
  var dev = devices[id];
  document.getElementById('modalTitle').textContent = dev.name + ' — Info';
  document.getElementById('modalBody').innerHTML = `
    <div class="modal-body-row"><span>ID</span><span>${id}</span></div>
    <div class="modal-body-row"><span>GPIO</span><span>${dev.gpio}</span></div>
    <div class="modal-body-row"><span>Description</span><span>${dev.desc}</span></div>
    <div class="modal-body-row"><span>Current State</span><span>${dev.state ? 'ON' : 'OFF'}</span></div>
  `;
  document.getElementById('infoModal').style.display = 'flex';
}

function closeModal() {
  document.getElementById('infoModal').style.display = 'none';
}


// ==================== SETTINGS ====================
function saveSettings() {
  var ssid     = document.getElementById('ssid').value.trim();
  var password = document.getElementById('password').value.trim();
  var token    = document.getElementById('token').value.trim();
  var server   = document.getElementById('server').value.trim();
  var port     = document.getElementById('port').value.trim();

  if (!ssid) { showToast('⚠️ SSID is required'); return; }

  var payload = JSON.stringify({
    page: "setting",
    value: { ssid, password, token, server, port }
  });
  Send_Data(payload);

  var fb = document.getElementById('saveFeedback');
  fb.textContent = '✓ Saved & sent to device';
  fb.classList.add('show');
  setTimeout(() => fb.classList.remove('show'), 3000);
}


// ==================== TOAST ====================
var _toastTimer;
function showToast(msg) {
  var el = document.getElementById('toast');
  el.textContent = msg;
  el.classList.add('show');
  clearTimeout(_toastTimer);
  _toastTimer = setTimeout(() => el.classList.remove('show'), 2500);
}
