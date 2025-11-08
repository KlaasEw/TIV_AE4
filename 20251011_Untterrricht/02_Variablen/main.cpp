#include <iostream>                 //Include the iostream library for input and output 

using namespace std;                //Standard namespace; avoids prefixing std:: to standard library names


int main()
{
    //Variablen Deklaration und Initialisierung
    int test = 42;

    //Fehler werden im Compiler erkannt
    int test2 {42};

    //Mehrere Variablen deklarieren und initialisieren
    int a,b,c;
    int d{0}, e{1}, f{2};

    return 0;
}

