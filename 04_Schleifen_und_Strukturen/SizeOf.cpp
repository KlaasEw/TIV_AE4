//Aufgabenstellung: Erstellen Sie ein C++ Programm, welches die Größe einer Variablen in Bytes ausgibt.
//Datum: 11.10.2023
//Autor: Klaus Ewald
//Version: 1.0

#include <iostream>                 //Include the iostream library for input and output

using namespace std;                //Standard namespace; avoids prefixing std:: to standard library names

int main()
{
    int a {24};
    cout << "Die Variabele hat den Wert " << a << " und benötigt " << sizeof(a) << " Bytes Speicherplatz" << endl;

    return 0;
}
