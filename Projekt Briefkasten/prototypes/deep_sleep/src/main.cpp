// Test DeepSleep Funktion
// Der ESP32 soll in den DeepSleep Modus zursetzt werden um die Leistungsaufnahme zu reduzieren.
// Der ESP soll durch den Druck eines Tasters aus dem DeepSleep Modus aufgeweckt werden und nach Ablauf des Programmes wieder in den DeepSleep wechseln.
// ZUsätzlich soll der ESP einmal pro tag aufwachen um einen Sensor auszulesen.

// Benutstes Tutorial: https://www.instructables.com/ESP32-Deep-Sleep-Tutorial/
// Benutstes Tutorial: https://randomnerdtutorials.com/esp32-external-wake-up-deep-sleep/


#include <Arduino.h>
#include "driver/rtc_io.h" // Wird benötigt um die Pullup/Pulldown Widerstände zu setzen

void readSensor();
void sendMail();
void goToSleep();


void setup() {
  Serial.begin(115200);
  delay(1000);

  esp_sleep_wakeup_cause_t reason = esp_sleep_get_wakeup_cause();

  if (reason == ESP_SLEEP_WAKEUP_EXT0) {
    sendMail();
  } else if (reason == ESP_SLEEP_WAKEUP_TIMER) {
    readSensor();
  } else {
    Serial.println("Erster Start oder anderer Grund");
  }
  goToSleep();

  
}

void loop() {
}

void readSensor() {
  Serial.println("Akkustand prüfen");
}

void sendMail() {
  Serial.println("E-Mail senden");
}

void goToSleep() {
  Serial.println("Hey, ich gehe jetzt schlafen");
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_4, HIGH);               // Aufgewacht durch Taster/Sensor
  esp_sleep_enable_timer_wakeup(24ULL * 3600ULL * 1000000ULL);  // Aufgewacht durch Timer 
  //esp_sleep_enable_timer_wakeup(60ULL * 1000000ULL);          //Aufgewacht durch Timer jede Minute Zum Testen
  rtc_gpio_pullup_dis(GPIO_NUM_4);
  rtc_gpio_pulldown_en(GPIO_NUM_4);
  esp_deep_sleep_start();
  Serial.println("Das wird niemals ausgegeben");
}