// SMTP Mail Versand
// Autor: Klaas Ewald
// Date: 05.07.2025
// Beschreibung: Mit diesem Programm soll der E-Mail versand vom ESP32 durchgeführt werden.
// Diese Mails sollen später als Benachrichtung für Briefkasten öffnung sowie Akkuwarnung genetzt werden.

// Genutzte Tutorials: https://randomnerdtutorials.com/esp32-send-email-smtp-server-arduino-ide/

#include <Arduino.h>
#include <mail_sender.h>
#include "secrets.h"
#define LED_Pin 2
MailSender mail;
void setup() {
    pinMode(LED_Pin, OUTPUT);
    Serial.begin(115200);
    MailConfig cfg = {
        .wifiSsid       = WIFI_SSID,
        .wifiPassword   = WIFI_PASSWORD,
        .smtpHost       = SMTP_HOST,
        .smtpPort       = SMTP_PORT,
        .authorEmail    = AUTHOR_EMAIL,
        .authorPassword = AUTHOR_PASS,
        .authorName     = AUTHOR_NAME,
        .recipientEmail = RECIPIENT_EMAIL,
        .recipientName  = RECIPIENT_NAME,
    };
    if (mail.begin(cfg)) {
        if (mail.send(
            "Briefkasten geöffnet",
            "Hey, dein Briefkasten wurde geöffnet!\r\n"
            "Schau doch mal nach, ob du einen neuen Brief hast.\r\n"
            "\r\n"
            "Gesendet von Postbot."
        )) {
            Serial.println("E-Mail gesendet.");
            digitalWrite(LED_Pin, HIGH);
        }
    } else {
        Serial.println("Initialisierung fehlgeschlagen.");
    }
}
void loop() {}
