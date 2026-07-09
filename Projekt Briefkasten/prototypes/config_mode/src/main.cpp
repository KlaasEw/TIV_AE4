// Prototyp: Config Mode
// Konfigurationsmodus für den Briefkasten.
// Der ESP32 soll in den Konfigurationsmodus gehen, wenn beim Boot des ESP ein Tasterbetätigt wird.

#include <Arduino.h>
#include <WiFiManager.h>
#include <Preferences.h>

#define TASTER_PIN 5

char smtp_host[64]       = "";
char smtp_port[8]        = "465";
char author_email[64]    = "";
char author_pass[64]     = "";
char author_name[32]     = "Briefkasten ESP32";
char recipient_email[64] = "";
char recipient_name[32]  = "Empfaenger";

WiFiManagerParameter p_smtp_host("smtp_host", "SMTP Server", smtp_host, sizeof(smtp_host));
WiFiManagerParameter p_smtp_port("smtp_port", "SMTP Port", smtp_port, sizeof(smtp_port));
WiFiManagerParameter p_author_email("author_email", "Absender E-Mail", author_email, sizeof(author_email));
WiFiManagerParameter p_author_pass("author_pass", "SMTP Passwort", author_pass, sizeof(author_pass));
WiFiManagerParameter p_author_name("author_name", "Absender Name", author_name, sizeof(author_name));
WiFiManagerParameter p_recipient_email("recipient_email", "Empfaenger E-Mail", recipient_email, sizeof(recipient_email));
WiFiManagerParameter p_recipient_name("recipient_name", "Empfaenger Name", recipient_name, sizeof(recipient_name));

Preferences prefs;
bool shouldSaveConfig = false;

void loadMailConfig();
void saveMailConfig();
void saveConfigCallback();

void setup() {
  Serial.begin(115200);
  delay(1000);
  pinMode(TASTER_PIN, INPUT_PULLUP);

  loadMailConfig();

  delay(50);
  if (digitalRead(TASTER_PIN) == LOW) {
    WiFiManager wm;
    wm.setTitle("Postbot");
    wm.setSaveConfigCallback(saveConfigCallback);

    const char* menu[] = {"wifi", "exit"};
    wm.setMenu(menu, 2);
    wm.setShowInfoUpdate(false);

    wm.addParameter(&p_smtp_host);
    wm.addParameter(&p_smtp_port);
    wm.addParameter(&p_author_email);
    wm.addParameter(&p_author_pass);
    wm.addParameter(&p_author_name);
    wm.addParameter(&p_recipient_email);
    wm.addParameter(&p_recipient_name);

    wm.setBreakAfterConfig(true);
    wm.setConfigPortalTimeout(180); // 3 Minuten

    bool res = wm.startConfigPortal("Postbot-Config");

    if (shouldSaveConfig) {
      saveMailConfig();
      shouldSaveConfig = false;
    }

    if (res) {
      Serial.println("Konfiguration abgeschlossen");
    } else {
      Serial.println("Konfiguration abgebrochen");
    }

    ESP.restart();
  }

  
}

void loop() {
  // put your main code here, to run repeatedly:
}

void loadMailConfig() {
  prefs.begin("mail_cfg", true);  // read-only
  prefs.getString("smtp_host", "").toCharArray(smtp_host, sizeof(smtp_host));
  prefs.getString("smtp_port", "465").toCharArray(smtp_port, sizeof(smtp_port));
  prefs.getString("author_email", "").toCharArray(author_email, sizeof(author_email));
  prefs.getString("author_pass", "").toCharArray(author_pass, sizeof(author_pass));
  prefs.getString("author_name", "Briefkasten ESP32").toCharArray(author_name, sizeof(author_name));
  prefs.getString("recipient_email", "").toCharArray(recipient_email, sizeof(recipient_email));
  prefs.getString("recipient_name", "Empfaenger").toCharArray(recipient_name, sizeof(recipient_name));
  prefs.end();
}
void saveMailConfig() {
  prefs.begin("mail_cfg", false);
  prefs.putString("smtp_host", p_smtp_host.getValue());
  prefs.putString("smtp_port", p_smtp_port.getValue());
  prefs.putString("author_email", p_author_email.getValue());
  prefs.putString("author_pass", p_author_pass.getValue());
  prefs.putString("author_name", p_author_name.getValue());
  prefs.putString("recipient_email", p_recipient_email.getValue());
  prefs.putString("recipient_name", p_recipient_name.getValue());
  prefs.end();
  Serial.println("Mail-Konfiguration gespeichert.");
}
void saveConfigCallback() {
  shouldSaveConfig = true;
}

