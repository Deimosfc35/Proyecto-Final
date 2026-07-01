#include <iostream>
//======================
#include "arreglos.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

int main() {

// ==============Ejercicio 1 ==============

int n;
int arr[n];
cout << "Ingrese el tamanio del arreglo(para un calculo rapido se recomienda un numer entre 5-10): " << endl;
cin >> n;

cout << "Ingrese los elementos del arreglo:" << endl;
    for(int i = 0; i < n; i++){
        cout << "Elemento [" << i << "]: ";
        cin >> arr[i];
    }

    cout << "Arreglo: " << endl;
    imprimirArreglo(arr, n);
 
    cout << "Media: " << media(arr, n) << endl;
    cout << "Desviacion estandar: " << desviacionEstandar(arr, n) << endl;
    cout << "Varianza: " << varianza(arr, n) << endl;
    cout << "Curtosis: " << curtosis(arr, n) << endl;
    cout << "Maximo: " << maximo(arr, n) << endl;
    cout << "Minimo: " << minimo(arr, n) << endl;

    return 0;

// ==============Ejercicio 2 ==============
    
}




