// Taschenrechner
// Interaktives Menü zur Durchführung einfacher Rechnungen
// Datum: 13.03.2026 (angepasst 2026)
// Autor: Klaas Ewald (überarbeitet)

#include <iostream>
#include <limits>
#include <cctype>

using namespace std;

// Funktionsprototypen
void zeigeMenue();
void rechneAddition();
void rechneSubtraktion();
void rechneMultiplikation();
void rechneDivision();
double leseZahl(const string &prompt);

int main()
{
    while (true)
    {
        system("clear");
        zeigeMenue();

        char wahl;
        cout << "Ihre Wahl: ";
        cin >> wahl;
        // Eingabe case-insensitive behandeln
        wahl = static_cast<char>(toupper(static_cast<unsigned char>(wahl)));

        switch (wahl)
        {
        case 'A':
            rechneAddition();
            break;
        case 'S':
            rechneSubtraktion();
            break;
        case 'M':
            rechneMultiplikation();
            break;
        case 'D':
            rechneDivision();
            break;
        case 'X':
            cout << "Programm beendet." << endl;
            return 0;
        default:
            cout << "Fehlerhafte Eingabe. Bitte erneut versuchen." << endl;
            break;
        }

        // Pause, damit der Benutzer das Ergebnis sehen kann
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        cout << "\nDrücken Sie Enter, um zum Menü zurückzukehren...";
        cin.get();
    }

    return 0;
}

void zeigeMenue()
{
    cout << "=== Einfacher Taschenrechner ===" << endl;
    cout << "A - Addition (+)" << endl;
    cout << "S - Subtraktion (-)" << endl;
    cout << "M - Multiplikation (*)" << endl;
    cout << "D - Division (/)" << endl;
    cout << "X - Beenden" << endl;
}

// Liest eine Zahl vom Benutzer (double) mit Fehlerbehandlung
double leseZahl(const string &prompt)
{
    double wert;
    while (true)
    {
        cout << prompt;
        cin >> wert;
        if (cin.fail())
        {
            cout << "Ungültige Eingabe. Bitte eine Zahl eingeben." << endl;
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        return wert;
    }
}

void rechneAddition()
{
    double a = leseZahl("Erste Zahl: ");
    double b = leseZahl("Zweite Zahl: ");
    cout << "Ergebnis: " << a << " + " << b << " = " << (a + b) << endl;
}

void rechneSubtraktion()
{
    double a = leseZahl("Erste Zahl: ");
    double b = leseZahl("Zweite Zahl: ");
    cout << "Ergebnis: " << a << " - " << b << " = " << (a - b) << endl;
}

void rechneMultiplikation()
{
    double a = leseZahl("Erste Zahl: ");
    double b = leseZahl("Zweite Zahl: ");
    cout << "Ergebnis: " << a << " * " << b << " = " << (a * b) << endl;
}

void rechneDivision()
{
    double a = leseZahl("Dividend (erste Zahl): ");
    double b;
    while (true)
    {
        b = leseZahl("Divisor (zweite Zahl): ");
        if (b == 0.0)
        {
            cout << "Fehler: Division durch 0 ist nicht erlaubt. Bitte anderen Wert eingeben." << endl;
            continue;
        }
        break;
    }
    cout << "Ergebnis: " << a << " / " << b << " = " << (a / b) << endl;
}