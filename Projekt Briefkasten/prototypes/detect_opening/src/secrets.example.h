// Vorlage für lokale Zugangsdaten
// 1. Diese Datei kopieren:  cp secrets.example.h secrets.h
// 2. secrets.h mit echten Werten ausfüllen
// 3. secrets.h wird von Git ignoriert und landet nicht auf GitHub

#pragma once

#include <stdint.h>

// WLAN (Repeater-SSID empfohlen, nicht Router-SSID)
#define WIFI_SSID "DEIN_WLAN_NAME"
#define WIFI_PASSWORD "DEIN_WLAN_PASSWORT"

// Repeater-BSSID (MAC-Adresse des Access Points, aus Serial Monitor)
static const uint8_t WIFI_BSSID[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

// Hetzner SMTP
#define SMTP_HOST "mail.your-server.de"
#define SMTP_PORT 465

#define AUTHOR_EMAIL "briefkasten@deine-domain.de"
#define AUTHOR_PASS "DEIN_MAILBOX_PASSWORT"
#define AUTHOR_NAME "Briefkasten ESP32"

#define RECIPIENT_EMAIL "empfaenger@example.com"
#define RECIPIENT_NAME "Empfaenger"
