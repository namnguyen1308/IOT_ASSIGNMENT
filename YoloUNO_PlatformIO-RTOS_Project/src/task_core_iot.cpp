
#include "task_core_iot.h"

const char* coreIOT_Server = "10.235.76.226";  
const char* coreIOT_Token = "OSs7LTKUBEBiwSRZNN8m";   // Device Access Token
const int   mqttPort = 1883;

constexpr uint32_t MAX_MESSAGE_SIZE = 1024U;

WiFiClient wifiClient;
Arduino_MQTT_Client mqttClient(wifiClient);
ThingsBoard tb(mqttClient, MAX_MESSAGE_SIZE);

constexpr char LED_STATE_ATTR[] = "ledState";

volatile int ledMode = 0;
volatile bool ledState = false;

constexpr uint16_t BLINKING_INTERVAL_MS_MIN = 10U;
constexpr uint16_t BLINKING_INTERVAL_MS_MAX = 60000U;
volatile uint16_t blinkingInterval = 1000U;

constexpr int16_t telemetrySendInterval = 10000U;

constexpr std::array<const char *, 2U> SHARED_ATTRIBUTES_LIST = {
    LED_STATE_ATTR,
};

void processSharedAttributes(const Shared_Attribute_Data &data)
{
    for (auto it = data.begin(); it != data.end(); ++it)
    {
        // if (strcmp(it->key().c_str(), BLINKING_INTERVAL_ATTR) == 0)
        // {
        //     const uint16_t new_interval = it->value().as<uint16_t>();
        //     if (new_interval >= BLINKING_INTERVAL_MS_MIN && new_interval <= BLINKING_INTERVAL_MS_MAX)
        //     {
        //         blinkingInterval = new_interval;
        //         Serial.print("Blinking interval is set to: ");
        //         Y
        //             Serial.println(new_interval);
        //     }
        // }
        // if (strcmp(it->key().c_str(), LED_STATE_ATTR) == 0)
        // {
        //     ledState = it->value().as<bool>();
        // digitalWrite(LED_PIN, ledState);
        // Serial.print("LED state is set to: ");
        // Serial.println(ledState);
        // }
    }
}

RPC_Response setLedSwitchValue(const RPC_Data &data)
{
    Serial.println("Received Switch state");
    bool newState = data;
    Serial.print("Switch state change: ");
    Serial.println(newState);
    return RPC_Response("setLedSwitchValue", newState);
}

const std::array<RPC_Callback, 1U> callbacks = {
    RPC_Callback{"setLedSwitchValue", setLedSwitchValue}};

const Shared_Attribute_Callback attributes_callback(&processSharedAttributes, SHARED_ATTRIBUTES_LIST.cbegin(), SHARED_ATTRIBUTES_LIST.cend());
const Attribute_Request_Callback attribute_shared_request_callback(&processSharedAttributes, SHARED_ATTRIBUTES_LIST.cbegin(), SHARED_ATTRIBUTES_LIST.cend());

void CORE_IOT_sendata(String mode, String feed, String data)
{
    if (mode == "attribute")
    {
        tb.sendAttributeData(feed.c_str(), data);
    }
    else if (mode == "telemetry")
    {
        float value = data.toFloat();
        tb.sendTelemetryData(feed.c_str(), value);
    }
    else
    {
        // handle unknown mode
    }
}

void CORE_IOT_reconnect()
{
    if (!tb.connected())
    {
        if (!tb.connect(CORE_IOT_SERVER.c_str(), CORE_IOT_TOKEN.c_str(), CORE_IOT_PORT.toInt()))
        {
            // Serial.println("Failed to connect");
            return;
        }

        tb.sendAttributeData("macAddress", WiFi.macAddress().c_str());

        Serial.println("Subscribing for RPC...");
        if (!tb.RPC_Subscribe(callbacks.cbegin(), callbacks.cend()))
        {
            // Serial.println("Failed to subscribe for RPC");
            return;
        }

        if (!tb.Shared_Attributes_Subscribe(attributes_callback))
        {
            // Serial.println("Failed to subscribe for shared attribute updates");
            return;
        }

        Serial.println("Subscribe done");

        if (!tb.Shared_Attributes_Request(attribute_shared_request_callback))
        {
            // Serial.println("Failed to request for shared attributes");
            return;
        }
        tb.sendAttributeData("localIp", WiFi.localIP().toString().c_str());
    }
    else if (tb.connected())
    {
        tb.loop();
    }
}

void coreiot_task(void *pvParameters) {
    
    SensorContext_t *context = (SensorContext_t *)pvParameters;

    while(1) {
        // 1. Check connect
        if (!tb.connected()) {
            Serial.println("Đang kết nối tới CoreIOT...");
            CORE_IOT_reconnect(); 
        } 
        else {
          
            tb.loop();

           
            float temp = 0.0, humi = 0.0;
            //int soil = 0;

            
            if (xSemaphoreTake(context->dataMutex, portMAX_DELAY) == pdTRUE) {
                temp = context->temperature;
                humi = context->humidity;
                //soil = context->soilMoisture;
                xSemaphoreGive(context->dataMutex); 
            }

            
            tb.sendTelemetryData("temperature", temp);
            tb.sendTelemetryData("humidity", humi);
            //tb.sendTelemetryData("soilMoisture", soil);

            Serial.printf("CoreIOT Publish -> T: %.1f, H: %.1f, Soil: %d\n", temp, humi);
        }

        // Delay 5 giây rồi mới gửi tiếp (tránh spam làm nghẽn server)
        vTaskDelay(pdMS_TO_TICKS(5000));
    }
}
