

#include <iostream>

using namespace std;

int main()
{
    int ergebnis {0};

    cout << "Die folgenden zahlen sind durch 3 teilbar: " << endl;

    for ( int i = 0; i <= 1000; i++ )
    {
        if (i % 3 == 0)
        {
            cout << i << ",";
            ergebnis += i;
            //ergebnis = ergebnis + 1;
        }
    }
    cout << endl << "Das Endergebnis ist: " << ergebnis << endl;


    return 0;
}