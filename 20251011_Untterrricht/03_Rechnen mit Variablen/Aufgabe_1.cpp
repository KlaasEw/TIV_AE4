//Rechnen integer Variablen (Teil 1)

#include <iostream>                 //Include the iostream library for input and output 

using namespace std;                //Standard namespace; avoids prefixing std:: to standard library names


int main()
{
    cout << "Ausgabenüber Variablen:" << endl;
    //Variablen Deklaration und Initialisierung
    int zahl {100}; 
    //Ausgabe der Variable
    cout << "zahl = " << zahl + 10 << endl;
    cout << "zahl = " << zahl - 10 << endl;
    cout << "zahl = " << zahl / 10 << endl;
    cout << "zahl = " << zahl * 10 << endl;

    cout << endl << "Ausgabenüber direkt über Zahlen:" << endl;
    //Ausgabe der Variable
    cout << "zahl = " << 100 + 10 << endl;
    cout << "zahl = " << 100 - 10 << endl;
    cout << "zahl = " << 100 / 10 << endl;
    cout << "zahl = " << 100 * 10 << endl;

    return 0;
}