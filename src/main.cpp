#include "main.h"

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

	start_task_bluetooth();
	
}

void loop() { 

	
}

