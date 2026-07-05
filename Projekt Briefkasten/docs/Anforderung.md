# Projekt: Briefkastenüberwachung

Projekt zur Umsetzung innerhalb des TIV-Unterrichts

> Dieses Dokument beschreibt den aktuellen Stand der Projektanforderungen.

---

## 1. Projektziel

Ziel des Projektes ist eine Überwachung für einen Briefkasten zu realisieren. Wird der Briefkasten geöffnet, soll eine E-Mail an den Eigentümer versendet werden.

---

## 2. Funktionsübersicht

| Ereignis | Reaktion des Systems |
|---|---|
| Briefkasten wird geöffnet | E-Mail an konfigurierte Empfängeradresse |
| Akkuspannung unter Schwellwert | E-Mail mit Warnung (mind. 1× täglich geprüft) |
| Taster beim Boot gedrückt | Konfigurationsmodus (eigenes WLAN + Webserver) |
| Normaler Betrieb | Deep Sleep, Aufwachen bei Öffnung oder Timer |

---

## 3. Mikrocontroller

Als Mikrocontroller soll ein **ESP32-WROOM-32** eingesetzt werden. Begründung:

- integriertes WLAN
- Deep-Sleep-Funktionen für energiesparenden Betrieb
- Modul ist CE-vorzertifiziert

---

## 4. Sensorik

### 4.1 Reedkontakt (Betriebsbetrieb)

Zum Detektieren der Briefkastenöffnung soll ein Reedkontakt eingesetzt werden. Dieser wird an der Briefkastenklappe montiert und erkennt das Öffnen und Schließen der Klappe.

Der Reedkontakt ist **nicht direkt auf der Platine** montiert. Auf der Platine wird ein Schraubklemmen-Terminal vorgesehen, an dem der Reedkontakt angeschlossen werden kann. Dadurch lässt sich der Abstand zum Reedkontakt und zu den Gehäusemagneten besser einhalten.

### 4.2 Entprellung

Wird eine Öffnung des Briefkastens erkannt, wird eine E-Mail ausgelöst. Eine erneute Auslösung ist für die **nächsten 30 Sekunden gesperrt**, um Mehrfachmeldungen durch mechanisches Prellen oder schnelles mehrfaches Öffnen zu vermeiden.

### 4.3 Ausgeschlossene Sensoren

Folgende Sensorarten wurden diskutiert und bewusst ausgeschlossen:

**Ultraschall / Time-of-Flight / Lichtschranke**

Diese Sensoren benötigen für den Betrieb eine dauerhafte Stromversorgung und sind daher nicht mit einer akkubetriebenen Schaltung vereinbar. Ansonsten wären sie gut geeignet, um die Öffnung des Briefkastens zu erkennen.

**LDR / Fotodiode**

Ein lichtabhängiger Widerstand oder eine Fotodiode wären grundsätzlich geeignet, um eine Öffnung zu erkennen. Die Kalibrierung ist jedoch aufwändiger, da der Messwert vom vorhandenen Umgebungslicht abhängt (Tageslicht, Dämmerung, Flurbeleuchtung).

Zum Testen dieser Sensorart soll auf der Platine dennoch ein LDR vorgesehen werden, der über eine Lötbrücke auftrennbar ist.

---

## 5. Stromversorgung

### 5.1 Akku und Laden

Die Schaltung wird über einen **1S-LiPo-Akku** versorgt. Auf der Platine ist eine **USB-C-Schnittstelle** integriert, über die der Akku geladen werden kann.

Der LiPo-Akku wird durch folgende Schutzfunktionen abgesichert:

- Kurzschlussschutz
- Unterspannungsschutz

### 5.2 Spannungsversorgung des ESP32

Die Versorgung des ESP32 erfolgt über einen **LDO** (Low-Dropout-Regler). Ein Schaltregler wäre für zukünftige Iterationen hinsichtlich des Wirkungsgrads sinnvoll, wird aufgrund der höheren Schaltungskomplexität in diesem Projekt jedoch ausgeschlossen.

### 5.3 Akkuspannungsmessung

Die Akkuspannung wird über einen **Spannungsteiler** erfasst und an den **ADC** des ESP32 angeschlossen. Wird ein konfigurierter Schwellwert unterschritten, versendet der ESP32 eine Warn-E-Mail.

Zur regelmäßigen Überwachung soll der ESP32 **mindestens einmal pro Tag** aufwachen und die Akkuspannung prüfen — unabhängig davon, ob der Briefkasten geöffnet wurde.

### 5.4 Energieoptimierung

Aufgrund der Akkuversorgung soll die Platine möglichst energiesparend ausgelegt werden:

- Der Mikrocontroller befindet sich den Großteil der Zeit im **Deep Sleep**.
- Alle Test-LEDs sind über Lötbrücken auftrennbar, um sie im späteren Betrieb auszuschließen.

**Akkulaufzeit:** Messungen der Stromaufnahme werden durchgeführt, sobald die Schaltung existiert. Anschließend erfolgt eine Abschätzung der erreichbaren Laufzeit.

---

## 6. Deep Sleep und Aufwecken

Der ESP32 verbringt im Normalbetrieb den Großteil der Zeit im Deep Sleep. Aufgeweckt wird er durch:

1. **GPIO-Interrupt (Reedkontakt):** Öffnen der Briefkastenklappe löst ein Aufwachen aus. Der Reedkontakt ist an einem GPIO-Pin angeschlossen, der als Wake-up-Source konfiguriert wird. Ein definierter Pull-up oder Pull-down sorgt für einen stabilen Ruhezustand im Deep Sleep.
2. **Timer-Interrupt:** Mindestens einmal pro Tag weckt ein interner Timer den ESP32 auf, um die Akkuspannung zu prüfen.

Nach dem Aufwachen verbindet sich der ESP32 mit dem konfigurierten WLAN, führt die erforderliche Aktion aus (E-Mail versenden oder Spannung prüfen) und kehrt anschließend wieder in den Deep Sleep zurück.

---

## 7. Netzwerkverbindung

Im Normalbetrieb verbindet sich der ESP32 über **WLAN** mit dem vorhandenen Heimnetzwerk. Die Zugangsdaten (SSID und Passwort) werden im Konfigurationsmodus hinterlegt (siehe Abschnitt 9).

Die WLAN-Empfangsstärke innerhalb des Metallbriefkastens muss im Rahmen des Projekts geprüft werden.

---

## 8. E-Mail-Benachrichtigung

Benachrichtigungen werden ausschließlich per **E-Mail** realisiert. Ein Zeitstempel in der Mail ist nicht erforderlich — der Eingangszeitpunkt der E-Mail beim Empfänger genügt als Referenz.

Folgende Ereignisse lösen eine E-Mail aus:

- erkannte Öffnung des Briefkastens
- unterschrittener Akku-Schwellwert

Für den Versand werden folgende Parameter benötigt, die im Konfigurationsmodus hinterlegt werden:

- Empfängeradresse
- SMTP-Server, Port
- SMTP-Benutzername und Passwort (bzw. App-Passwort)

---

## 9. Konfigurationsmodus

Bei **jedem Boot** wird geprüft, ob der Konfigurationstaster gedrückt ist.

| Zustand beim Boot | Verhalten |
|---|---|
| Taster **gedrückt** | Konfigurationsmodus wird aktiviert |
| Taster **nicht gedrückt** | Normalbetrieb (Deep Sleep) |

Im Konfigurationsmodus:

1. Der ESP32 baut ein **eigenes WLAN** (Access Point) auf.
2. Ein **Webserver** wird bereitgestellt.
3. Über die Webseite können folgende Einstellungen vorgenommen und dauerhaft gespeichert werden:
   - WLAN-Konfiguration (SSID und Passwort des Heimnetzwerks)
   - Empfängeradresse
   - SMTP-Konfiguration (Server, Port, Zugangsdaten)

Die gespeicherten Werte bleiben erhalten, bis sie im Konfigurationsmodus erneut überschrieben werden.

> **Hinweis:** Mögliche Angriffsvektoren des unverschlüsselten Konfigurations-Webservers sind bekannt. Eine Sicherheitsbetrachtung ist nicht Bestandteil dieses Projektumfangs.

---

## 10. Hardware-Umsetzung

### 10.1 Platine

Die Schaltung wird auf einer eigenen Platine umgesetzt.

### 10.2 Montage am Briefkasten

Die Platine wird über Magnete an der Metall-Außenwand des Briefkastens befestigt. Es muss sichergestellt werden, dass die Gehäusemagnete den Reedkontakt nicht beeinflussen.

Zur Verbindung der Platine mit den Magneten ist ein **Kunststoffbauelement** zu designen und über additive Fertigungsverfahren (3D-Druck) herzustellen.

### 10.3 Umgebungsbedingungen

Der Briefkasten befindet sich in einem Innenraum. Wetterschutz ist daher nicht von größerer Bedeutung.

---

## 11. Bewusst ausgeschlossene Erweiterungen

Folgende Punkte wurden bewusst aus dem Projektumfang ausgeschlossen und können in zukünftigen Iterationen umgesetzt werden:

- Schaltregler statt LDO (höherer Wirkungsgrad, höhere Komplexität)

- Zeitstempel in ausgehenden E-Mails
- Sicherheitsmaßnahmen für den Konfigurations-Webserver

