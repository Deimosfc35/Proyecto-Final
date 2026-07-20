#include <iostream>
#include "proyecto.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

int main() {

    int opcion;

    do {
        cout << "=========================================" << endl;
        cout << "              MENU PRINCIPAL" << endl;
        cout << "=========================================" << endl;
        cout << "1.- Red neuronal" << endl;
        cout << "2.- Resolucion sistema de ecuaciones lineales" << endl;
        cout << "3.- Resolucion laberinto" << endl;
        cout << "0.- Salir" << endl;
        cout << "=========================================" << endl;
        cout << "Seleccione una opcion: " << endl;
        cin >> opcion;

        switch(opcion) {

            // ==============Ejercicio 1 ==============

            // Investigue el funcionamiento del algoritmo de una Red Neuronal.
            // Implemente una red neuronal que sea capaz de predecir el valor de Y
            // recibiendo una entrada X

            case 1:{
            	Ejercicio1();
				break;
			}
			
            // ==============Ejercicio 2 ==============

            // Realice un algoritmo que permita resolver sistemas de ecuaciones lineales.

            case 2:{
            	Ejercicio2();
				break;
			}
			
            // ==============Ejercicio 3 ==============

            // Genere un algoritmo para resolver laberintos.
            // Representa el laberinto utilizando arreglos bidimensionales,
            // donde las paredes se representan con 1s, los espacios con 0s,
            // la salida con un 2 y la llegada con un 3.

            case 3:{
            	Ejercicio3();
				break;
			}

            case 0:{
            	cout << "Saliendo del programa...";
				break;
			}

            default:{
            	cout << "Opcion invalida. Intente nuevamente." << endl;
				break;
			}
        }
    } while(opcion != 0);

    return 0;
}




