// WHILE NUMERO SECRETO.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    //Programa que genera un número aleatorio entre 1 y 100 y nos da pista para adivinarlo

    //el programa nos prepara ese numero
    srand(static_cast<unsigned int>(time(nullptr)));
    int numeroSecreto = rand() % 100 + 1, numero = 0, intentos = 0;

    //bucle para adivinar el numero
    while (numero != numeroSecreto) {
        //aumentamos el numero de intentos realizados
        intentos++;
        cout << "Adivina el numero: ";
        cin >> numero;

        //bucle para comprobar si hemos acertado el numero, si no, nos dice si nuestro numero es mayor o merno
        if (numero == numeroSecreto) {
            cout << "Correcto, has adivinado el numero despues de " << intentos << " intentos" << endl;
        }
        else {
            if (numero > numeroSecreto) cout << "El numero que has introducido es mayor que el secreto" << endl;
            else cout << "El numero que has introducido es menor que el introducido" << endl;
        }
    }
    {

    }
    
}

