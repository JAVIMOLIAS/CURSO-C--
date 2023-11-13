// NOTA MEDIA.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <Windows.h>
#include <locale.h>
#include <string>

using namespace std;


//***************************************************************** FUNCION PRINCIPAL ***************************************************************
int main()
{
    //funciones para poder ver caracteres especiales
    setlocale(LC_ALL, "ES_es.UTF-8");
    SetConsoleOutputCP(1252);
    SetConsoleCP(1252);

    //defino el string y las variables para sacar la nota media
    int numero = 0, contador = 0, media = 0, calificacion[5] = {};
    

    //bucle para introducir las notas en el array y sumarlas
    for (numero; numero < 5; numero++) {
        //pido la nota
        cout << "Introduce la nota de " << numero + 1 << ": ";
        cin >> calificacion[numero];

        //sumo la nota al resto de notas introducidas
        media += calificacion[numero];
    }
    //bucle en el que muestro las notas introducidas en el array
    for (int iterador: calificacion) {
        contador++;
        cout << "calificación del alumno " << contador <<": " << iterador << endl;
    }
    //muestra el resultado de la nota media
    cout << "La nota media es: " << media /5 << endl;
    
   
}

