#include "main.h"

char fanspeed[20];

void onReceive(const uint8_t *mac_addr, const uint8_t *incomingData, int len) {
    memcpy(fanspeed, incomingData, len);
    fanspeed[len] = '\0';  // Null-terminate the received string

    Serial.printf("\n\nReceived fanspeed: %s\n", fanspeed);

	//Char array is received, convert to int
	long int fanspeed_int = strtol(fanspeed, NULL, 10);
	
	Serial.printf("\nReceived fanspeed number: %s\n", fanspeed_int);

	if (fanspeed_int > 0 && fanspeed_int <= 20 ) {
        //Low speed
		digitalWrite(32,HIGH);			//Green LED on
		digitalWrite(33,LOW);
        digitalWrite(25,LOW);
        digitalWrite(26,LOW);
    }
	else if (fanspeed_int > 20 && fanspeed_int <= 50) {
        //Medium speed
		digitalWrite(32,LOW);
		digitalWrite(33,HIGH);			//Yellow LED on
        digitalWrite(25,LOW);
        digitalWrite(26,LOW);
    }
	if (fanspeed_int > 50 && fanspeed_int < 100) {
        //High speed
		digitalWrite(32,LOW);
		digitalWrite(33,LOW);
        digitalWrite(25,HIGH);			//Red LED On
        digitalWrite(26,LOW);
    }
	else {
        //Outside range
		digitalWrite(32,LOW);
		digitalWrite(33,LOW);
        digitalWrite(25,LOW);
        digitalWrite(26,HIGH);			//Blue LED on
    }
}

void setup() {
    Serial.begin(115200);

	pinMode(32,OUTPUT);
	pinMode(33,OUTPUT);
	pinMode(25,OUTPUT);
	pinMode(26,OUTPUT);

	digitalWrite(32,LOW);
	digitalWrite(33,LOW);
	digitalWrite(25,LOW);
	digitalWrite(26,LOW);

    WiFi.mode(WIFI_STA);
    esp_now_init();

    esp_now_register_recv_cb(onReceive);
}

void loop() {

}
