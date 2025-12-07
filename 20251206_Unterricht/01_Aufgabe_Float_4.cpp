//AUFGABE: Float 4
//Erstellen sie ein Programm welches eine positive Zahl mit 2 nachkommeatellen ausnimmt.
//Diese Zahke muss mindestens 0,55 sein,sonst muss die Eingabe wiederholt werden.
//Mainpulieren sie die Zahl solange bis das ergebnis 0,45 Erreicht ist.
//Anschließend geben sie die Anzahl der benötigten Schritte aus.
//Datum: 06.12.2025
//Autor: Klaas Ewald
//Version: 1.0


#include <iostream>

using namespace std;

int main()
{
    float zahl {0.0};
    int schritte {0};

    do
    {
        cout << "Bitte geben sie eine positive Zahl mit 2 Nachkommastellen ein (mindestens 0,55): ";
        cin >> zahl;
    } while (zahl < 0.55);

    while (zahl > 0.45)
    {
        zahl -= 0.01f;
        schritte++;
    }

    cout << "Anzahl der benötigten Schritte: " << schritte << endl;
    return 0;
}