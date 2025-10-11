//Rechnen integer Variablen (Teil 2)
//Besonderheiten von vor und nachgelageerter Inkrementierung und Modulo-Operator


#include <iostream>                 //Include the iostream library for input and output 

using namespace std;                //Standard namespace; avoids prefixing std:: to standard library names


int main()
{
    int a {10}, b {9};
    cout << "zahl = " << a++ << endl;
    cout << "zahl = " << ++a << endl;
    cout << "zahl = " << a%2 << endl;
    cout << "zahl = " << a%3 << endl;

    return 0;
}