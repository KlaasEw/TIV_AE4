//Expotentialfunktionen: Ausgabe der Maximal in einem Integer speicherbare Zahl
//Datum: 08.11.2023
//Autor: Klaas Ewald
//Version: 1.0


#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int basis {2};
    int ergebnis {1};

    // Maximal in einem Integer speicherbare Zahl
    ergebnis = pow(basis, (sizeof(basis) * 8)-1);
    cout << ergebnis << endl;

    //Was pasiert, wenn wir 1 addieren? >> die Zahl "überläuft" und wird maximal negativ
    ergebnis = pow(basis, (sizeof(basis) * 8)-1);
    ergebnis = ergebnis +1;
    cout << ergebnis << endl;


    return 0;
}
