//Switch Case
//Schreiben sie ein Programm welches ein einzelens Zeichen aus der Eingabe einließt und dieses Anschließend wieder ausgibt.
//Datum: 13.03.2026
//Autor: Klaas Ewald
//Version: 1.0


#include <iostream>

using namespace std;

int main()
{
    char a;
    cout << "Geben sie für Test_1 (a)ein, Geben sie für Test_2 (b) ein" << endl;
    cin >> a;

    switch (a)
    {
    case 'a':
        cout << "Ihre Eingabe war a" << endl;
        break;
    case 'b':
        cout << "Ihre Eingabe war b" << endl;
        break;
    
    default:
        cout << "Fehlerhafte Eingabe" << endl;
        break;
    }

}