// PIRAMIDE.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <Windows.h>

using namespace std;


//******************************************************************* FUNCIÓN PRINCIPAL *******************************************************************
int main()
{
    //declaro variables para mostrar número *
    int numeroLinea, asteriscosLinea;

    //pido el número de *
    cout << "Numero de *: ";
    cin >> numeroLinea;

    //bucle for que me creará las líneas de *
    for (numeroLinea; numeroLinea > 0; numeroLinea--) 
    {
        //bucle for que imprime el número de * por línea
        for (asteriscosLinea = 1; asteriscosLinea <= numeroLinea; asteriscosLinea++)
        {
            //muestra por pantalla 1 * por cada repetición del for
            cout << "*";
        }
        //una vez terminado el for salta de linea
        cout << endl;
    }

    //detiene el final del programa 2 segundos antes de que se cierre la consola
    Sleep(2000);
}

