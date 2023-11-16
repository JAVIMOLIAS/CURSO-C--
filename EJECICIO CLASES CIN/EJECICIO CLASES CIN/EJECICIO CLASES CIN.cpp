// EJECICIO CLASES CIN.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//Solicitar datos de 5 alumnos en pantalla. Los datos que solicitamos son: nombre completo y no. No utilizar array de objeto

#include <iostream>
#include <Windows.h>
#include <string>
#include <locale.h>
#include <vector>
#include <memory>
#include <stdlib.h>

using namespace std;

// clase con los datos de los alumnos
class alumno {
private:
	//declaramos las variables para nombre, apellidos y nota, son privadas, no podemos acceder directamente desde las funciones
	string nombre, apellidos;
	float nota;

public:
	//método que nos permite introducir los datos tipo string del alumno
	string entrada_nombre() {
		cout << "Nombre: ";
		cin.ignore();//ponemos esto para evitar el salto de línea
		getline(cin, nombre);//con getline podemos introducir espacios y que pueda guardar y leer todo
		cout << "Apellidos: ";
		getline(cin, apellidos);
		return "";
	}

	//método que nos permite introducir los datos tipo float del alumno
	float entrada_nota() {
		cout << "Nota: ";
		cin >> nota;
		return 0;
	}

	// función que devuelve el nombre del alumno para poderlo mostrar por pantalla
	string mostrarnombre() {
		string devolvernombre;
		devolvernombre = nombre + " " + apellidos; //concatenamos el nombre y los apellidos unidos en una única variable
		return devolvernombre;
	}

	//función que devuelve la nota del alumno para poderlo mostrar por pantalla
	float mostrarnota() {
		return nota;
	}



};

int main()
{
	//funciones para mostrar caracteres especiales
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252);
	setlocale(LC_ALL, "es_ES.UHT-8");

	int nalumnos; // variable para controlar el número de alumnos con los que vamos a trabjar

	//creamos un array de objetos de la clase alumno
	alumno* alumnos = new alumno[5];

	//pedimos número de alumnos con los que trabajar
	cout << "Número de alumnos a introducir: ";
	cin >> nalumnos;

	//bucle para introducir los datos de los alumnos
	for (int i = 0; i < nalumnos; i++) {
		//mostramos el número del alumno que va a introducir
		cout << "Datos del alumno " << i + 1 << endl;

		//llamada a los métodos de la clase para introducir los datos, al ser privados no podemos acceder directamente a ellos
		//lo pido así para practicar con los métodos
		alumnos[i].entrada_nombre();
		alumnos[i].entrada_nota();
	}
	system("cls"); // limpiamos los datos de la pantalla

	//bucle para mostrar por pantalla los alumnos introducidos en el array
	for (int i = 0; i < nalumnos; i++) {
		// mostramos el número de alumno
		cout << "Alumno " << i + 1 << endl;

		//llamada a las funciones de la clase para mostrar los datos, al ser privados no podemos acceder directamente a ellos
		cout << "Nombre: " << alumnos[i].mostrarnombre() << endl;
		cout << "Nota: " << alumnos[i].mostrarnota() << endl << endl;
	}
	//al terminar la ejecución del programa, pausa la ejecución hasta que pulsemos cualquier tecka
	system("pause");
}

