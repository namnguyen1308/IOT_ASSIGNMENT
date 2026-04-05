#include <task_handler.h>

// void handleWebSocketMessage(String message)
// {
//     Serial.println("📨 Received: " + message);
    
//     StaticJsonDocument<1024> doc;
//     DeserializationError error = deserializeJson(doc, message);
    
//     if (error)
//     {
//         Serial.println("❌ JSON parse error: " + String(error.c_str()));
//         return;
//     }
    
//     JsonObject value = doc["value"];
//     String page = doc["page"] | "";
    
//     // Handle device control from "Thiết bị" page
//     if (page == "device")
//     {
//         if (!value.containsKey("gpio") || !value.containsKey("status"))
//         {
//             Serial.println("⚠️ JSON missing gpio or status field");
//             return;
//         }
        
//         int gpio = value["gpio"];
//         String status = value["status"].as<String>();
//         bool turnOn = status.equalsIgnoreCase("ON");
        
//         Serial.printf("⚙️ Controlling GPIO %d → %s\n", gpio, turnOn ? "ON" : "OFF");
//         pinMode(gpio, OUTPUT);
//         digitalWrite(gpio, turnOn ? HIGH : LOW);
        
//         // Send confirmation back
//         StaticJsonDocument<256> response;
//         response["type"] = "device_response";
//         response["success"] = true;
//         response["gpio"] = gpio;
//         response["status"] = turnOn ? "ON" : "OFF";
        
//         String responseStr;
//         serializeJson(response, responseStr);
//         ws.textAll(responseStr);
//     }
//     // Handle adding new relay
//     else if (page == "add_relay")
//     {
//         if (value.containsKey("name") && value.containsKey("gpio"))
//         {
//             String name = value["name"].as<String>();
//             int gpio = value["gpio"];
            
//             Serial.printf("➕ Adding new relay: %s on GPIO %d\n", name.c_str(), gpio);
            
//             // You can store this in a vector or EEPROM
//             StaticJsonDocument<256> response;
//             response["type"] = "add_relay_response";
//             response["success"] = true;
//             response["message"] = "Relay added successfully";
            
//             String responseStr;
//             serializeJson(response, responseStr);
//             ws.textAll(responseStr);
//         }
//     }
//     // Handle deleting relay
//     else if (page == "delete_relay")
//     {
//         if (value.containsKey("id"))
//         {
//             int id = value["id"];
//             Serial.printf("🗑️ Deleting relay with ID: %d\n", id);
            
//             StaticJsonDocument<256> response;
//             response["type"] = "delete_relay_response";
//             response["success"] = true;
            
//             String responseStr;
//             serializeJson(response, responseStr);
//             ws.textAll(responseStr);
//         }
//     }
//     // Handle settings configuration
//     else if (page == "setting")
//     {
//         String WIFI_SSID = value["ssid"].as<String>();
//         String WIFI_PASS = value["password"].as<String>();
//         String CORE_IOT_TOKEN = value["token"].as<String>();
//         String CORE_IOT_SERVER = value["server"].as<String>();
//         String CORE_IOT_PORT = value["port"].as<String>();
        
//         Serial.println("📥 Received configuration from WebSocket:");
//         Serial.println("  SSID: " + WIFI_SSID);
//         Serial.println("  PASS: " + WIFI_PASS);
//         Serial.println("  TOKEN: " + CORE_IOT_TOKEN);
//         Serial.println("  SERVER: " + CORE_IOT_SERVER);
//         Serial.println("  PORT: " + CORE_IOT_PORT);
        
//         // Save configuration
//         Save_info_File(WIFI_SSID, WIFI_PASS, CORE_IOT_TOKEN, CORE_IOT_SERVER, CORE_IOT_PORT);
        
//         // Send success response
//         StaticJsonDocument<256> response;
//         response["status"] = "ok";
//         response["page"] = "setting_saved";
//         response["message"] = "Configuration saved. Device will restart.";
        
//         String responseStr;
//         serializeJson(response, responseStr);
//         ws.textAll(responseStr);
//     }
// }
