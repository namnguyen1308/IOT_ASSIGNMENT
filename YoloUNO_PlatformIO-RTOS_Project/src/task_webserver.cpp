#include "task_webserver.h"

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

bool webserver_isrunning = false;
bool led1_state = false;
bool led2_state = false;

// GPIO pins for controlled devices (adjust as needed)
#define DEVICE1_GPIO 2  // LED1 or other device
#define DEVICE2_GPIO 4  // LED2 or other device

void Webserver_sendata(String data) {
    if (ws.count() > 0) {
        ws.textAll(data);
        Serial.println("📤 WebSocket data sent: " + data);
    } else {
        Serial.println("⚠️ No WebSocket clients connected");
    }
}

// Send sensor data to all connected WebSocket clients
void Webserver_send_sensor_data(float temperature, float humidity) {
    StaticJsonDocument<256> doc;
    doc["type"] = "sensor_data";
    doc["temperature"] = temperature;
    doc["humidity"] = humidity;
    doc["led1"] = led1_state ? "ON" : "OFF";
    doc["led2"] = led2_state ? "ON" : "OFF";
    
    String jsonString;
    serializeJson(doc, jsonString);
    Webserver_sendata(jsonString);
}

// Control device based on GPIO and status
void control_device(int gpio, bool turn_on) {
    pinMode(gpio, OUTPUT);
    digitalWrite(gpio, turn_on ? HIGH : LOW);
    
    // Update state tracking
    if (gpio == DEVICE1_GPIO) {
        led1_state = turn_on;
        Serial.printf("🔆 Device 1 (GPIO %d) turned %s\n", gpio, turn_on ? "ON" : "OFF");
    } else if (gpio == DEVICE2_GPIO) {
        led2_state = turn_on;
        Serial.printf("🔆 Device 2 (GPIO %d) turned %s\n", gpio, turn_on ? "ON" : "OFF");
    }
}

void handleWebSocketMessage(String message) {
    Serial.println("Received WebSocket message: " + message);
    
    StaticJsonDocument<512> doc;
    DeserializationError error = deserializeJson(doc, message);
    
    if (error) {
        Serial.println("❌ JSON parse error: " + String(error.c_str()));
        return;
    }
    
    String page = doc["page"] | "";
    JsonObject value = doc["value"];
    
    if (page == "device") {
        // Handle device control
        if (!value.containsKey("gpio") || !value.containsKey("status")) {
            Serial.println("⚠️ JSON missing gpio or status field");
            return;
        }
        
        int gpio = value["gpio"];
        String status = value["status"].as<String>();
        bool turn_on = status.equalsIgnoreCase("ON");
        
        Serial.printf("⚙️ Controlling GPIO %d → %s\n", gpio, turn_on ? "ON" : "OFF");
        control_device(gpio, turn_on);
        
        // Send confirmation back
        StaticJsonDocument<256> response;
        response["type"] = "device_response";
        response["gpio"] = gpio;
        response["status"] = turn_on ? "ON" : "OFF";
        response["success"] = true;
        
        String responseStr;
        serializeJson(response, responseStr);
        Webserver_sendata(responseStr);
        
    } else if (page == "setting") {
        // Handle WiFi and CoreIOT configuration
        String WIFI_SSID = value["ssid"].as<String>();
        String WIFI_PASS = value["password"].as<String>();
        String CORE_IOT_TOKEN = value["token"].as<String>();
        String CORE_IOT_SERVER = value["server"].as<String>();
        String CORE_IOT_PORT = value["port"].as<String>();
        
        Serial.println("📥 Received configuration:");
        Serial.println("  SSID: " + WIFI_SSID);
        Serial.println("  PASS: " + WIFI_PASS);
        Serial.println("  TOKEN: " + CORE_IOT_TOKEN);
        Serial.println("  SERVER: " + CORE_IOT_SERVER);
        Serial.println("  PORT: " + CORE_IOT_PORT);
        
        // Save configuration
        Save_info_File(WIFI_SSID, WIFI_PASS, CORE_IOT_TOKEN, CORE_IOT_SERVER, CORE_IOT_PORT);
        
        // Send success response
        String msg = "{\"status\":\"ok\",\"page\":\"setting_saved\",\"message\":\"Configuration saved. Device will restart.\"}";
        ws.textAll(msg);
    }
}

void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len) {
    if (type == WS_EVT_CONNECT) {
        Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
        
        // Send initial device states to new client
        StaticJsonDocument<256> initMsg;
        initMsg["type"] = "init";
        initMsg["led1"] = led1_state ? "ON" : "OFF";
        initMsg["led2"] = led2_state ? "ON" : "OFF";
        
        String initStr;
        serializeJson(initMsg, initStr);
        client->text(initStr);
        
    } else if (type == WS_EVT_DISCONNECT) {
        Serial.printf("WebSocket client #%u disconnected\n", client->id());
    } else if (type == WS_EVT_DATA) {
        AwsFrameInfo *info = (AwsFrameInfo *)arg;
        
        if (info->opcode == WS_TEXT) {
            String message;
            message = String((char *)data).substring(0, len);
            handleWebSocketMessage(message);
        }
    }
}

void connectWebSocket() {
    ws.onEvent(onEvent);
    server.addHandler(&ws);
    
    // Serve static files from LittleFS
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(LittleFS, "/index.html", "text/html");
    });
    
    server.on("/script.js", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(LittleFS, "/script.js", "application/javascript");
    });
    
    server.on("/styles.css", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(LittleFS, "/styles.css", "text/css");
    });
    
    server.begin();
    ElegantOTA.begin(&server);
    webserver_isrunning = true;
    Serial.println("🌐 Web server started in AP mode");
    Serial.println("📡 Access Point IP: " + WiFi.softAPIP().toString());
}

void Webserver_stop() {
    ws.closeAll();
    server.end();
    webserver_isrunning = false;
    Serial.println("Web server stopped");
}

void Webserver_reconnect() {
    if (!webserver_isrunning) {
        connectWebSocket();
    }
    ElegantOTA.loop();
}
