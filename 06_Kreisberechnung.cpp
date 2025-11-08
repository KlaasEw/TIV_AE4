//Aufgabe: Schreibe ein Programm, das den Benutzer nach dem Radius eines Kreises fragt
//und dann den Umfang und die Fläche des Kreises berechnet und ausgibt.
//Datum: 06.11.2023
//Autor: Klaas Ewald
//Version: 1.0

#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    float radius {0};

    cout << "Bitte geben sie den Radius des Kreises in cm ein: ";
    cin >> radius;
    cout << "Der Umfang des Kreises ist: " << 2 * M_PI * radius << " cm" << endl;
    cout << "Die Fläche des Kreises ist: " << M_PI * pow(radius, 2) << " cm²" << endl;
    
    
    
    return 0;
}
