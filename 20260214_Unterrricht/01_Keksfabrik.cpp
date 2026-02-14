//Keksfabrik
//Erstelle ein Programm zur Produktion von Keksen in einer Keksfabrik.
//Die Fabrik produziert 10.000 Kekse in einem Größenbereich von 50 - 56mm.
//Verkauft werden können nur Kekse im Bereich zwischen 52 - 54 mm.
//Die zugroßen, richigen und zu kleinen Kekse sollen abgespeichert und ausgegeben werden.

//Datum: 14.02.2026
//Autor: Klaas Ewald
//Version: 1.0

#include <iostream>
#include <ctime>


using namespace std;


int main()
{
    const int maxi {56};
    const int  mini {50};
    const int tol_maxi {54};
    const int tol_mini {52};
    int kekse_prod[10000];
    int kekse_schlecht[10000];

    int schlecht_zaeler {0};

    int zu_klein {0};
    int zu_gross {0};

    //Herstellen der Kekse
    //Es werden 10.000 Kekes mit einer Größe von 50 - 56mm hergestellt
    srand(time(0));
    for (int i = 0; i < 10000; i++)
    {
        kekse_prod[i] = rand() % (maxi - mini + 1) + mini;
    }

    //Qualitätsprüfung der der Kekse
    for (int i = 0; i < 10000; i++)
    {
        if (kekse_prod[i] < tol_mini) //Zu kleine Kekse aussortieren
        {
            kekse_schlecht[schlecht_zaeler] = kekse_prod[i];
            schlecht_zaeler++;
            kekse_prod[i] = 0;
            zu_klein++;
        }
        else if (kekse_prod[i] > tol_maxi) //Zu große Kekse aussortieren
        {
            kekse_schlecht[schlecht_zaeler] = kekse_prod[i];
            schlecht_zaeler++;
            kekse_prod[i] = 0;
            zu_gross++;
        }
    }
    //Ausgabe der Statistik
    cout << "Gute Kekse: " << 10000 - zu_gross - zu_klein << endl;
    cout << "Kekse zu groß: " << zu_gross << endl;
    cout << "Kekse zu klein: " << zu_klein << endl;
    cout << "Schlechte Kekse: " << schlecht_zaeler << endl;

    cout << "Stichprobe der guten Kekse: " << endl;
    for (int  i = 0; i < 10000; i+=100)
    {
        cout << kekse_prod[i] << ", ";
    }
    
    cout << endl << "Stichprobe der schlechten Kekse: " << endl;
    for (int  i = 0; i < 10000; i+=100)
    {
        cout << kekse_schlecht[i] << ", ";
    }
    
}