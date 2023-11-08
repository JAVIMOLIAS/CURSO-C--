

#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	// PROGRAMA PARA PEDIR UNA SUMA COMO ACCESO AL SISTEMA
	int login;
	int contador = 0;
	cout << "Introduce la suma de 5 + 9: ";
	cin >> login;
	//INTRODUCIMOS UN RESULTADO, SI ES CORRECTO ACCEDEMOS AL SISTEMA
	if (login == 14) {
		cout << "\nAcceso correcto";
		Sleep(1000);
		
	}
	else 
	{
		//SI EL RESULTADO ES INCORRECTO, NOS DA LA OPORTUNIDAD DE VOLVER A INTENTARLO
		while (contador < 3 && login != 14)
		{
			contador += 1;
			cout << "\nError, vuelve a intentarlo";
			cout << "\nIntroduce la suma de 5 + 9: ";
			cin >> login;
			if (login == 14)
			{
				cout << "\nAcceso correcto";
				Sleep(1000);
			}
		}
		if (contador == 3)
		{
			cout << "has agotado los intentos";
			Sleep(1000);
		}
	}
}
