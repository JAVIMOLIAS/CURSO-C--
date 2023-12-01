// EJERCICIO SWITCH CASE.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <Windows.h>
#include <string>
#include <locale.h>
#include <vector>
#include <memory>
#include <stdlib.h>

using namespace std;


//declaramos la clase que va a contener los datos de los libros
class libro {
private:
	//variables de la clase como privadas
	string autor, titulo;
	float precio;

public:
	//método para crear los datos del libro La Catedral del Mar
	string catedral() {
		autor = "Ildefonso Falcones";
		titulo = "La Catedral del Mar";
		precio = 19.8;
		return "";
	}

	//método para crear los datos del libro La Sombra del Viento
	string sombra() {
		autor = "Carlos Ruiz Zafón";
		titulo = "La Sombra del Vientro";
		precio = 15.2;
		return "";
	}


	//método para crear los datos del libro Los Pilares de la Tierra
	string pilares() {
		autor = "Ken Follet";
		titulo = "Los Pilares de la Tierra";
		precio = 21.2;
		return "";
	}

public:
	//método para listar por pantalla los datos de los objetos  NO PROBADO
	string ver_titulo() {
		return titulo;
	}

	string ver_autor(){
		return autor;
	}

	float ver_precio() {
		return precio;
	}
};




int main()
{
	//declaro las variales contador para controlar el número de libros pedidos, y opcion para poder salir del bucle
	int opcion = 0, contador = 0;

	//declaro un array de la clse libro
	libro* compra = new libro[20];


	//bucle para controlar la salida del programa
	while (opcion != 5){

		system("cls");
		//menú que se muestra por pantalla con las opciones disponibles
		cout << "-------------------------------librería Javi ------------------------" << endl;
		cout << "1. Comprar La Catedral del Mar" << endl;
		cout << "2. Comprar La Sombra del viento" << endl;
		cout << "3. Comprar Los Pilares de la Tierra" << endl;
		cout << "4. Ver carrito" << endl;
		cout << "5. Salir" << endl;
		cout << "Opción: ";
		//leer la opción elegida
		cin >> opcion;

		//switch para las acciones del menu
		switch (opcion){
			case 1:
				//aumentamos contador y llamada al metodo de la clase libro para añadir los datos de la opcion 1
				contador++;
				compra[contador].catedral();
				break;

			case 2:
				//aumentamos contador y llamada al método de la clase libro para añadir los datos de la opción 2
				contador++;
				compra[contador].sombra();
				break;

			case 3:
				//aumentamos contador y llamada al método de la clase libro para añadir los datos de la opción 3
				contador++;
				compra[contador].pilares();
				break;

			case 4:
				//bucle para mostrar por pantalla los datos del pedido
				system("cls");
				for (int i = 0; i < contador; i++)
				{
					cout << compra[i].ver_autor() << endl;
					cout << compra[i].ver_titulo() << endl;
					cout << compra[i].ver_precio() << endl;
				}
				system("pause");
				break;
			case 5:
				cout << "Fin programa";
				break;
		}
	}
	return 0;
}
