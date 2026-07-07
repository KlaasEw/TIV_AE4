// Prototype: Detect Opening
// Der Reed-Sensor wird verwendet um zu erkennen, ob die Klappe des Briefkastens geöffnet wurde.
// Wenn die Klappe geöffnet wird, wird eine E-Mail gesendet.

#include <Arduino.h>
#include "mail_sender.h"
#include "secrets.h"

#define Reed_Pin 4

unsigned long timerAlt = 0;
unsigned long time_block = 30000;
bool Reed_State = false;

void setup() {
  pinMode(Reed_Pin, INPUT_PULLUP);
  Serial.begin(115200);
  delay(1000);
  

  
}

void loop() {
  MailSender mail;
  MailConfig cfg = {
      .wifiSsid       = WIFI_SSID,
      .wifiPassword   = WIFI_PASSWORD,
      .wifiBssid      = WIFI_BSSID,
      .wifiChannel    = 0,
      .smtpHost       = SMTP_HOST,
      .smtpPort       = SMTP_PORT,
      .authorEmail    = AUTHOR_EMAIL,
      .authorPassword = AUTHOR_PASS,
      .authorName     = AUTHOR_NAME,
      .recipientEmail = RECIPIENT_EMAIL,
      .recipientName  = RECIPIENT_NAME,
    };

  if (digitalRead(Reed_Pin) && timerAlt < millis() && Reed_State == false){
    if (mail.begin(cfg)) {
      if (mail.send(
          "Briefkasten geöffnet",
          "Hey, dein Briefkasten wurde geöffnet!\r\n"
          "Schau doch mal nach, ob du einen neuen Brief hast.\r\n"
          "\r\n"
          "Gesendet von Postbot.")) {
          Serial.println("E-Mail gesendet.");
      } else {
          Serial.println("E-Mail-Versand fehlgeschlagen.");
      }
    } else {
      Serial.println("Initialisierung fehlgeschlagen.");
    }
    timerAlt = millis() + time_block;
    Reed_State = true;
  }
  if (!digitalRead(Reed_Pin)) {
    Reed_State = false;
  }
}