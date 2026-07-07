#include <Arduino.h>

#define Reed_Pin 2

int timerAlt = 0;
int time_block = 30000;

void setup() {
  pinMode(Reed_Pin, INPUT);
}

void loop() {
  if (digitalRead(Reed_Pin) && timerAlt < millis())
  {
    Serial.println("Briefkasten geöffet");
    timerAlt = millis() + time_block;
  }
  
}