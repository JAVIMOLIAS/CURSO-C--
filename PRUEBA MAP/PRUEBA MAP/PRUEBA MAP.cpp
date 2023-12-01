// PRUEBA MAP.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <Windows.h>
#include <string>
#include <locale.h>
#include <vector>
#include <memory>
#include <stdlib.h>
#include <map>

using namespace std;


class objeto {
public:
	string nombre;
	int edad;

	
};

int main()
{
	string nombre;
	int nota;
	int salir = 0, contador = 0, edad;
	map <string, objeto> prueba;
	cout << "Número alumnos: ";
	cin >> contador;
	for (int i = 0; i < contador; i++) {
		cout << "Nombre";
		cin.ignore();
		getline(cin, nombre);
		prueba[to_string(i)].nombre = nombre;
		cout << "Edad: ";
		cin >> nota;
		prueba[to_string(i)].edad = nota;
	}

	for (int i = 0; i < contador; i++) {
		cout << prueba[to_string(i)].nombre << endl;
		cout << prueba[to_string(i)].edad << endl;
	}
}

