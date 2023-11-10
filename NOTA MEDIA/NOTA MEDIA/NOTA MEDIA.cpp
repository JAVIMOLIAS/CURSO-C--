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
    setlocale(LC_ALL, "ES_es.UTF-8");
    SetConsoleOutputCP(1252);
    SetConsoleCP(1252);
    //defino el string donde añadiremos las notas
    int numero = 0, nota, media = 0, calificacion[5] = {};

    for (numero; numero < 5; numero++) {
        cout << "Introduce la nota de " << numero + 1 << ": ";
        cin >> nota;
        calificacion[numero] = nota;
        media += nota;
    }
    media = media / 5;
    cout << "La nota media es: " << media << endl;
    
   
}

