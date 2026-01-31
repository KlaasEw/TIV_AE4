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
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        cout << rand() << endl;
    }
    
    
}
