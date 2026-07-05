// SMTP Mail Versand
// Autor: Klaas Ewald
// Date: 05.07.2025
// Beschreibung: Mit diesem Programm soll der E-Mail versand vom ESP32 durchgeführt werden.
// Diese Mails sollen später als Benachrichtung für Briefkasten öffnung sowie Akkuwarnung genetzt werden.

// Genutzte Tutorials: https://randomnerdtutorials.com/esp32-send-email-smtp-server-arduino-ide/
/*
#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include "secrets.h"

#define ENABLE_SMTP
#define ENABLE_DEBUG
#include <ReadyMail.h>

#define LED_Pin 2

WiFiClientSecure ssl_client;
SMTPClient smtp(ssl_client);

void setup() {
  pinMode(LED_Pin, OUTPUT);
  Serial.begin(115200);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Verbinde mit WLAN");
  while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
  }
  Serial.println();
  Serial.print("WLAN verbunden, IP: ");
  Serial.println(WiFi.localIP());

  ssl_client.setInsecure();

  auto statusCallback = [](SMTPStatus status) {
    Serial.println(status.text);
  };

  smtp.connect(SMTP_HOST, SMTP_PORT, statusCallback);

  if (smtp.isConnected()) {
    smtp.authenticate(AUTHOR_EMAIL, AUTHOR_PASS, readymail_auth_password);

    SMTPMessage msg;

    msg.headers.add(rfc822_from, String(AUTHOR_NAME) + " <" + AUTHOR_EMAIL + ">");
    msg.headers.add(rfc822_to, String(RECIPIENT_NAME) + " <" + RECIPIENT_EMAIL + ">");
    msg.headers.add(rfc822_subject, "Briefkasten geöffnet");



    String bodyText = "Hey, dein Briefkasten wurde geöffnet!\r\n";
    bodyText += "Schau doch mal nach, ob du einen neuen Brief hast.\r\n";
    bodyText += "\r\n";
    bodyText += "Gesendet von Postbot.";
    msg.text.body(bodyText);

    smtp.send(msg);
    Serial.println("E-Mail gesendet.");
    digitalWrite(LED_Pin, HIGH);
  } else {
    Serial.println("SMTP-Verbindung fehlgeschlagen.");
  }
}

void loop() {
}

*/

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
