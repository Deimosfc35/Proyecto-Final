#ifndef ARREGLOS_H
#define ARREGLOS__H
#include <string>

int sumaArreglo(int arr[], int n);
int maximo(int arr[], int n);
int minimo(int arr[], int n);

float media(int arr[], int n);
float varianza(int arr[], int n);
float raizCuadrada(float x);
float desviacionEstandar(int arr[], int n);
float curtosis(int arr[], int n);

void imprimirArreglo(int arr[], int n);


// Ejercicio 3
std::string obtenerSiglas(const std::string& texto);
int stringAInt(const std::string& texto);
char caracterMasRepetido(const std::string& texto);

#endif
