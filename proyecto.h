#ifndef PROYECTO_H
#define PROYECTO_H
#include <string>

using namespace std;

/// ==============Ejercicio 1 ==============
void Ejercicio1();
float activacion(float x);
float prediccion(float w0,float b,float x);
float calcularError(float x[], float y[], int n, float w0, float b);

// ==============Ejercicio 2 ==============

void Ejercicio2();
void mostrarIncognita(int j, int n);
void ingresarEcuaciones(float matriz[][11], int n);
void mostrarSistema(float matriz[][11], int n);
void obtenerSubMatriz(float matriz[][11], float subMatriz[][11], int filaOmitida, int columnaOmitida, int n);
float calDeterminante(float matriz[][11], int n);
void cambiarColumna(float matriz[][11], float matrizDestino[][11], float columnaNueva[], int colACambiar, int n);

// ==============Ejercicio 3 ==============

void Ejercicio3();

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
