//Schreiben ein Programm, das Wenn ein Butten an Pion 3 gedrückt wird eine LED blinken lässt, 
//ist der Button nicht gedrückt soll die LED deaktiviert sein.
//Wird der Button gedrückt soll dies im Sereillen Monitor ausgegeben werden.
//Autor: Klaas Ewald
//Datum: 25.04.2026
//Version: 1.0

#include <Arduino.h>
const int BUTTON_PIN = 2; // Taster zwischen D2 und GND

void setup() {
  // LED und Button Pins konfigurieren, LED zu Begin deaktivieren
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(115200);

}

void loop() {
  //Button auslesen und LED Blinkenlassen, wenn Taster gedrückt wurde
  //
  if (digitalRead(BUTTON_PIN))
  {
    Serial.println("Taster gedrückt");
    digitalWrite(LED_BUILTIN, HIGH);
    delay(250);
    digitalWrite(LED_BUILTIN, LOW);
    delay(250);
  }
  
}
