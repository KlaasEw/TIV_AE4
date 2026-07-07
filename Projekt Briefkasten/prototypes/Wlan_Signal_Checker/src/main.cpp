#include <Arduino.h>
#include <WiFi.h>
#include "secrets.h"  // WIFI_SSID, WIFI_PASSWORD
void setup() {
    Serial.begin(115200);
    delay(1000);
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Verbinde mit WLAN");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWLAN verbunden!");
    Serial.print("SSID: ");   Serial.println(WiFi.SSID());
    Serial.print("IP:   ");   Serial.println(WiFi.localIP());
    Serial.print("Kanal: ");  Serial.println(WiFi.channel());
    Serial.println("\n--- RSSI-Messung (Ctrl+C zum Beenden) ---\n");
}
void loop() {
    if (WiFi.status() == WL_CONNECTED) {
        Serial.print("Verbunden mit AP (BSSID): ");
        Serial.print(WiFi.BSSIDstr());
        int rssi = WiFi.RSSI();
        Serial.printf(" | RSSI: %d dBm", rssi);
        if (rssi >= -60)      Serial.println("  -> Gut");
        else if (rssi >= -75) Serial.println("  -> Ausreichend");
        else                  Serial.println("  -> Schwach!");
    } else {
        Serial.println("WLAN getrennt!");
    }
    delay(2000);
}