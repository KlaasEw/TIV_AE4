Aufgabenlöungen der Probeklausur

# 1. Aufgabe
32Bit Aufteilung 1/8/23

1 steht für Vorzeichen
8 steht für Exponent
23 steht für die Matisse

Bei einer Float zahl bleiben nur 23 Bit um die Zahl darzustellen. Der Wert 1,23 wird im Programm gespeichert als 1,229999...
Würden wird diese Zahl jetzt mit einer sehr großen Zahl mulitpizieren z.B. 1000, würden wir als Ergebnis 1229,99... erhalten und nicht 1230.
Duch die Begrenzete Anzahl an Nachkomma stellen ist die Zahl nicht besonders genau.

# 2. Aufgabe
**While** ist Kopf gestuert, und wird wiederholt solage die Bedingung wahr ist. Die wird nur dorchlaufen wenn die Bedingung beim ersten la whr ist. Die Schleife kann als Endlosschleife dargestellt werden. Die Schleife wird angewendet wenn der Abbruchzeitpunkt unbekannt ist. 

while(true)
{
    cout << "In der Schleife" << endl;
}

**IF** ist keine Schleife, es handelt sich bei If um eine Kontrollsturktur. Sie dient der Überprüfung von Bedingungen, auf Variable/Werte. Wenn die Bedingung war ist wird der Inhalt der Strucktur ausgeführt, wenn nicht wird sie übersprungen. Die If Abfrage kann um else if oder else erweitert werden um weitere Bedingungen zu prüfen. Es wird immer nur eins ausgeführt

if(a==b)
{
    cout << "a ist gelich b" << endl;
}
else
{
    cout << "a ist ungelich b" << endl;
}

# 3. Aufgabe
Aufbau einer IDE vom Schrieben zum ausführbaren Programm.
* Editor mit Highlighter ==> Schreibprogramm
* Parser  ==> Sucht nach syntaktischen Fehlern
* Optimizern ==> Optimiert den geschriebenen Code
* Linker  ==> Ergänzt benötoigte Befehle aus den Bibliotheken
* Compiler ==> Übersetzt lessbaren Code in ausführbaren Maschinencode
* Debuger ==> Fehlersucher zur Programmlaufzeit

# 4. Aufgabe
A. Laufzeitbedingung der For-Schleife fehlerhaft
B. kreisr ist nicht definiert
Pfele bei cin falsch herum
Main nicht abgeschlossen
C. Die Zahl ist zu groß für die gegbene Zahl

# 5. Aufgabe
A.
1
0
0
0

B.
200
175
150
125
100
75
50
25

# 6. Aufgabe
```
#include <iostream>

using namespace std;

int main()
{
    int a {0};
    cin >> a;
    if (a%2==0)
    {
        cout << "a ist gerade" << endl;
    }
    else
    {
        cout << "a ist ungerade" << endl;
    }
}
```

# 7. Aufgabe
[Strutkurgramm anzeigen](/20260214_Unterrricht/03_Probelausur_Aufgabe_7.pdf)

# 8. Aufgabe
[Strutkurgramm anzeigen](/20260214_Unterrricht/03_Probelausur_Aufgabe_8.pdf)
```
#include <iostream>
using namespace std;

main()
{
    int zahl_vor {0};
    int zahl_nach {1};
    int zahl_aktuell {0};

    int eingabe;

    cin >> eingabe;
    
    if (eingabe == 0)
    {
        cout << zahl_vor << endl;
        return(0);
    }
    cout << zahl_vor << entl;
    cout << zahl_nach << entl;

    while(zahl_aktuell < eingabe)
    {
        zahl_aktuell = zahl_vor + zahl_nach;
        zahl_vor = Zahl_nach;
        zahl_nach = zahl_aktuell;
        cout << zahl_aktuell << endl;
    }

    return(0);
}
```