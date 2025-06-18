#include "main.h"

char fanspeed[20];

void onReceive(const uint8_t *mac_addr, const uint8_t *incomingData, int len) {
    memcpy(fanspeed, incomingData, len);
    fanspeed[len] = '\0';  // Null-terminate the received string

    Serial.printf("Received: Fanspeed: %s\n", fanspeed);

	if (fanspeed == "low") {
        digitalWrite(32,HIGH);
		digitalWrite(33,LOW);
        digitalWrite(25,LOW);
        digitalWrite(26,LOW);
    }
	else if (fanspeed == "medium") {
        digitalWrite(32,LOW);
		digitalWrite(33,HIGH);
        digitalWrite(25,LOW);
        digitalWrite(26,LOW);
    }
	if (fanspeed == "high") {
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
    //vTaskDelay(pdMS_TO_TICKS(5000));
}
