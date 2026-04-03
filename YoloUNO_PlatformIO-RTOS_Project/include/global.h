#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

typedef enum {
    STATE_NOMAL = 0,
    STATE_WARNING,
    STATE_CRITIAL,
    STATE_ERROR
} SensorState_t;

typedef struct {
    float temperature;
    float humidity;
    
    
    SensorState_t tempState; 
    
    SemaphoreHandle_t dataMutex;     // Mutex for protecting data 
    SemaphoreHandle_t semTempUpdate; // Semaphore for Task 1
    
    // semaphore for Task 2 
    uint8_t humiState;
    SemaphoreHandle_t semHumiUpdate; 
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