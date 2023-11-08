

#include <iostream>
#include <string>
using namespace std;


int suma(int a, int b)
{
	int resultado;
	resultado = a + b;
	return resultado;
}

int main()
{
	int numero1, numero2, resultado;
	cout << "Numero 1: ";
	cin >> numero1;
	cout << "Numero 2: ";
	cin >> numero2;
	resultado = suma(numero1, numero2);
	cout << resultado;
}

