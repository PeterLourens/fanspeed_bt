#include "main.h"

BluetoothSerial SerialBT;

void setup() {

	int data;
	Serial.begin(115200);

	SerialBT.begin("ESP32_Slave"); // Bluetooth device name
	SerialBT.setPin("1234"); // Set the PIN for pairing
	Serial.println("The device started, now you can pair it with Bluetooth!");

}

void loop() { 

	/*if (Serial.available()) {
		int data = Serial.read();

	if (data >= 0 && data <= 255) {
		SerialBT.write(data);
	}
	}*/

	if (SerialBT.available()) {
		int data = SerialBT.read();
		Serial.println(data);
	}
}

