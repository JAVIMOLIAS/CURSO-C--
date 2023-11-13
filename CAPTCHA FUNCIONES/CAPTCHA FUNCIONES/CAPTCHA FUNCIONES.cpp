// CAPTCHA FUNCIONES.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;


//función para cuando agotamos el número máximo de intentoos
int FinPrograma()
{
    cout << "Has agotado el número máximo de intentos, vuelve a intentarlo en 30 minutos" << endl;
    Sleep(2000);
    return 0;
}



// función LoginCorrecto, como se ha introducido el login correcto, seguimos adelante con el programa
void LoginCorrecto()
{
    cout << "Contraseña correcta, bienvenido" << endl;
    Sleep(2000);
}



//función si el login introducido no es correcto
int LoginErroneo(int entrada, int valorLogin, int contador)
{
    int acceso;
    cout << contador;
    //pedimos introducir de nuevo la contraseña
    cout << "Error contraseña incorrecta: " << endl;
    cout << "Introduce el login: ";
    cin >> entrada;
    //bucle en el que mientras no sea correcta la entrada y el número de veces introducida sea menor de 4, vuelve a llamar a esta función
    while ( contador < 3 && entrada != valorLogin) 
    {
        //aumentamos en 1 contador y vuelve a llamar a la función si la contraseña es incorrecta
        contador++;
        LoginErroneo(entrada, valorLogin, contador);
    }
    //terminamos el bucle, si la contraseña es correcta acceso es true
    if (contador < 3) {
        acceso = true;
    }
    else {
        //si no hemos introducido la contraseña correcta en menos de 4 intentos acceso es false
        acceso = false;
    }
    return acceso;
}


//funcion para comprobar si es correcto el login
int ComprobarEntrada(int entrada, int valorLogin)
{
    int valor;
    if (entrada == valorLogin) {
        // si el login es correcto, pasamos valor como verdadero, si no, como falso
        valor = true;
    }
    else valor = false;
    return valor;
}



// función para ingresar el login
int IngresarLogin(int valorLogin)
{

    int resultado, valor = 0;
    cout << "Introduce la contraseña: ";
    cin >> resultado;

    //llamada a la función ComprobarEntrada para ver si es correcto en login
    valor = ComprobarEntrada(resultado, valorLogin);
    return valor;
}





/// *************************************** FUNCION PRINCIPAL *************************
int main()
{
    int comprobar = 0, contador = 1, entrada, valorLogin = 14;
    //llamamos a la función para introducir el login que nos devuelve un valor
    entrada = IngresarLogin(valorLogin);

    //comprobamos si el valor devuelto por la función IngresarLogin es true o false
    if (entrada) {
        //el valor devuelto por IngresarLogin es correcto, llamada a la función LoginCorrecto que nos permite continuar con el programa
        LoginCorrecto();
    }
    else
    {
        //el valor devuelto por IngresarLogin es incorrecto, llamada a LoginErroneo que nos permite volver a introducir el login
        entrada = LoginErroneo(entrada, valorLogin, contador);
        if (entrada) LoginCorrecto();//si la función LoginErroneo es true entramos en el sistema
        else FinPrograma(); //si la función LoginErroneo se acaba el programa
    }
}









