#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  float Messwert = map(analogRead(A0), 0, 1023, 0, 5000) / 1000.0;
  Serial.println(Messwert);
  delay(100);
}