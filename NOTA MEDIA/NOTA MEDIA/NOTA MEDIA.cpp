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
    int numero = 0, contador = 0;
    float media = 0, calificacion[5];
    
    cout << "Número de notas a introducir: ";
    cin >> numero;

    //bucle para introducir las notas en el array y sumarlas
    for (int i = 0; i < numero; i++) {
        //pido la nota
        cout << endl << "Introduce la nota de " << i + 1 << ": ";
        cin >> calificacion[i];

        //sumo la nota al resto de notas introducidas
        media += calificacion[i];
    }
    //bucle en el que muestro las notas introducidas en el array
    cout << long(calificacion);
    Sleep(2000);
    for (float iterador : calificacion) {
        contador++;
        cout << "calificación del alumno " << contador <<": " << iterador << endl;
    }
    //muestra el resultado de la nota media
    cout << "La nota media es: " << media / numero << endl;
    
   
}

