//Aufgaben: erstellen sie eine Konsolen Eingabe
//Datum: 08.11.2023
//Autor: Klaas Ewald
//Version: 1.0

#include <iostream>

using namespace std;

int main()
{
    int eingabe {0};
    cout << "Bitte geben sie eine Zahl ein: ";
    cin >> eingabe;
    cout << "Sie haben die Zahl " << eingabe << " eingegeben." << endl;
    return 0;
}
