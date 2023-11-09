// LOGIN3INTENTOS.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	// introducir un valor y si falla mas de 3 veces, sale del programa
    int intento = 1, valor;

	while (intento < 4)	{
		cout << "Introduce la suma de 5+9: ";
		cin >> valor;
		if (valor != 14 && intento < 2)  {
			cout << "Error, intento " << intento << " fallido, vuelve a intentarlo " << endl;
			intento++;
		}else if ((valor != 14) && (intento == 2)) {
			cout << "Error, te queda 1 intento " << endl;
		}else {
			cout << "Acceso correcto ";
		}
		if (intento >= 4) cout << "Has gastado todos los intentos, fin programa";
	}
}

