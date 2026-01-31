//Pallindorm Prüfung
//Erstelle eine Funktion die die Zahl umdrehrt mit dem Original vergleicht.
//Wenn beide Zahlen gleich sind, soll dies als Palindrom erkannt werden.

//Datum: 31.01.2026
//Autor: Klaas Ewald
//Version: 1.0

#include <iostream>

using namespace std;

bool isPalindrome(int Zahl) {
    int Original = Zahl;
    long Umgedreht = 0; // 'long', um Überlauf bei Rückwärtszählung zu vermeiden
    
    // Zahl umkehren
    while (Zahl > 0) {
        Umgedreht = Umgedreht * 10 + Zahl % 10;
        Zahl /= 10;
    }
    
    // Original mit Umkehrung vergleichen
    return Original == Umgedreht;
}

int main() {
    int Eingabe {};
    cin >> Eingabe;
    if (isPalindrome(Eingabe)) {
        cout << Eingabe << " ist ein Palindrom." << endl;
    } else {
        cout << Eingabe << " ist kein Palindrom." << endl;
    }
    return 0;
}