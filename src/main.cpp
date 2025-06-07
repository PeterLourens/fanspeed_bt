#include "main.h"

//Variables

void setup() {

  Serial.begin(115200);

  // Begin LittleFS
  if (!LittleFS.begin())
  {
    Serial.println("\nAn Error has occurred while mounting LittleFS");
    return;
  }

}

void loop() { }

