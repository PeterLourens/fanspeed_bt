#ifndef TASK_BLUETOOTHL_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define TASK_BLUETOOTH_H

#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include "BluetoothSerial.h"

// function declarations
void start_task_bluetooth(void);
void task_bluetooth_code(void *pvParameters);

#endif
