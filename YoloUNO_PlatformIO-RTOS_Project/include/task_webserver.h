
#ifndef __TASK_WEBSERVER_H__
#define __TASK_WEBSERVER_H__

#include <ESPAsyncWebServer.h>
#include "LittleFS.h"
#include <AsyncTCP.h>
#include <ArduinoJson.h>
#include <ElegantOTA.h>
#include <task_handler.h>

extern AsyncWebServer server;
extern AsyncWebSocket ws;
extern bool webserver_isrunning = false;

void Webserver_send_sensor_data(float temperature, float humidity);
void Webserver_stop();
void Webserver_reconnect();
void Webserver_sendata(String data);

#endif
