#include <iostream>
#include "proyecto.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

// ==============Ejercicio 3 ==============

int padreX[FILAS][COLUMNAS];
int padreY[FILAS][COLUMNAS];
int g[FILAS][COLUMNAS]; 
int f[FILAS][COLUMNAS]; 
bool listaAbierta[FILAS][COLUMNAS];
bool listaCerrada[FILAS][COLUMNAS];

void Ejercicio3() {
    int laberinto[FILAS][COLUMNAS] = {
        {2, 0, 1, 0, 0, 1, 1, 1, 1, 1},
        {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 0, 1, 1, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 0, 0, 1},
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
        return;
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
}

void imprimirLaberinto(int mapa[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (mapa[i][j] == PARED)
                cout << "[]";
            else if (mapa[i][j] == CAMINO)
                cout << "  ";
            else if (mapa[i][j] == INICIO)
                cout << " O"; 
            else if (mapa[i][j] == META)
                cout << " X"; 
            else if (mapa[i][j] == RUTA_OPTIMA)
                cout << " *"; 
        }
        cout << endl; 
    }
}

void inicializarMatrices(int xInicio, int yInicio, int xMeta, int yMeta) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            g[i][j] = 99999; 
            f[i][j] = 99999;
            padreX[i][j] = -1;
            padreY[i][j] = -1;
            listaAbierta[i][j] = false;
            listaCerrada[i][j] = false;
        }
    }
    int diffX = xInicio - xMeta;
    int diffY = yInicio - yMeta;
    int manhattanInicio = ((diffX < 0) ? -diffX : diffX) + ((diffY < 0) ? -diffY : diffY);

    g[xInicio][yInicio] = 0;
    f[xInicio][yInicio] = manhattanInicio;
    listaAbierta[xInicio][yInicio] = true;
}


bool resolverLaberintoAEstrella(int laberinto[FILAS][COLUMNAS], int xInicio, int yInicio, int xMeta, int yMeta) {
    inicializarMatrices(xInicio, yInicio, xMeta, yMeta);

    while (true) {
        int menorF = 99999;
        int xActual = -1, yActual = -1;

        for (int i = 0; i < FILAS; i++) {
            for (int j = 0; j < COLUMNAS; j++) {
                if (listaAbierta[i][j] && f[i][j] < menorF) {
                    menorF = f[i][j];
                    xActual = i;
                    yActual = j;
                }
            }
        }

        if (xActual == -1) return false; 
        if (xActual == xMeta && yActual == yMeta) return true; 

        listaAbierta[xActual][yActual] = false;
        listaCerrada[xActual][yActual] = true;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int nX = xActual + dx[i];
            int nY = yActual + dy[i];

            if (nX >= 0 && nX < FILAS && nY >= 0 && nY < COLUMNAS && laberinto[nX][nY] != PARED && !listaCerrada[nX][nY]) {
                int nuevoG = g[xActual][yActual] + 1;

                if (nuevoG < g[nX][nY]) {
                    padreX[nX][nY] = xActual;
                    padreY[nX][nY] = yActual;
                    g[nX][nY] = nuevoG;

                    int dX = nX - xMeta;
                    int dY = nY - yMeta;
                    int manhattanVecino = ((dX < 0) ? -dX : dX) + ((dY < 0) ? -dY : dY);

                    f[nX][nY] = nuevoG + manhattanVecino;
                    listaAbierta[nX][nY] = true;
                }
            }
        }
    }
}

void marcarCaminoRecursivo(int laberinto[FILAS][COLUMNAS], int currX, int currY, int xInicio, int yInicio, int xMeta, int yMeta) {
    if (currX == -1 || currY == -1) return;

    marcarCaminoRecursivo(laberinto, padreX[currX][currY], padreY[currX][currY], xInicio, yInicio, xMeta, yMeta);

    if (laberinto[currX][currY] != INICIO && laberinto[currX][currY] != META) {
        laberinto[currX][currY] = RUTA_OPTIMA;
    }
}
