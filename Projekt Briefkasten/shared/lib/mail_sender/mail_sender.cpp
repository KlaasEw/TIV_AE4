#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include "mail_sender.h"

#define ENABLE_SMTP
#define ENABLE_DEBUG
#include <ReadyMail.h>



bool MailSender::begin(const MailConfig& config){
    _config = config;

    WiFi.begin(_config.wifiSsid, _config.wifiPassword);
    Serial.print("Verbinde mit WLAN");
    while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    }
    Serial.println();
    Serial.print("WLAN verbunden, IP: ");
    Serial.println(WiFi.localIP());

    _sslClient.setInsecure();

    auto statusCallback = [](SMTPStatus status) {
    Serial.println(status.text);
    };

    _smtp.connect(_config.smtpHost, _config.smtpPort, statusCallback);

    if (!_smtp.isConnected()) {
        _ready = false;
        return false;
    }
    _smtp.authenticate(_config.authorEmail, _config.authorPassword, readymail_auth_password);
    _ready = true;
    return true;
}

bool MailSender::send(const char* subject, const char* body){
    if (!_ready) {
        return false;
    }
    SMTPMessage msg;

    msg.headers.add(rfc822_from, String(_config.authorName) + " <" + _config.authorEmail + ">");
    msg.headers.add(rfc822_to, String(_config.recipientName) + " <" + _config.recipientEmail + ">");
    msg.headers.add(rfc822_subject, subject);

    msg.text.body(body);

    _smtp.send(msg);
    return true;
}

