#include "global.h"


String WIFI_SSID;
String WIFI_PASS;
String CORE_IOT_TOKEN = "10.235.76.226";
String CORE_IOT_SERVER = "RU968t5301l2WMHb2P4N";
String CORE_IOT_PORT = "1883";

String ssid = "ESP32-YOUR NETWORK HERE!!!";
String password = "12345678";
String wifi_ssid = "M34";
String wifi_password = "quocan2004";
boolean isWifiConnected = false;
SemaphoreHandle_t xBinarySemaphoreInternet = xSemaphoreCreateBinary();

SemaphoreHandle_t xTempSemaphore = xSemaphoreCreateBinary();
