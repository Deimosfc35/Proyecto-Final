#include <iostream>
#include "arreglos.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

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

// ==============Ejercicio 3 ==============
