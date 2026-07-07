#pragma once

#include <WiFiClientSecure.h>
#define ENABLE_SMTP
#include <ReadyMail.h>

#include <Arduino.h>

struct MailConfig {
    const char* wifiSsid;
    const char* wifiPassword;
    const uint8_t* wifiBssid;  // optional: Repeater-MAC fuer schnellere Verbindung
    uint8_t     wifiChannel;   // 0 = aus NVS oder Scan ermitteln
    const char* smtpHost;
    uint16_t    smtpPort;
    const char* authorEmail;
    const char* authorPassword;
    const char* authorName;
    const char* recipientEmail;
    const char* recipientName;
};

class MailSender {
    public:
        bool begin(const MailConfig& config);
        bool send(const char* subject, const char* body);
        MailSender() : _smtp(_sslClient) {}
    private:
        WiFiClientSecure _sslClient;
        SMTPClient _smtp;
        MailConfig _config{};
        bool _ready = false;
};