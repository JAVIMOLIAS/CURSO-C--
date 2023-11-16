// PRACTICA CLASES.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <Windows.h>
#include <string>
#include <locale.h>
#include <vector>
#include <memory>

using namespace std;

class profesor {
	public:
		int edad;
		string nombre;
public:
	string bienvenida() {
		return "Hola, soy Javi";
	}

};

class clase {		//creamos la clase "clase"
	public:	//modo acceso
		//variales que tendremos que rellenar despues de crear el objeto
		int edad;
		string nombre;
public:
	void escribe() { //metodo que haga lo que queramos al llamarla
		cout << "hola" << endl;
	}
/*public: //constructor como en PYTHON, variables que rellenamos al crear el objeto
	clase(int e, string n) {
		edad = e;
		nombre = n;
	}*/

};




int main()
{
	setlocale(LC_ALL, "ES_es.UTF-8");
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252);

	//creamos clase alumno
/*	clase alumno;
	alumno.edad = 21;
	alumno.nombre = "Javi";
	cout << "Nombre: " << alumno.nombre << endl;
	cout << "Edad: " << alumno.edad << endl;

	//creamos clase alumno2
	clase alumno2;
	alumno2.edad = 21;
	alumno2.nombre = "Javi";
	cout << "Nombre: " << alumno2.nombre << endl;
	cout << "Edad: " << alumno2.edad << endl;

	//llamamos al método escribe de alumno
	alumno.escribe();*/

	/*clase alumno1(21, "pepe");
	cout << "Nombre: " << alumno1.nombre << endl;
	cout << "Edad: " << alumno1.edad << endl;*/

	/*
	cout << endl << "------------------------------arrays--------------" << endl;

	clase* alumnos = new clase[2];	//para crear una array de clase no hemos de tener constructor
	alumnos[0].nombre = "";
	delete[] alumnos; //para eliminar el array de objetos */

	profesor* profesor1;
	profesor1 = new profesor;
	profesor1->edad = 24;
	cout << profesor1->bienvenida()
		<< "javi";
	Sleep(2000);






	return 0;
}

