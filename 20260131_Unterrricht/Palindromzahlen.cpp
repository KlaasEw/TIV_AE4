//Pallindorm Prüfung
//Ergelichen der ersten un der letzten Ziffer.

//Datum: 31.01.2026
//Autor: Klaas Ewald
//Version: 1.0


#include <iostream>

using namespace std;

int main (){
    //Variablendefinition
    int Eingabe {};
    int letzte {};
    int erste{};

    //Eingabe
    cin >> Eingabe;

    //Berechnen der letzten Stelle
    letzte = Eingabe % 10;

    //Berechnen der Ersten Stelle
    erste = Eingabe;
    
    while (erste >= 10)
    {
        erste = erste / 10;
    }

    //Ausgabe: vergelich der ersten und der letzten Ziffer
    if (erste == letzte)
    {
        cout << "Palindrom gefunden" << endl;
    }else{
        cout << "Kein Palindrom gefunden" << endl;
    }
    
    //Ausgabe
    cout <<  "Eingabe: " << Eingabe << endl;
    cout << "Erste Ziffer " << erste << endl;
    cout << "Letzte Ziffer " << letzte << endl;
    


}