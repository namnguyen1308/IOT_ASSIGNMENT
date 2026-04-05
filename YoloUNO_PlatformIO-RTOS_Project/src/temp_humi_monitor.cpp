#include "temp_humi_monitor.h"
#include "global.h" 

DHT20 dht20;
LiquidCrystal_I2C lcd(33, 16, 2);

void temp_humi_monitor(void *pvParameters){
    
    SensorContext_t *context = (SensorContext_t *)pvParameters;

    Wire.begin(11, 12);
    Serial.begin(115200);
    dht20.begin();

    lcd.begin();
    lcd.backlight();

    while (1){
        dht20.read();
        
        float temperature = dht20.getTemperature();
        float humidity = dht20.getHumidity();

        if (isnan(temperature) || isnan(humidity)) {
            Serial.println("Failed to read from DHT sensor!");
            vTaskDelay(pdMS_TO_TICKS(5000));
            continue;
        }

        uint8_t currentTempState = 0;
        if (temperature < 30.0) {
            currentTempState = 0; // Normal
        } else if (temperature >= 30.0 && temperature < 35.0) {
            currentTempState = 1; // Warning
        } else {
            currentTempState = 2; // Critical
        }

        
        if (xSemaphoreTake(context->dataMutex, portMAX_DELAY) == pdTRUE) {
            context->temperature = temperature;
            context->humidity = humidity;
            context->tempState = currentTempState; 
            xSemaphoreGive(context->dataMutex);
        }

        // LCD shows
        
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("T:"); lcd.print(temperature, 1); lcd.print("C ");
        lcd.print("H:"); lcd.print(humidity, 1); lcd.print("%");
        
        lcd.setCursor(0, 1);
        if (currentTempState == 0) lcd.print("State: NORMAL");
        else if (currentTempState == 1) lcd.print("State: WARNING");
        else lcd.print("State: CRITICAL");

   
        // include the data in struct 
        xSemaphoreGive(context->semTempUpdate); 

        // In ra Serial
        Serial.print("Humidity: ");
        Serial.print(humidity);
        Serial.print("%  Temperature: ");
        Serial.print(temperature);
        Serial.println("°C");
        
        vTaskDelay(pdMS_TO_TICKS(5000));
    }
}