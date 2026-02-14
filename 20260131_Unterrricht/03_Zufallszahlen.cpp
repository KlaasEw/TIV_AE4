//Zufallszahlen
//Erstelle ein Programm zum Erstellen von Zufallszahlen

//Datum: 31.01.2026
//Autor: Klaas Ewald
//Version: 1.0

#include <iostream>
#include <ctime>


using namespace std;


int main()
{
    const int minimum {50};
    const int  maximum {100};

    srand(time(0));
    for (int i = 0; i < 1000; i++)
    {
        cout << rand()% (maximum - minimum + 1) + minimum << endl;
    }
    
    
}
