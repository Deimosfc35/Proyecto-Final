#include <iostream>
#include "arreglos.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

int main() {

// ==============Ejercicio 1 ==============

// Investigue el funcionamiento del algoritmo de una Red Neuronal.
// Implemente una red neuronal que sea capaz de predecir el valor de Y
// recibiendo una entrada X


// ==============Ejercicio 2 ==============

// Realice un algoritmo que permita resolver sistemas de ecuaciones lineales.


// ==============Ejercicio 3 ==============

// Genere un algoritmo para resolver laberintos. Representa el laberinto
// utilizando arreglos bidimensionales.



int laberinto[FILAS][COLUMNAS] = {
        {2, 0, 1, 0, 0, 0, 1, 1, 1, 1},
        {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
        {1, 1, 1, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 1, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 1, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 1, 1},
        {1, 1, 1, 0, 1, 1, 1, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 3}
    };

    int xInicio = -1, yInicio = -1, xMeta = -1, yMeta = -1;

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (laberinto[i][j] == INICIO) { xInicio = i; yInicio = j; }
            if (laberinto[i][j] == META) { xMeta = i; yMeta = j; }
        }
    }

    if (xInicio == -1 || xMeta == -1) {
        cout << "Error: Falta el punto de inicio (2) o meta (3) en la matriz." << endl;
        return 1;
    }

    cout << "--- LABERINTO ORIGINAL ---" << endl;
    imprimirLaberinto(laberinto);


    if (resolverLaberintoAEstrella(laberinto, xInicio, yInicio, xMeta, yMeta)) {
        cout << "--- CAMINO MAS OPTIMO ENCONTRADO ---" << endl;
        marcarCaminoRecursivo(laberinto, xMeta, yMeta, xInicio, yInicio, xMeta, yMeta);
        imprimirLaberinto(laberinto);
    } else {
        cout << "No existe un camino valido para resolver este laberinto." << endl;
    }

    return 0;
}




