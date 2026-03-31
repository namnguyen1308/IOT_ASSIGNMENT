// #include "coreiot.h"
// #include "global.h" // Chắc chắn bạn đã include global.h để dùng được SensorContext_t

// // ----------- CONFIGURE THESE! -----------
// // Đảm bảo địa chỉ server khớp với nền tảng bạn dùng.
// // Trong PDF yêu cầu là app.coreiot.io, nên nếu IP dưới đây là mạng nội bộ của trường thì bạn cứ giữ, 
// // nếu không hãy đổi thành "app.coreiot.io"
// const char* coreIOT_Server = "10.235.76.226";  
// const char* coreIOT_Token = "OSs7LTKUBEBiwSRZNN8m";   // THAY BẰNG TOKEN CỦA BẠN TRÊN COREIOT!
// const int   mqttPort = 1883;
// // ----------------------------------------

// WiFiClient espClient;
// PubSubClient client(espClient);

// void reconnect() {
//   // Loop until we're reconnected
//   while (!client.connected()) {
//     Serial.print("Attempting MQTT connection...");
    
//     String clientId = "ESP32Client-";
//     clientId += String(random(0xffff), HEX);

//     // SỬA LỖI: Bắt buộc truyền coreIOT_Token vào làm username để server xác thực
//     if (client.connect(clientId.c_str(), coreIOT_Token, NULL)) {
        
//       Serial.println("connected to CoreIOT Server!");
//       client.subscribe("v1/devices/me/rpc/request/+");
//       Serial.println("Subscribed to v1/devices/me/rpc/request/+");

//     } else {
//       Serial.print("failed, rc=");
//       Serial.print(client.state());
//       Serial.println(" try again in 5 seconds");
//       vTaskDelay(pdMS_TO_TICKS(5000)); // Dùng vTaskDelay thay vì delay() trong FreeRTOS
//     }
//   }
// }

// void callback(char* topic, byte* payload, unsigned int length) {
//   Serial.print("Message arrived [");
//   Serial.print(topic);
//   Serial.println("] ");

//   // Allocate a temporary buffer for the message
//   char message[length + 1];
//   memcpy(message, payload, length);
//   message[length] = '\0';
//   Serial.print("Payload: ");
//   Serial.println(message);

//   // Parse JSON
//   StaticJsonDocument<256> doc;
//   DeserializationError error = deserializeJson(doc, message);

//   if (error) {
//     Serial.print("deserializeJson() failed: ");
//     Serial.println(error.c_str());
//     return;
//   }

//   const char* method = doc["method"];
//   if (strcmp(method, "setStateLED") == 0) {
//     const char* params = doc["params"];
//     if (strcmp(params, "ON") == 0) {
//       Serial.println("Device turned ON.");
//       //TODO: Thêm Semaphore để báo Task điều khiển LED nếu cần
//     } else {   
//       Serial.println("Device turned OFF.");
//       //TODO: Thêm Semaphore để báo Task điều khiển LED nếu cần
//     }
//   } else {
//     Serial.print("Unknown method: ");
//     Serial.println(method);
//   }
// }

// void setup_coreiot(){
//   // Chờ cho đến khi Task WiFi phát Semaphore xác nhận đã có Internet
//   while(1){
//     if (xSemaphoreTake(xBinarySemaphoreInternet, portMAX_DELAY)) {
//       // Trả lại Semaphore để các Task khác (như Webserver) cũng có thể check được Internet
//       xSemaphoreGive(xBinarySemaphoreInternet); 
//       break;
//     }
//     vTaskDelay(pdMS_TO_TICKS(500));
//     Serial.print(".");
//   }

//   Serial.println(" Internet Connected! Starting CoreIOT...");

//   // Lưu ý: Đảm bảo CORE_IOT_SERVER và CORE_IOT_PORT đã được gán giá trị đúng ở đâu đó (vd: đọc từ bộ nhớ flash/webserver)
//   client.setServer(CORE_IOT_SERVER.c_str(), CORE_IOT_PORT.toInt());
//   client.setCallback(callback);
// }

// void coreiot_task(void *pvParameters){
//     // Ép kiểu pvParameters để lấy các Semaphore và dữ liệu
//     SensorContext_t *context = (SensorContext_t *)pvParameters;
    
//     setup_coreiot();

//     while(1){
//         if (!client.connected()) {
//             reconnect();
//         }
//         client.loop();

//         float currentTemp = 0.0;
//         float currentHumi = 0.0;

//         // ĐỌC DỮ LIỆU AN TOÀN QUA MUTEX (Thay thế biến toàn cục)
//         if (xSemaphoreTake(context->dataMutex, portMAX_DELAY) == pdTRUE) {
//             currentTemp = context->temperature;
//             currentHumi = context->humidity;
//             xSemaphoreGive(context->dataMutex); // Đọc xong phải nhả Mutex ra ngay
//         }

//         // Đóng gói payload JSON với dữ liệu vừa đọc
//         String payload = "{\"temperature\":" + String(currentTemp, 1) +  ",\"humidity\":" + String(currentHumi, 1) + "}";
        
//         client.publish("v1/devices/me/telemetry", payload.c_str());
        
//         Serial.println("Published payload: " + payload);
        
//         // Publish mỗi 10 giây
//         vTaskDelay(pdMS_TO_TICKS(10000));  
//     }
// }