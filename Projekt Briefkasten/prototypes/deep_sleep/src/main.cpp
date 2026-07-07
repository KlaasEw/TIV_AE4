// Test DeepSleep Funktion
// Der ESP32 soll in den DeepSleep Modus zursetzt werden um die Leistungsaufnahme zu reduzieren. Der ESP soll durch den Druck eines Tasters aus dem DeepSleep Modus aufgeweckt werden und nach Ablauf des Programmes wieder in den DeepSleep wechseln.

// Benutstes Tutorial: https://www.instructables.com/ESP32-Deep-Sleep-Tutorial/
// Benutstes Tutorial: https://randomnerdtutorials.com/esp32-external-wake-up-deep-sleep/


#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  Serial.println("Hey, ich gehe jetzt schlafen");
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_5, HIGH);
  esp_deep_sleep_start();
  Serial.println("Das wird neimals ausgegeben");
}

void loop() {
}
