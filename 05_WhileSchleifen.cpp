//Aufgaben: in dem Programm sollen zahelen eingegebne werden.
// die erste Zhal soll zwischen 0 und 10 liegen
// die zweite Zahl soll muss größer als 20 sein
// die dritte Zahl muss durch 11 teilbar sein
//Datum: 08.11.2023
//Autor: Klaas Ewald
//Version: 1.0

#include <iostream>

using namespace std;

int main()
{
    int zahl1 {0};
    int zahl2 {0};
    int zahl3 {0};

    //Zahl 1
    cout << "Bitte geben sie eine Zahl ein (zwischen 0 und 10): ";
    cin >> zahl1;
    while ( zahl1 < 0 || zahl1 > 10 )
    {
        cout << "Falsche Eingabe. Bitte geben sie eine Zahl ein (zwischen 0 und 10): ";
        cin >> zahl1;
    }
    cout << "Danke für die Eingabe der richtige Zahl: " << zahl1 << endl;


    //Zahl 2
    cout << endl << "Bitte geben sie eine Zahl ein (größer als 20): ";
    cin >> zahl2;
    while ( zahl2 <= 20 )
    {
        cout << "Falsche Eingabe. Bitte geben sie eine Zahl die größer als 20 ist: ";
        cin >> zahl2;
    }
    cout << "Danke für die Eingabe der richtige Zahl: " << zahl2 << endl;


    //Zahl 3
    cout << endl << "Bitte geben sie eine Zahl ein (durch 11 teilbar): ";
    cin >> zahl3;
    while ( zahl3 % 11 != 0 )
    {
        cout << "Falsche Eingabe. Bitte geben sie eine Zahl ein die durch 11 teilbar ist: ";
        cin >> zahl3;
    }
    cout << "Danke für die Eingabe der richtige Zahl: " << zahl3 << endl;



    return 0;
}
