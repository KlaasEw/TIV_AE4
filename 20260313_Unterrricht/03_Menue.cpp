//Switch Case
//Schreiben sie ein Programm welches über ein Menü mit dem User Interagiert
//Datum: 13.03.2026
//Autor: Klaas Ewald
//Version: 1.0

#include <iostream>
#include <limits>
#include <cctype>

using namespace std;

//Funktionsprototyp
void Satz();
int Addition();

int main()
{
    while (true)
    {
        char a;
        system("clear");
        cout << "Einen Satz ausgeben(S), Brechnung'+' durchführen(B), Programm Beenden(X)" << endl;
        cin >> a;

        // Eingabe case-insensitive behandeln
        a = static_cast<char>(toupper(static_cast<unsigned char>(a)));

        switch (a)
        {
        case 'S':
            Satz();
            break;
        case 'B':
            Addition();
            break;
        case 'X':
            cout << "Programm Beendet" << endl;
            return 0;
            break;
        
        default:
            cout << "Fehlerhafte Eingabe" << endl;
            break;
        }
        // Warten, damit die Ausgabe sichtbar bleibt, außer beim Beenden
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        cout << "\nDrücken Sie Enter, um zum Menü zurückzukehren...";
        cin.get();
    }
}

//Funktion zur Prüfung ob ein Palindrom vorliegt
void Satz(){
    cout << "Ich gebe einen Satz aus" << endl;
}

int Addition(){
    int Wert_1 = 0;
    int Wert_2 = 0;
    cout << "Gib den Ersten Wert ein: ";
    cin >> Wert_1;
    cout << "Gib den Ersten Wert ein: ";
    cin >> Wert_2;
    cout << "Das Ergebnis lautet: " << Wert_1 + Wert_2 << endl;
    return Wert_1 + Wert_2;
}