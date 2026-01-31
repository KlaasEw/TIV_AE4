//Pallindorm Prüfung
//Erstelle eine Funktion ein Palindrom erkenne dafrü soll diese Funktiondie Eingabe umdrehen und mit dem Original vergleichen.
//Wenn beide Zahlen gleich sind, soll dies als Palindrom erkannt werden.
//zahlen die beiden Zähler i und J nach oben bis Ihler Limits Mulit1 und Muli2 ereicht sind.
// Prüfe jedes Mulitiplikationsergebnis, ob dies ein Palindrom ist. Falls ja gebe dies auf der Konsole aus.


//Datum: 31.01.2026
//Autor: Klaas Ewald
//Version: 1.0

#include <iostream>
#include <sstream>

#define Multi1 999
#define Mulit2 999

using namespace std;

//Funktionsprototyp
bool PalindromPrüfung(int);


int main()
{
    string input {""};

    for (int i = 10; i <= Multi1; i++)
    {
        for (int j = 1; j <= Mulit2; j++)
        {
            if (PalindromPrüfung(int(i*j))) {
                cout << j << " * " << i << " ist ein Palindrom: " << j*i << endl;
            }
        }
        
    }
    
    return 0;
}

//Funktion zur Prüfung ob ein Palindrom vorliegt
bool PalindromPrüfung(int Zahl){

    string eingabe;
    eingabe = to_string(Zahl);

    string compare = eingabe;
    

    for (int i = 0; i < eingabe.length(); i++)
    { 
        compare[eingabe.length()-i-1] = eingabe[i];
    }

    return eingabe == compare;
}