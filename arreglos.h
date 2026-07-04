#ifndef ARREGLOS_H
#define ARREGLOS__H
#include <string>

using namespace std;

// Ejercicio 1

int sumaArreglo(int arr[], int n);
int maximo(int arr[], int n);
int minimo(int arr[], int n);

float media(int arr[], int n);
float varianza(int arr[], int n);
float raizCuadrada(float x);
float desviacionEstandar(int arr[], int n);
float curtosis(int arr[], int n);

void imprimirArreglo(int arr[], int n);

// Ejercicio 2

const int MAX = 100;
int elementoMax(int matriz[MAX][MAX], int filas, int columnas);
int elementoMin(int matriz[MAX][MAX], int filas, int columnas);
int calcularTraza(int matriz[MAX][MAX], int filas, int columnas);
void matrizTranspuesta(int matriz[MAX][MAX], int transpuesta[MAX][MAX], int filas, int columnas);
bool esSimetrica(int matriz[MAX][MAX], int filas, int columnas);

// Ejercicio 3

string obtenerSiglas(const string& texto);
int stringAInt(const string& texto);
char caracterMasRepetido(const string& texto);

#endif
