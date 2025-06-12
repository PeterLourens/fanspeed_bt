#include "main.h"

BluetoothSerial SerialBT;

void setup() {

	pinMode(32,OUTPUT);
	pinMode(33,OUTPUT);
	pinMode(25,OUTPUT);
	pinMode(26,OUTPUT);

	Serial.begin(115200);

	digitalWrite(32,LOW);
	digitalWrite(33,LOW);
	digitalWrite(25,LOW);
	digitalWrite(26,LOW);

	SerialBT.begin("ESP32_Slave"); // Bluetooth device name
	SerialBT.setPin("1234"); // Set the PIN for pairing
}

void loop() { 

	String RxBuffer = "";
	char RxByte;

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

