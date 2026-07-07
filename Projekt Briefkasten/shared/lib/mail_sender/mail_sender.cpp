#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <Preferences.h>
#include "mail_sender.h"

#define ENABLE_SMTP
#define ENABLE_DEBUG
#include <ReadyMail.h>

static volatile bool staStarted = false;

static void onWifiEvent(WiFiEvent_t event, WiFiEventInfo_t info) {
    (void)info;
    if (event == ARDUINO_EVENT_WIFI_STA_START) {
        staStarted = true;
    }
}

static int scanChannelForBssid(const uint8_t* bssid) {
    Serial.println("Suche WLAN-Kanal...");
    int n = WiFi.scanNetworks();
    for (int i = 0; i < n; i++) {
        if (memcmp(WiFi.BSSID(i), bssid, 6) == 0) {
            int channel = WiFi.channel(i);
            Serial.printf("Kanal gefunden: %d\n", channel);
            WiFi.scanDelete();
            return channel;
        }
    }
    WiFi.scanDelete();
    return 0;
}

static int loadCachedChannel() {
    Preferences prefs;
    prefs.begin("mail_sender", true);
    int channel = prefs.getUChar("wifi_ch", 0);
    prefs.end();
    return channel;
}

static void saveCachedChannel(int channel) {
    if (channel <= 0) {
        return;
    }
    Preferences prefs;
    prefs.begin("mail_sender", false);
    prefs.putUChar("wifi_ch", channel);
    prefs.end();
}

static int resolveWifiChannel(const MailConfig& config) {
    if (config.wifiChannel > 0) {
        return config.wifiChannel;
    }

    int channel = loadCachedChannel();
    if (channel > 0) {
        Serial.printf("Gespeicherter Kanal: %d\n", channel);
        return channel;
    }

    if (config.wifiBssid) {
        return scanChannelForBssid(config.wifiBssid);
    }

    return 0;
}

static bool initWifiRadio() {
    staStarted = false;
    WiFi.onEvent(onWifiEvent);
    WiFi.persistent(false);
    WiFi.setSleep(false);
    WiFi.mode(WIFI_STA);

    unsigned long start = millis();
    while (!staStarted && millis() - start < 5000) {
        delay(10);
    }

    if (!staStarted) {
        Serial.println("WLAN-Stack nicht bereit.");
        return false;
    }

    delay(100);
    return true;
}

static void startWifiConnection(const MailConfig& config, int channel) {
    if (config.wifiBssid && channel > 0) {
        Serial.printf("Verbinde mit Kanal %d\n", channel);
        WiFi.begin(config.wifiSsid, config.wifiPassword, channel, config.wifiBssid);
    } else if (config.wifiBssid) {
        WiFi.begin(config.wifiSsid, config.wifiPassword, 0, config.wifiBssid);
    } else {
        WiFi.begin(config.wifiSsid, config.wifiPassword);
    }
}

static bool logWifiConnected() {
    if (WiFi.status() != WL_CONNECTED) {
        return false;
    }
    Serial.println();
    Serial.print("WLAN verbunden, IP: ");
    Serial.println(WiFi.localIP());
    Serial.print("AP (BSSID): ");
    Serial.println(WiFi.BSSIDstr());
    Serial.print("Kanal: ");
    Serial.println(WiFi.channel());
    Serial.print("RSSI: ");
    Serial.print(WiFi.RSSI());
    Serial.println(" dBm");
    saveCachedChannel(WiFi.channel());
    return true;
}

// Repeater halten nach abruptem Power-Off oft noch die alte ESP-Session.
// Kurzer Verbindungsversuch + Pause gibt dem Repeater Zeit, sie freizugeben.
static bool prepareRepeaterSession(const MailConfig& config, int channel) {
    Serial.println("WLAN vorbereiten...");
    startWifiConnection(config, channel);

    unsigned long start = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - start < 2500) {
        delay(100);
    }

    if (WiFi.status() == WL_CONNECTED) {
        return true;
    }

    Serial.println("Repeater-Session freigeben...");
    WiFi.disconnect(false);
    delay(2000);
    return false;
}

static bool waitForWifiConnection(int timeoutSekunden) {
    unsigned long start = millis();
    while (WiFi.status() != WL_CONNECTED) {
        delay(250);
        Serial.print(".");
        if (millis() - start > timeoutSekunden * 1000UL) {
            Serial.printf(" Timeout (Status %d)\n", WiFi.status());
            return false;
        }
    }
    return true;
}

static bool connectWifi(const MailConfig& config) {
    if (!initWifiRadio()) {
        return false;
    }

    int channel = resolveWifiChannel(config);

    if (config.wifiBssid && channel > 0) {
        if (prepareRepeaterSession(config, channel)) {
            return logWifiConnected();
        }
    }

    const int maxVersuche = 2;
    const int timeoutSekunden = 10;

    for (int versuch = 1; versuch <= maxVersuche; versuch++) {
        if (versuch > 1) {
            WiFi.disconnect(false);
            delay(500);
        }

        Serial.printf("WLAN-Verbindung (Versuch %d/%d)\n", versuch, maxVersuche);
        startWifiConnection(config, channel);

        if (waitForWifiConnection(timeoutSekunden)) {
            return logWifiConnected();
        }

        if (channel == 0 && config.wifiBssid) {
            channel = scanChannelForBssid(config.wifiBssid);
        }
    }

    Serial.println("WLAN-Verbindung fehlgeschlagen.");
    return false;
}

bool MailSender::begin(const MailConfig& config){
    _config = config;

    if (!connectWifi(_config)) {
        _ready = false;
        return false;
    }

    _sslClient.setInsecure();

    auto statusCallback = [](SMTPStatus status) {
        Serial.println(status.text);
    };

    _smtp.connect(_config.smtpHost, _config.smtpPort, statusCallback);

    if (!_smtp.isConnected()) {
        Serial.println("SMTP-Verbindung fehlgeschlagen.");
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
