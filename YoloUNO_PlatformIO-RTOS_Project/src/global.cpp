#include "global.h"


String WIFI_SSID = "Galaxy A04sAB78";
String WIFI_PASS = "wifi_trung";
String CORE_IOT_TOKEN = "RU968t5301l2WMHb2P4N";
String CORE_IOT_SERVER = "app.coreiot.io";
String CORE_IOT_PORT = "1883";

String ssid = "ESP32-YOUR NETWORK HERE!!!";
String password = "12345678";
boolean isWifiConnected = false;
SemaphoreHandle_t xBinarySemaphoreInternet = xSemaphoreCreateBinary();

SemaphoreHandle_t xTempSemaphore = xSemaphoreCreateBinary();
