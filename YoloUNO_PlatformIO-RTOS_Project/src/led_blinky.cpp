#include "led_blinky.h"

void led_blinky(void *pvParameters){
  pinMode(LED_GPIO, OUTPUT);
  SensorContext_t *context = (SensorContext_t *)pvParameters;
  TickType_t xDelayTime;
  while(1) {                        
    // digitalWrite(LED_GPIO, HIGH);  // turn the LED ON
    // vTaskDelay(1000);
    // digitalWrite(LED_GPIO, LOW);  // turn the LED OFF
    // vTaskDelay(1000);


    if (xSemaphoreTake(context->semTempUpdate, portMAX_DELAY) == pdTRUE){
      if(context->tempState == STATE_CRITIAL){
        xDelayTime = 100;
      }
      else if(context->tempState == STATE_WARNING){
        xDelayTime = 500;
      }
      else if(context->tempState == STATE_NOMAL){
        xDelayTime = 1000;
      }
      digitalWrite(LED_GPIO, HIGH);
      vTaskDelay(pdMS_TO_TICKS(xDelayTime));
      digitalWrite(LED_GPIO, LOW);
      vTaskDelay(pdMS_TO_TICKS(xDelayTime));
    }

    
  }
}