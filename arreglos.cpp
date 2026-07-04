#include <iostream>
#include "arreglos.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
// ==============Ejercicio 1 ==============

int sumaArreglo(int arr[], int n){
	int suma = 0;
	for (int i =0; i < n; suma += arr[i++]);
	return suma;
}

int maximo (int arr[], int n){
	int max= arr[0];
	for (int i =1; i<n ;i++){
		if (arr[i] > max){
			max = arr[i];
		}
		#ifdef DEBUG
			printf("Maximo: %d\n", max);
		#endif
	}
	return max;
}

int minimo (int arr[], int n){
	int min= arr[0];
	for (int i =1; i<n ;i++){
		if (arr[i] < min){
			min = arr[i];
		}
		#ifdef DEBUG
			printf("Minimo: %d\n", min);
		#endif
	}
	return min;
}

float media(int arr[], int n){
    float suma = 0;

    for(int i = 0; i < n; i++){
        suma += arr[i];
    }

    return suma / n;
}

float varianza(int arr[], int n){
    float prom = media(arr, n);
    float suma = 0;
    float dif;

    for(int i = 0; i < n; i++){
        dif = arr[i] - prom;
        suma += dif * dif;
    }

    return suma / n;
}

float raizCuadrada(float x){
    float r = x;

    if(x == 0)
        return 0;

    for(int i = 0; i < 20; i++){
        r = (r + x / r) / 2;
    }

    return r;
}

float desviacionEstandar(int arr[], int n){
    return raizCuadrada(varianza(arr, n));
}

float curtosis(int arr[], int n){
    float prom = media(arr, n);
    float desv = desviacionEstandar(arr, n);
    float suma = 0;
    float z;

    for(int i = 0; i < n; i++){
        z = (arr[i] - prom) / desv;
        suma += z * z * z * z;
    }

    return (suma / n) - 3;
}

void imprimirArreglo(int arr[], int n){
	for(int i =0; i < n; i++){
		printf("%d, ", arr [i]);
	}
	printf("\n");
}

// ==============Ejercicio 2 ==============

int elementoMax(int matriz[MAX][MAX], int filas, int columnas){
    int max = matriz[0][0];

    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            if(matriz[i][j] > max) max = matriz[i][j];
        }
    }

    return max;
}

int elementoMin(int matriz[MAX][MAX], int filas, int columnas){
	
    int min = matriz[0][0];

    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
        	
            if(matriz[i][j] < min) min = matriz[i][j];
        }
    }

    return min;
}

int calcularTraza(int matriz[MAX][MAX], int filas, int columnas){
    if(filas != columnas)
        return -1;

    int suma = 0;

    for(int i = 0; i < filas; i++){
    	
        suma += matriz[i][i];    
    }

    return suma;
}

void matrizTranspuesta(int matriz[MAX][MAX], int transpuesta[MAX][MAX], int filas, int columnas){
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
        	
            transpuesta[j][i] = matriz[i][j];
        }
    }
}

bool esSimetrica(int matriz[MAX][MAX], int filas, int columnas){
    if(filas != columnas)
        return false;

    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            if(matriz[i][j] != matriz[j][i])
                return false;
        }
    }

    return true;
}

// ==============Ejercicio 3 ==============


string obtenerSiglas(const string& texto){
    string resultado = "";

    for(int i = 0; i < texto.length(); i++){
        if(texto[i] != ' '){

            if(i == 0 || texto[i - 1] == ' '){

                if(!resultado.empty()){
                    resultado += ".";
                }

                resultado += texto[i];
            }
        }
    }

    return resultado;
}

int stringAInt(const string& texto){
    int resultado = 0;
    int signo = 1;
    int inicio = 0;

    if(texto.empty())
        return 0;

    if(texto[0] == '-'){
        signo = -1;
        inicio = 1;
    }
    else if(texto[0] == '+'){
        inicio = 1;
    }

    for(int i = inicio; i < texto.length(); i++){
        if(texto[i] >= '0' && texto[i] <= '9'){
            resultado = resultado * 10 + (texto[i] - '0');
        }
        else{
            break;
        }
    }

    return resultado * signo;
}

char caracterMasRepetido(const string& texto){

    int frecuencias[256] = {0};

    for(int i = 0; i < texto.length(); i++){
        if(texto[i] != ' '){
            unsigned char indice = texto[i];
            frecuencias[indice]++;
        }
    }

    int maxFrecuencia = 0;
    char masRepetido = ' ';

    for(int i = 0; i < 256; i++){
        if(frecuencias[i] > maxFrecuencia){
            maxFrecuencia = frecuencias[i];
            masRepetido = (char)i;
        }
    }

    return masRepetido;
}
