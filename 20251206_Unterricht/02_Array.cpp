//AUFGABE: Array
//Erstellen sie eine Arry das die folgenden werte enthält 1,5,7,18,2,3,128,12,35,42
//Geben sie anschließend alle Werte des Arrays mit einer Schleife aus
//Datum: 06.12.2025
//Autor: Klaas Ewald
//Version: 1.0

#include <iostream>

using namespace std;

int main()
{
    int a[10] = {1,5,7,18,2,3,128,12,35,42};

    for (int  i = 0; i < 10; i++)
    {
        cout << "Element " << i << ": " << a[i] << endl;
    }
    
    
    return 0;
}
