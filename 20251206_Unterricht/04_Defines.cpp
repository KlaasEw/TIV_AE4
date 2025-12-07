//AUFGABE: Defines
//Schreiben sie ein Programm das ein Array aus Interwerten anlegt.
//Die Größe des Array soll durch ein Define bestimmt werden.
//Geben sie anschließend die Anzahl der Elemente und die Größe des Arrays in Byte aus.
//Datum: 06.12.2025
//Autor: Klaas Ewald
//Version: 1.0

#include <iostream>

#define ARRAY_SIZE 7

using namespace std;

int main()
{
    int a[ARRAY_SIZE];


    cout << "Das Array kann " <<sizeof(a) / sizeof(a[0]) << " Werte vom Type Integer mit einer Größe von je " << sizeof(a[0]) << " Byte speichern." << endl;
    cout << "Die Gesamtgröße des Arrays beträgt " << sizeof(a) << " Byte." << endl << endl;
    
    return 0;
}