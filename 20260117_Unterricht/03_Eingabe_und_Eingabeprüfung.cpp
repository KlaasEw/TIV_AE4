//Aufgabe:
//Nutzereingaben mit Fehlerprüfung

//Aufgabenstellung 1:
//Ein User soll eine Zahl eingeben.
//Die Zahl soll größer als 0 sein.
//Buchstaben und Sonderzeiche sind nicht zulässig.
//Bei Falschereingabe ist die Eingabe zu wiederhohlen.

//Aufgabenstellung 2:
//Die Aufgabenstellung wird jetzt angepasst, dadraufhin das jetzt auch negative Zahlen erlabt werden sollen.

//Aufgabenstellung 3:
//Die Aufgabenstellung wirdn jetzt ein weiteres Mal angepasst werden, es sollen auch Komma erlabt werden.
//Als Komma sind die folgenden zeichen zulässig "," & "."
//Es darf nur ein Komma vorhanden sein
// Das Komma darf nicht an der ersten oder der letztenstelle itzen und auch nicht direkt hinter dem Komma

//Datum: 17.01.2026
//Autor: Klaas Ewald
//Version: 1.0

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    
    bool fehler {false};
    bool negativ {false};
    bool komma {false};
    int position {0};
    string input;
    float zahl {0.0};

    do
    {
        fehler = false;
        komma = false;
        //Eingabe
        cout << endl <<  "Bitte gibt eine Zahl ein: ";
        cin >> input;

        //Staren der Analyse
        cout << "Warte ... ich analyisere die Eingabe:" << endl << endl;
        
        //Pfüfen ob Ziffern das Array aus Ziffen besteht
        for (int i = 0; i < input.length(); i++)
        {
            
            //Überprüfen ob das erste Symbol ein Minuszeichen ist, wenn ja setzte die Variable negativ auf true
            //der Wert 45 entspricht dem ASCII-Zeichen "-"
            if (i == 0 && int(input[i]) == 45)
            {
                cout << "Das erste Zeichen ist ein Minus" << endl;
                negativ = true;
            }

            //Überprüfen ob ein Komma vorhanden ist
            //der Wert 44 entspricht dem ASCII-Zeichen "," und der Wert 46 entspricht dem ASCII-Zeichen "."
            if (i != 0 && i != input.length() &&(int(input[i]) == 44 || int(input[i]) == 46 ) && komma== false)
            {
                komma = true;
                position = i;
                cout << "komma: " << komma << " positon: " << position << endl;
            }else if (komma == true &&(int(input[i]) == 44 || int(input[i]) == 46 ))
            {
                fehler = true;
                cout << "Zu viele Komma eingegeben " << endl;
            }
            
            
            
            
            //int(input[i]) wandelt die einzelnen Zeichen des Strings in ihre Dezeimalen Werte aus der ASCII-Tabelle um.
            //Der Wert 48 entspricht laut der Tabelle dem Zeichen 0 und der Wert 57 entspricht dem Zeichen 9
            //Ist der Werte also zwischen 0 und 9 wird die Bedingung ausgeführt, stimmt die Bedingung nicht wird Else ausgeführt, ein Feler ausgegeben und die Variable Fehler auf True gesetzte.
            //Ergäzt um Abrfrage auf Wert 44 und 46 also den Zeichen "." und ","
            cout << "ASCII-Zeichennummer: " << int(input[i]) << " Buchtabe: "<< input[i];

            if ((int(input[i]) > 48 && int(input[i]) < 57) || (int(input[i]) == 44 || int(input[i]) == 46 ))
            {
                cout << endl;
            }else
            {
                //Wenn negativ true ist soll diese Fehlermeldung bzw. das setzen des Fehlercodes  an der ersten Stelle nicht gesetzt werden.
                if (negativ == true && i == 0)
                {
                    fehler = false;
                    cout << endl;
                }
                else
                {
                    cout << " Fehler! " << endl;
                    fehler = true;
                }

                
                
                
            }
        } 
        //Ausgabe eines fehlercodes, Luafvariable der do while Schleife
        cout << "Fehlercode: " << fehler << endl;

        // Falls ein Fehler vorliegt, ausgeben einer Fehlermeldung.
        if (fehler)
        {
            cout << "Leider hast du einen flaschen Wert eingeben, es sind nur Ziffern zwischen 0 und 9 zulässig" << endl;
        }

        
    //Abfrage solange durchfühen bis der Nutzer eine richtige Eingabe getätigt hat
    } while (fehler);

    //Ausgeben das eingegebene Zeichenkette richtig war
    cout << endl << "Du hast eine zulässige Zeichenkette eingegeben: " << input << endl;

    //Umwandeln der eingegeben Zeichenkette in eine Zahl
    //Für die Prüfung ist die Umwandlung in eine Zahl nicht notwendig, aber für weitere Berechnungen.
    //Dieser Allgoritmus muss angepasst werden um die Berechnung von Komma zahlen zu ermöglichen.

    if (negativ)
    {
        for ( int i = 1; i < input.length(); i++)
        {
            zahl += (input[i]- '0') * pow(10, input.length()-1-i);
        }
        zahl = -zahl;
    }else
    {
        for ( int i = 0; i < input.length(); i++)
        {
            zahl += (input[i]- '0') * pow(10, input.length()-1-i);
        } 
    }

    // Die Umwandlung in eine Zahl kann alternativ über dise Zeile durchgeführt werden:
    //zahl = stoi(input);
    //Unterscheidliche Brechenungen für positive und nagative Zahlen sind damit nicht notwendig.
    
    //Ausgabe der eingegebenen Zahl als Integer
    cout << "Der eingegebene Wert wurde in eine Zahl umgewandelt und kann für wietere Berechnungen genutzt werden: "<< zahl << endl;


    return 0;
}
