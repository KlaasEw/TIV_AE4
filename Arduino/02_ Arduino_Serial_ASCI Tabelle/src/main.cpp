#include <Arduino.h>


void setup() {
  Serial.begin(115200);

  // Ausgabe der ASCII-Zeichen 32..126 (inklusive)
  for (int i = 32; i <= 126; i++) {
    // Zeige erst den Dezimalcode, dann das Zeichen selbst.
    Serial.print(i);
    Serial.print(": ");

    if (i == 32) {
      // Leerzeichen sichtbar machen
      Serial.println("[space]");
    } else {
      Serial.println((char)i);
    }
  }
}

void loop() {

}
