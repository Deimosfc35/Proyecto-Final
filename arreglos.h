#ifndef ARREGLOS_H
#define ARREGLOS_H
#include <string>

using namespace std;

/// ==============Ejercicio 1 ==============



// ==============Ejercicio 2 ==============



// ==============Ejercicio 3 ==============

const int FILAS = 10;
const int COLUMNAS = 10;

const int CAMINO = 0;
const int PARED = 1;
const int INICIO = 2; 
const int META = 3;   
const int RUTA_OPTIMA = 8; 

extern int padreX[FILAS][COLUMNAS];
extern int padreY[FILAS][COLUMNAS];
extern int g[FILAS][COLUMNAS]; 
extern int f[FILAS][COLUMNAS]; 
extern bool listaAbierta[FILAS][COLUMNAS];
extern bool listaCerrada[FILAS][COLUMNAS];

void inicializarMatrices(int xInicio, int yInicio, int xMeta, int yMeta);
void marcarCaminoRecursivo(int laberinto[FILAS][COLUMNAS], int currX, int currY, int xInicio, int yInicio, int xMeta, int yMeta);
void imprimirLaberinto(int mapa[FILAS][COLUMNAS]);
bool resolverLaberintoAEstrella(int laberinto[FILAS][COLUMNAS], int xInicio, int yInicio, int xMeta, int yMeta);

#endif
