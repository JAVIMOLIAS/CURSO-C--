// programa para concatenar
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
	int numero = 5;
	string resultado = (numero < 5) ? "bien" : "mal";
	cout << "introduce numero: ";
	cin >> numero;
	cout << resultado;

	
}
