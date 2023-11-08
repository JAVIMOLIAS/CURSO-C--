// hipotenusa.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <Windows.h>
#include <locale.h>
#include <math.h>

using namespace std;

int main()
{
 
    //rutina para calcular la hipotenusa a partir de los catetos introducidos
    double cateto1, cateto2, hipotenusa, hipotenusa2;
    cout << "Introduce cateto 1: ";
    cin >> cateto1;
    cout << "Introduce cateto 2: ";
    cin >> cateto2;

    //hipotenusa calculada por C++
    cout << "Hipotenusa calculada por c++: " << hypot(cateto1, cateto2) << endl;

    //hipotenusa calculada por operaciones
    hipotenusa = pow(cateto1, 2) + pow(cateto2, 2);
    hipotenusa2 = sqrt((pow(cateto1, 2) + pow(cateto2, 2)));
    cout << "Hipotenusa calculada con operaciones V1: " << sqrt(hipotenusa) << endl;
    cout << "Hipotenusa calculada con operaciones V2: " << hipotenusa2 << endl;
    system("pause");


}


