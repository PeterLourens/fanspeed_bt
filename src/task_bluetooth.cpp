#include "task_bluetooth.h"

BluetoothSerial SerialBT;
TaskHandle_t task_bluetooth;

void start_task_bluetooth(void) {

    xTaskCreate(task_bluetooth_code, "task_valvectrl", 10000, NULL, 8, &task_bluetooth);

}

void task_bluetooth_code(void * pvParameters) {
    
    SerialBT.begin("ESP32_Slave"); // Bluetooth device name
    SerialBT.setPin("1234"); // Set the PIN for pairing
    
    char RxByte;

    for (;;) {
        String RxBuffer = "";
        
        if (SerialBT.available()) {
            
            while (SerialBT.available() > 0) {
                RxByte = SerialBT.read();
                RxBuffer += String(RxByte);
            }

            Serial.print("\n");
            Serial.print(RxBuffer);

            if (RxBuffer == "low") {
                digitalWrite(32,HIGH);
                digitalWrite(33,LOW);
                digitalWrite(25,LOW);
                digitalWrite(26,LOW);
            }
            else if (RxBuffer == "medium") {
                digitalWrite(32,LOW);
                digitalWrite(33,HIGH);
                digitalWrite(25,LOW);
                digitalWrite(26,LOW);
            }
            else if (RxBuffer == "high") {
                digitalWrite(32,LOW);
                digitalWrite(33,LOW);
                digitalWrite(25,HIGH);
                digitalWrite(26,LOW);
            }
            else {
                digitalWrite(32,LOW);
                digitalWrite(33,LOW);
                digitalWrite(25,LOW);
                digitalWrite(26,HIGH);
            }

            vTaskDelay(5000);
            
            digitalWrite(32,LOW);
            digitalWrite(33,LOW);
            digitalWrite(25,LOW);
            digitalWrite(26,LOW);
        }
    }
    vTaskDelay(10);
}

