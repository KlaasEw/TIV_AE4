// Ausgaben der länge von Short, int, long, long long und deren Maximalwerte
//Datum: 08.11.2023
//Autor: Klaas Ewald
//Version: 1.0

#include <iostream>

using namespace std;

int main()
{
    //Short
    short shortVar {0};
    cout << "Short Variablen" << endl;
    cout << "Die Größe von short ist: " << sizeof(shortVar) << " Bytes" << endl;
    cout << "Der Maximalwert von short ist: " << (pow(2, (sizeof(shortVar) * 8)-1)-1) << endl;


    // Integer
    int intVar {0};
    cout << endl << "Integer Variablen" << endl;
    cout << "Die Größe von int ist: " << sizeof(intVar) << " Bytes" << endl;
    cout << "Der Maximalwert von short ist: " << (pow(2, (sizeof(intVar) * 8)-1)-1) << endl;

    // Long
    long longVar {0};
    cout << endl << "long Variablen" << endl;
    cout << "Die Größe von long ist: " << sizeof(longVar) << " Bytes" << endl;
    cout << "Der Maximalwert von long ist: " << (pow(2, (sizeof(longVar) * 8)-1)-1) << endl;

    // Long Long
    long long longLongVar {0};
    cout << endl << "long long Variablen" << endl;
    cout << "Die Größe von long long ist: " << sizeof(longLongVar) << " Bytes" << endl;
    cout << "Der Maximalwert von long long ist: " << (pow(2, (sizeof(longLongVar) * 8)-1)-1) << endl;

    return 0;
}