#include "task_webserver.h"
#include "global.h"

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

bool webserver_isrunning = false;

// Track device states
struct RelayDevice {
    int id;
    String name;
    int gpio;
    bool state;
};

std::vector<RelayDevice> relayDevices;
int nextRelayId = 1;

// Default relay configuration (can be loaded from storage)
void initDefaultRelays() {
    if (relayDevices.empty()) {
        relayDevices.push_back({nextRelayId++, "Relay 1", 2, false});
        relayDevices.push_back({nextRelayId++, "Relay 2", 4, false});
        relayDevices.push_back({nextRelayId++, "Relay 3", 5, false});
        relayDevices.push_back({nextRelayId++, "Relay 4", 18, false});
    }
}

// Control a relay by GPIO
void controlRelay(int gpio, bool turnOn) {
    pinMode(gpio, OUTPUT);
    digitalWrite(gpio, turnOn ? HIGH : LOW);
    Serial.printf("🔌 GPIO %d turned %s\n", gpio, turnOn ? "ON" : "OFF");
}

// Send current sensor data to all connected clients
void Webserver_send_sensor_data(float temperature, float humidity) {
    if (ws.count() > 0) {
        StaticJsonDocument<256> doc;
        doc["type"] = "sensor_update";
        doc["temperature"] = temperature;
        doc["humidity"] = humidity;
        
        String jsonString;
        serializeJson(doc, jsonString);
        ws.textAll(jsonString);
    }
}

// Send all relay states to a specific client (or all)
void Webserver_send_relay_states(int clientId = -1) {
    StaticJsonDocument<1024> doc;
    doc["type"] = "relay_list";
    
    JsonArray relays = doc.createNestedArray("relays");
    for (const auto& relay : relayDevices) {
        JsonObject obj = relays.createNestedObject();
        obj["id"] = relay.id;
        obj["name"] = relay.name;
        obj["gpio"] = relay.gpio;
        obj["state"] = relay.state;
    }
    
    String jsonString;
    serializeJson(doc, jsonString);
    
    if (clientId == -1) {
        ws.textAll(jsonString);
    } else {
        ws.text(clientId, jsonString);
    }
}

// Handle WebSocket messages from frontend
void handleWebSocketMessage(String message) {
    Serial.println("📨 Received: " + message);
    
    StaticJsonDocument<1024> doc;
    DeserializationError error = deserializeJson(doc, message);
    
    if (error) {
        Serial.println("❌ JSON parse error: " + String(error.c_str()));
        return;
    }
    
    String page = doc["page"] | "";
    JsonObject value = doc["value"];
    
    // Handle device control from "Thiết bị" page
    if (page == "device") {
        if (value.containsKey("name") && value.containsKey("status") && value.containsKey("gpio")) {
            String name = value["name"].as<String>();
            String status = value["status"].as<String>();
            int gpio = value["gpio"];
            bool turnOn = status.equalsIgnoreCase("ON");
            
            // Find and update relay state
            for (auto& relay : relayDevices) {
                if (relay.name == name && relay.gpio == gpio) {
                    relay.state = turnOn;
                    controlRelay(gpio, turnOn);
                    break;
                }
            }
            
            // Send confirmation back
            StaticJsonDocument<256> response;
            response["type"] = "device_response";
            response["success"] = true;
            response["gpio"] = gpio;
            response["status"] = turnOn ? "ON" : "OFF";
            
            String responseStr;
            serializeJson(response, responseStr);
            ws.textAll(responseStr);
        }
    }
    // Handle adding new relay
    else if (page == "add_relay") {
        if (value.containsKey("name") && value.containsKey("gpio")) {
            String name = value["name"].as<String>();
            int gpio = value["gpio"];
            
            // Check if GPIO already in use
            bool gpioInUse = false;
            for (const auto& relay : relayDevices) {
                if (relay.gpio == gpio) {
                    gpioInUse = true;
                    break;
                }
            }
            
            if (!gpioInUse) {
                relayDevices.push_back({nextRelayId++, name, gpio, false});
                controlRelay(gpio, false); // Initialize to OFF
                Webserver_send_relay_states(); // Broadcast updated list
                
                StaticJsonDocument<256> response;
                response["type"] = "add_relay_response";
                response["success"] = true;
                response["message"] = "Relay added successfully";
                String responseStr;
                serializeJson(response, responseStr);
                ws.textAll(responseStr);
            } else {
                StaticJsonDocument<256> response;
                response["type"] = "add_relay_response";
                response["success"] = false;
                response["message"] = "GPIO already in use";
                String responseStr;
                serializeJson(response, responseStr);
                ws.textAll(responseStr);
            }
        }
    }
    // Handle deleting relay
    else if (page == "delete_relay") {
        if (value.containsKey("id")) {
            int id = value["id"];
            auto it = std::find_if(relayDevices.begin(), relayDevices.end(), 
                [id](const RelayDevice& r) { return r.id == id; });
            
            if (it != relayDevices.end()) {
                relayDevices.erase(it);
                Webserver_send_relay_states(); // Broadcast updated list
                
                StaticJsonDocument<256> response;
                response["type"] = "delete_relay_response";
                response["success"] = true;
                String responseStr;
                serializeJson(response, responseStr);
                ws.textAll(responseStr);
            }
        }
    }
    // Handle settings configuration (WiFi + CoreIOT)
    else if (page == "setting") {
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
        StaticJsonDocument<256> response;
        response["status"] = "ok";
        response["page"] = "setting_saved";
        response["message"] = "Configuration saved. Device will restart.";
        
        String responseStr;
        serializeJson(response, responseStr);
        ws.textAll(responseStr);
        
        // Delay restart to allow response to be sent
        vTaskDelay(pdMS_TO_TICKS(1000));
        ESP.restart();
    }
}

void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len) {
    if (type == WS_EVT_CONNECT) {
        Serial.printf("🔌 WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
        
        // Send current relay states to the new client
        Webserver_send_relay_states(client->id());
        
    } else if (type == WS_EVT_DISCONNECT) {
        Serial.printf("🔌 WebSocket client #%u disconnected\n", client->id());
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
    
    server.on("/styles.css", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(LittleFS, "/styles.css", "text/css");
    });
    
    server.on("/script.js", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(LittleFS, "/script.js", "application/javascript");
    });
    
    server.begin();
    ElegantOTA.begin(&server);
    webserver_isrunning = true;
    Serial.println("🌐 Web server started");
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
        initDefaultRelays();
    }
    ElegantOTA.loop();
}
