/*Aufgabenbeschreibung:
Ihr Auftraggeber lebt in einem Haus mit angeschlossener Zisterne.
Die Zisterne fängt Regenwasser auf und bietet ein Reservoir für 20.000 Liter Wasser.
Es gibt einen Sensor, der anzeigt, ob sich mindestens 1.000 Liter Wasser in der Zisterne befinden.
Eine Pumpe, die das Wasser aus der Zisterne in den Brauchwasserkreislauf (nicht Trinkwasser) im Haus pumpt, steht zur Verfügung.
Wenn in der Zisterne nicht mehr genügend Wasser zur Verfügung steht, wird das Wasser aus dem öffentlichen Wassernetz der Wasserversorger genutzt.
Die Umschaltung des Einspeisepunktes wird über ein Umschaltventil bewerkstelligt.
Ein Drucksensor (0-10V) im Brauchwasserkreislauf zeigt, dass Wasser im System angefordert wird.
Im Garten des Hauses ist ein 1.000 Liter Tank vorhanden, welcher mit 2 Sensoren (min. und max. Level) ausgestattet ist.
Zusätzlich bedient eine Pumpe in der Zisterne bedient diesen Tank.
Ein Schlüsselschalter schaltet die Speisung des Tanks frei, somit kann dieser Wasserkreis im Winter ausgeschaltet werden.
Ihre Aufgabe ist die Erstellung einer entsprechenden Steuerung, die das System überwacht und die Pumpen schaltet.*/


//Sensoren
const int Zisternensensor_PIN = 2;       //Digital
const int Drucksensor_PIN = A0;          //Analog 
const int Gartentank_MIN_PIN = 3;        //Digital
const int Gartentank_MAX_PIN	= 4;       //Digital
const int Schluesselschalter_PIN	= 5;   //Digital

//Senosren Status
bool Zisternensensor_Status = LOW;
bool Drucksensor_Status = LOW;
bool Gartentank_MIN_Status = LOW;
bool Gartentank_MAX_Status	= LOW;
bool Schluesselschalter_Status	= LOW;

//Ausgänge
const int Hauspumpe_PIN = 6;
const int Gartenpumpe_PIN = 7;
const int Umschaltventil_PIN = 8;

//Status Befüllung Garten Tank
bool Tank_Befuellen = false;



void setup() {
  //Sensoren
  pinMode(Zisternensensor_PIN, INPUT);
  pinMode(Drucksensor_PIN, INPUT);
  pinMode(Gartentank_MIN_PIN, INPUT);
  pinMode(Gartentank_MAX_PIN, INPUT);
  pinMode(Schluesselschalter_PIN, INPUT);

  //Ausgänge
  pinMode(Hauspumpe_PIN, OUTPUT);
  pinMode(Gartenpumpe_PIN, OUTPUT);
  pinMode(Umschaltventil_PIN, OUTPUT);

  //Serielle Schnittstelle
  Serial.begin(9600);


}

void loop() {
  //Sensoren auslesen
  Zisternensensor_Status = digitalRead(Zisternensensor_PIN);
  int Drucksensor_analog_Status = analogRead(Drucksensor_PIN);
  if(Drucksensor_analog_Status >= 500){
    Drucksensor_Status = HIGH;
  }else{
    Drucksensor_Status = LOW;
  }
  Gartentank_MIN_Status = digitalRead(Gartentank_MIN_PIN);
  Gartentank_MAX_Status = digitalRead(Gartentank_MAX_PIN);
  Schluesselschalter_Status = digitalRead(Schluesselschalter_PIN);

  //Steuerung Hauspumpe
  if(Drucksensor_Status == LOW && Zisternensensor_Status == HIGH){
    digitalWrite(Hauspumpe_PIN, HIGH);
    Serial.println("Hauspumpe Aktiv");
  }else{
    digitalWrite(Hauspumpe_PIN, LOW);
    Serial.println("Hauspumpe Inaktiv");
  }

  //Steuereung Umschaltventil
  if(Zisternensensor_Status== LOW){
    digitalWrite(Umschaltventil_PIN, HIGH);
    Serial.println("Wasserversorgung aus Wassernetz");
  }else{
    digitalWrite(Umschaltventil_PIN, LOW);
    Serial.println("Wasserversorgung aus Zisterne");
  }

  //Steuerung GartenTank
  if(Schluesselschalter_Status == HIGH){
    if(Zisternensensor_Status== HIGH){

      //Tank leer -> Befüllung starten
      if(Gartentank_MIN_Status == LOW){
           Tank_Befuellen = true;
      }

      //Tank voll -> Befüllung stoppen
      if(Gartentank_MAX_Status == HIGH){
          Tank_Befuellen = false;
      }
        
      //Pumpe entsprechend schalten
      if(Tank_Befuellen == true){
          digitalWrite(Gartenpumpe_PIN, HIGH);
          Serial.println("Gartentank wird befuellt");
      }else{
          digitalWrite(Gartenpumpe_PIN, LOW);
          Serial.println("Gartentank voll");
      }

    }else{
      Tank_Befuellen = false;
      digitalWrite(Gartenpumpe_PIN, LOW);
      Serial.println("Gartenpumpe deaktiviert, Zisternen Füllstand zu gring");
    }
  }else{
    Tank_Befuellen = false;
    digitalWrite(Gartenpumpe_PIN, LOW);
    Serial.println("Gartenpumpe über Schlüsselscahlter deaktiviert");
  }

  //Pause
  Serial.println("");
  Serial.println("");
  delay(1000);
}
