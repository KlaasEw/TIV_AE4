//AUFGABE: Array 2
//Erweitern sie das Programm aus 02_Array.cpp so das die größe des Array für die Aufgabe irrelevant ist.
//Benutzen sie dazu sizeof() Funktion
//Datum: 06.12.2025
//Autor: Klaas Ewald
//Version: 1.0

#include <iostream>

using namespace std;

int main()
{
    int a[10] = {1,5,7,18,2,3,128,12,35,42};
    cout << "Das Array kann " <<sizeof(a) / sizeof(a[0]) << " Werte vom Type Integer mit einer Größe von je " << sizeof(a[0]) << " Byte speichern." << endl;

    for (int  i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        cout << "Element " << i << ": " << a[i] << endl;
    }
    return 0;
}
