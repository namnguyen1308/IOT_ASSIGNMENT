#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

typedef struct {
    float temperature;
    float humidity;
    SemaphoreHandle_t dataMutex;     // Mutex for data protecting
    
    // Semaphores for Task 1 
    SemaphoreHandle_t semTempNormal;
    SemaphoreHandle_t semTempWarning;
    SemaphoreHandle_t semTempCritical;

    // Semaphores for Task 2 
    SemaphoreHandle_t semHumiLow;
    SemaphoreHandle_t semHumiOptimal;
    SemaphoreHandle_t semHumiHigh;
} SensorContext_t;

extern String WIFI_SSID;
extern String WIFI_PASS;
extern String CORE_IOT_TOKEN;
extern String CORE_IOT_SERVER;
extern String CORE_IOT_PORT;

extern boolean isWifiConnected;
extern SemaphoreHandle_t xBinarySemaphoreInternet;

extern SemaphoreHandle_t xTempSemaphore;
#endif