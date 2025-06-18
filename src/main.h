#ifndef MAIN_H
#define MAIN_H

#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <WiFi.h>
#include <esp_now.h>

void onReceive(const uint8_t *mac_addr, const uint8_t *incomingData, int len);

#endif
