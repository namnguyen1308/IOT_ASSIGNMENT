#include "task_webserver.h"

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

bool webserver_isrunning = false;

// ──────────────────────────────────────────────
//  GPIO definitions for the two controlled LEDs
// ──────────────────────────────────────────────
#define LED1_GPIO   2
#define LED2_GPIO   4

// ──────────────────────────────────────────────
//  Send arbitrary string to every WS client
// ──────────────────────────────────────────────
void Webserver_sendata(String data)
{
    if (ws.count() > 0)
    {
        ws.textAll(data);
        Serial.println("📤 WS send: " + data);
    }
    else
    {
        Serial.println("⚠️ No WS clients connected.");
    }
}

// ──────────────────────────────────────────────
//  Broadcast latest sensor readings
//  Call this from your temp/humi task whenever
//  new data is available, e.g.:
//      Webserver_sendSensors(glob_temperature, glob_humidity);
// ──────────────────────────────────────────────
void Webserver_sendSensors(float temp, float humi)
{
    String json = "{\"page\":\"sensor\",\"value\":{\"temp\":" +
                  String(temp, 1) + ",\"humi\":" + String(humi, 1) + "}}";
    Webserver_sendata(json);
}

// ──────────────────────────────────────────────
//  Echo current device state back to all clients
// ──────────────────────────────────────────────
void Webserver_sendDeviceState(const String &name, bool state, int gpio)
{
    String json = "{\"page\":\"device\",\"value\":{\"name\":\"" + name +
                  "\",\"status\":\"" + (state ? "ON" : "OFF") +
                  "\",\"gpio\":" + String(gpio) + "}}";
    Webserver_sendata(json);
}

// ──────────────────────────────────────────────
//  Handle WebSocket messages from the browser
// ──────────────────────────────────────────────
void handleWebSocketMessage(const String & message)
{
    Serial.println("📩 WS received: " + message);

    // ── Parse with ArduinoJson (include <ArduinoJson.h> in your header) ──
    StaticJsonDocument<256> doc;
    DeserializationError err = deserializeJson(doc, message);
    if (err)
    {
        Serial.println("⚠️ JSON parse error: " + String(err.c_str()));
        return;
    }

    const char *page = doc["page"];

    // ── Device control ──────────────────────────────────────────────────
    if (strcmp(page, "device") == 0)
    {
        const char *name   = doc["value"]["name"];
        const char *status = doc["value"]["status"];
        int         gpio   = doc["value"]["gpio"] | -1;

        Serial.printf("Device: %s  Status: %s  GPIO: %d\n", name, status, gpio);

        bool turnOn  = (strcmp(status, "ON")  == 0);
        bool blink   = (strcmp(status, "BLINK") == 0);

        // Determine which GPIO to act on
        int targetGPIO = -1;
        if      (strcmp(name, "LED1") == 0) targetGPIO = LED1_GPIO;
        else if (strcmp(name, "LED2") == 0) targetGPIO = LED2_GPIO;
        else if (gpio > 0)                  targetGPIO = gpio;

        if (targetGPIO >= 0)
        {
            pinMode(targetGPIO, OUTPUT);

            if (blink)
            {
                // Simple blink: 3 × 200 ms pulses
                for (int i = 0; i < 3; i++)
                {
                    digitalWrite(targetGPIO, HIGH);
                    vTaskDelay(pdMS_TO_TICKS(200));
                    digitalWrite(targetGPIO, LOW);
                    vTaskDelay(pdMS_TO_TICKS(200));
                }
                // Echo current state (OFF after blink sequence)
                Webserver_sendDeviceState(String(name), false, targetGPIO);
            }
            else
            {
                digitalWrite(targetGPIO, turnOn ? HIGH : LOW);
                // Echo confirmed state back to all clients
                Webserver_sendDeviceState(String(name), turnOn, targetGPIO);
            }
        }
    }

    // ── Settings (WiFi / MQTT) ───────────────────────────────────────────
    else if (strcmp(page, "setting") == 0)
    {
        const char *ssid     = doc["value"]["ssid"]     | "";
        const char *password = doc["value"]["password"] | "";
        const char *token    = doc["value"]["token"]    | "";
        const char *srv      = doc["value"]["server"]   | "";
        int         port     = doc["value"]["port"]     | 1883;

        Serial.printf("Settings → SSID:%s  Token:%s  Server:%s  Port:%d\n",
                      ssid, token, srv, port);

        // TODO: persist to LittleFS / NVS and trigger WiFi reconnect
        // Example:  saveWifiConfig(ssid, password);
        //           saveMqttConfig(token, srv, port);
        //           ESP.restart();  // or Wifi_reconnect();
    }
}

// ──────────────────────────────────────────────
//  WebSocket event handler
// ──────────────────────────────────────────────
void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client,
             AwsEventType type, void *arg, uint8_t *data, size_t len)
{
    if (type == WS_EVT_CONNECT)
    {
        Serial.printf("WS client #%u connected from %s\n",
                      client->id(), client->remoteIP().toString().c_str());
    }
    else if (type == WS_EVT_DISCONNECT)
    {
        Serial.printf("WS client #%u disconnected\n", client->id());
    }
    else if (type == WS_EVT_DATA)
    {
        AwsFrameInfo *info = (AwsFrameInfo *)arg;
        if (info->opcode == WS_TEXT)
        {
            String message = String((char *)data).substring(0, len);
            handleWebSocketMessage(message);
        }
    }
}

// ──────────────────────────────────────────────
//  Start server (called once)
// ──────────────────────────────────────────────
void connnectWSV()
{
    if (webserver_isrunning) return;

    // Init LED GPIOs
    pinMode(LED1_GPIO, OUTPUT);
    pinMode(LED2_GPIO, OUTPUT);
    digitalWrite(LED1_GPIO, LOW);
    digitalWrite(LED2_GPIO, LOW);

    ws.onEvent(onEvent);
    server.addHandler(&ws);

    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
    {
        request->send(LittleFS, "/index.html", "text/html");
    });

    server.on("/script.js", HTTP_GET, [](AsyncWebServerRequest *request)
    {
        request->send(LittleFS, "/script.js", "application/javascript");
    });

    server.on("/styles.css", HTTP_GET, [](AsyncWebServerRequest *request)
    {
        request->send(LittleFS, "/styles.css", "text/css");
    });

    ElegantOTA.begin(&server);

    server.begin();
    webserver_isrunning = true;
    Serial.println("✅ WebServer started");
}

// ──────────────────────────────────────────────
//  Stop server
// ──────────────────────────────────────────────
void Webserver_stop()
{
    ws.closeAll();
    server.end();
    webserver_isrunning = false;
}

// ──────────────────────────────────────────────
//  Keep OTA alive; restart server if stopped
// ──────────────────────────────────────────────
void Webserver_reconnect()
{
    if (!webserver_isrunning)
    {
        connnectWSV();
    }
    ElegantOTA.loop();
}

// ──────────────────────────────────────────────
//  FreeRTOS Task
//  xTaskCreate(WebserverTask, "WebServerTask", 12288, NULL, 1, NULL);
// ──────────────────────────────────────────────
void WebserverTask(void *pvParameters)
{
    connnectWSV();

    while (true)
    {
        ws.cleanupClients();    // free stale connections
        Webserver_reconnect();  // keep OTA + server alive
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}
