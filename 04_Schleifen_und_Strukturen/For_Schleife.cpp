//For-Schleife: Zahler von 0 bis 99 addieren
//Schreiben sie ein Programm, das die Zahlen von 0 bis 99 addiert und das Ergebnis ausgibt.

#include <iostream>                 //Include the iostream library for input and output 

using namespace std;                //Standard namespace; avoids prefixing std:: to standard library names


int main()
{
    //For-Schleife: Zahler von 0 bis 99 addieren
    int a {0};

    for (int i = 0; i <= 99; i++)
    {
        cout << "Wert a = " << a << ", ich andiere jetzt den Wert = " << i << endl;
        a += i;     //a = a + i;

    }

    //Ausgabe des Endwertes
    cout << "Endwert a = " << a << endl;
    
    return 0;
}