//Aufgabe Guwamdeln eines gegebenen Struktorgramms in Programmcode

//Datum: 14.02.2026
//Autor: Klaas Ewald
//Version: 1.0

#include <iostream>

using namespace std;

int main()
{
    int ar[5]{1,6,4,7,9};
    int temp {0};

    for (int n = 1; n < sizeof(ar)/sizeof(int)-1; n++)
    {
        for (int i = 0; i < sizeof(ar)/sizeof(int)-n; i++)
        {
            temp = ar[i];
            ar[i] = ar[i+1];
            ar[i+1] = temp;
        }
        
    }
    for (int i = 0; i < sizeof(ar)/sizeof(int); i++)
    {
        cout << ar[i] << ", ";
    }

    cout << endl;
    
    
}


