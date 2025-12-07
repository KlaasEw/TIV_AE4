//AUFGABE: Array sortieren
//Erstellen sie ein Programm das ein Arry mit 10 Integer Werten anlegt und diese anschließend der Größe nach sortiert ausgibt.
//Dazu soll der Algorithmus "Bubble Sort" verwendet werden.
//Datum: 06.12.2025
//Autor: Klaas Ewald
//Version: 1.0

#include <iostream>
#define ARRAY_SIZE 10

using namespace std;

int main()
{
    int a[ARRAY_SIZE] = {1,5,7,18,2,3,128,12,35,42};

    //ARray vor dem Sortieren ausgeben
    cout << endl <<  "Array vor dem Sortieren:" << endl;
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    

    //Bubble Sort Algorithmus
    for (int i = 1; i < ARRAY_SIZE; i++)
    {
            for (int n = 0; n < ARRAY_SIZE-i; n++)
            {
                if ( a[n] > a[n+1]){
                    int temp = a[n];
                    a[n] = a[n+1];
                    a[n+1] = temp;
                }
            }
    }

    
    //Array nach dem Sortieren ausgeben
    cout << endl << "Array nach dem Sortieren:" << endl;
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        cout << a[i] << " ";
    }

    cout << endl << endl;
    


    return 0;
}
