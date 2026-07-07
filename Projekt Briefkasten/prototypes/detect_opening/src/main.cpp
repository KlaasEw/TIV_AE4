// Prototype: Detect Opening
// Der Reed-Sensor wird verwendet um zu erkennen, ob die Klappe des Briefkastens geöffnet wurde.
// Wenn die Klappe geöffnet wird, wird eine E-Mail gesendet.

#include <Arduino.h>
#include "mail_sender.h"
#include "secrets.h"

#define Reed_Pin 4

unsigned long timerAlt = 0;
unsigned long time_block = 30000;
bool lastReed = true;

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

void setup() {
  pinMode(Reed_Pin, INPUT_PULLUP);
  Serial.begin(115200);
  delay(1000);

  lastReed = digitalRead(Reed_Pin);
  
  if (!mail.begin(cfg)) {
    Serial.println("Initialisierung fehlgeschlagen.");
  }

  
}

void loop() {
  bool reed = digitalRead(Reed_Pin);
  if (reed && !lastReed && timerAlt < millis()){
    Serial.println("Briefkasten Öffnung erkannt");
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
    timerAlt = millis() + time_block;
  }
  lastReed = reed;
}