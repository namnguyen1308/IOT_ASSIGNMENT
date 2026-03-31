#include "global.h"

#include "led_blinky.h"
#include "neo_blinky.h"
#include "temp_humi_monitor.h"
// #include "mainserver.h"
// #include "tinyml.h"
#include "coreiot.h"

// include task
#include "task_check_info.h"
#include "task_toogle_boot.h"
#include "task_wifi.h"
#include "task_webserver.h"
#include "task_core_iot.h"

void setup()
{
  Serial.begin(115200);
  check_info_File(0);

  // 1. Cấp phát vùng nhớ động cho struct dùng chung
  SensorContext_t *sensorContext = (SensorContext_t *)pvPortMalloc(sizeof(SensorContext_t));

  if (sensorContext != NULL) {
      sensorContext->temperature = 0.0;
      sensorContext->humidity = 0.0;
      
    
      sensorContext->dataMutex = xSemaphoreCreateMutex();
      
      //init Semaphores for Task 1
      sensorContext->semTempNormal = xSemaphoreCreateBinary();
      sensorContext->semTempWarning = xSemaphoreCreateBinary();
      sensorContext->semTempCritical = xSemaphoreCreateBinary();

      // init Semaphores for Task 2 
      sensorContext->semHumiLow = xSemaphoreCreateBinary();
      sensorContext->semHumiOptimal = xSemaphoreCreateBinary();
      sensorContext->semHumiHigh = xSemaphoreCreateBinary();

     
      xTaskCreate(led_blinky, "Task LED Blink", 2048, (void *)sensorContext, 2, NULL);
      
      
      // xTaskCreate(neo_blinky, "Task NEO Blink", 2048, (void *)sensorContext, 2, NULL);
      
      xTaskCreate(temp_humi_monitor, "Task TEMP HUMI Monitor", 2048, (void *)sensorContext, 2, NULL);
  } else {
      Serial.println("Error: Không thể cấp phát bộ nhớ cho SensorContext!");
  }

  // xTaskCreate(main_server_task, "Task Main Server" ,8192  ,NULL  ,2 , NULL);
  // xTaskCreate( tiny_ml_task, "Tiny ML Task" ,2048  ,NULL  ,2 , NULL);
  
  // Lưu ý: Sau này bật lại Task 6 thì nhớ truyền (void *)sensorContext thay vì NULL
  // xTaskCreate(coreiot_task, "CoreIOT Task" ,4096  ,(void *)sensorContext  ,2 , NULL);
  // xTaskCreate(Task_Toogle_BOOT, "Task_Toogle_BOOT", 4096, NULL, 2, NULL);
}

void loop()
{
  if (check_info_File(1))
  {
    if (!Wifi_reconnect())
    {
      Webserver_stop();
    }
    else
    {
      //CORE_IOT_reconnect();
    }
  }
  Webserver_reconnect();
}