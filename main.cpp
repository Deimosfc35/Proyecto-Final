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



// ==============Ejercicio 2 ==============

int matriz[MAX][MAX];
    int transpuesta[MAX][MAX];

    int filas, columnas;

    cout << "Ingrese filas: ";
    cin >> filas;

    cout << "Ingrese columnas: ";
    cin >> columnas;

    cout << "\nIngrese la matriz(Por filas):\n";

    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            cin >> matriz[i][j];
        }
    }

    cout << "\nMaximo: " << elementoMax(matriz, filas, columnas);

    cout << "\nMinimo: " << elementoMin(matriz, filas, columnas);

    int traza = calcularTraza(matriz, filas, columnas);

    if(traza != -1) cout << "\nTraza: " << traza;
    
    else cout << "\nLa matriz no es cuadrada";

    matrizTranspuesta(matriz, transpuesta, filas, columnas);

    cout << "\n\nMatriz transpuesta:\n";

    for(int i = 0; i < columnas; i++){
        for(int j = 0; j < filas; j++){
            cout << transpuesta[i][j] << " ";
        }
        cout << endl;
    }

    if(esSimetrica(matriz, filas, columnas))
        cout << "\nEs simetrica";
    else
        cout << "\nNo es simetrica";


// Ejercicio 3

	string textoFrase = "El primer hombre en pisar la luna fue Neil Amstrong";
    string resultadoSiglas = obtenerSiglas(textoFrase);
    
    
    cout << "\nTexto original: " << textoFrase << endl;
    cout << "Resultado:      " << resultadoSiglas << endl;
    cout << "--------------------------------------------------" << endl << endl;


    
    string textoNumero = "-9876";
    int numeroConvertido = stringAInt(textoNumero);
    
   
    cout << "Texto original:  \"" << textoNumero << "\"" << endl;
    cout << "Como entero:     " << numeroConvertido << endl;



    string textoEstructura = "estructura de datos";
    char masRepetido = caracterMasRepetido(textoEstructura);
    
    
    cout << "Texto analizado: \"" << textoEstructura << "\"" << endl;
    cout << "Letra mas comun: '" << masRepetido << "'" << endl;
    

    return 0;
}




