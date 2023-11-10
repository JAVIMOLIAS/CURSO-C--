// ARRAYS-FOR.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <Locale.h>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
    //funciones para poder ver bien por pantalla los caracteres especiales
    setlocale(LC_ALL, "ES_es.UFT-8");
    SetConsoleOutputCP(1252);
    SetConsoleCP(1252);
           
    //declaramos array con un máximo de 20 elementos
    string frutero[20] = { "pera", "manzana", "platano" };

    cout << "----------------------" << endl;

    //mostrar segunda posición del array
    cout << "mostrar segunda posicion: " << frutero[1] << endl;

    cout << "----------------------" << endl;


    //cambiar valor posición valor
    frutero[0] = "melon";
    cout << "cambiar valor posición 1: " << frutero[0] << endl;

    cout << "----------------------" << endl;


    //añadir valor array
    frutero[3] = "fresa";
    cout << "añadir valor al array: " << frutero[3] << endl;

    cout << "----------------------" << endl;


    //iterar por los valores del array con for
    cout << "vamos a recorrer los elementos del array con for" << endl;
    for (int i = 0; i < 4; i++) {
        cout << frutero[i] << endl;
    }

    cout << "----------------------" << endl;


    //iterar por los valores del array con for each
    cout << "vamos a recorrer los elementos del array con for each" << endl;
    for (string i : frutero) {
        cout << i << ", ";
    }


}
