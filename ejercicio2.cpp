#include <iostream>
#include "proyecto.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

// ==============Ejercicio 2 ==============

void Ejercicio2(){
	
	int n;
    float matriz[10][11];
    float terminosIndependientes[10];
    float matrizTemporal[10][11];

    
    cout << "   RESOLUCION DE SISTEMAS (METODO CRAMER)  " << endl;
  
    cout << "Ingrese el numero de incognitas (maximo 10): ";
    cin >> n;

    if (n <= 0 || n > 10) {
        cout << "[Error] Dimension invalida." << endl;
    }

    ingresarEcuaciones(matriz, n);
    
    for(int i = 0; i < n; i++) {
        terminosIndependientes[i] = matriz[i][n];
    }

    cout << "\n--- SISTEMA INGRESADO ---" << endl;
    mostrarSistema(matriz, n);
    
    float detPrincipal = calDeterminante(matriz, n);

    cout << "\n--- RESULTADO ---" << endl;
    if (detPrincipal == 0) {
        
        cout << "El determinante principal es 0." << endl;
        cout << "El sistema no tiene solucion unica (puede tener infinitas o ninguna)." << endl;
    } else {
        cout << "Soluciones del sistema:" << endl;
        
        for (int j = 0; j < n; j++) {
           
            cambiarColumna(matriz, matrizTemporal, terminosIndependientes, j, n);
            
            float detVariable = calDeterminante(matrizTemporal, n);
            
            mostrarIncognita(j, n);
            cout << " = " << (detVariable / detPrincipal) << endl;
        }
    }

}
	

void mostrarIncognita(int j, int n){
	if(n <= 3){
		if(j == 0) cout << "x";
		else if(j == 1) cout << "y";
		else cout << "z";
		
	}else {
		cout << "x" << (j + 1);
	}
}

void ingresarEcuaciones(float matriz[][11], int n){
	int i, j;
	for(i= 0; i < n; i++){
		cout << "Ecuacion " << i + 1 << endl;
		
		for(int j = 0; j < n; j++){
			cout << "Coeficiente de ";
			mostrarIncognita(j, n);
			cout << ": ";
			cin >> matriz[i][j];
		}
		
		cout << "Resultado: ";
		cin >> matriz[i][n];
		cout << endl;
	}
}

void mostrarSistema(float matriz[][11], int n){
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(j > 0){
				if(matriz[i][j] >= 0) cout << " + ";
				else cout << " - ";
				
				if(matriz[i][j] < 0) cout << -matriz[i][j];
				else cout << matriz[i][j];
			}else {
				cout << matriz[i][j];
			}
			
			mostrarIncognita(j, n);
		}
		
		cout << " = " << matriz[i][j] << endl;
	}	
}

void obtenerSubMatriz(float matriz[][11], float subMatriz[][11], int filaOmitida, int columnaOmitida, int n){
	int subFila = 0;
	for(int i = 0; i < n; i++){
		if (i == filaOmitida) continue;
		
		int subColumna = 0;
		for(int j = 0; j < n; j ++){
			if(j == columnaOmitida) continue;
			
			subMatriz[subFila][subColumna] = matriz[i][j];
			subColumna++;
		}
		
		subFila++;
	}		
}

float calDeterminante(float matriz[][11], int n) {
    if (n == 1) {
        return matriz[0][0];
    }
    
    if (n == 2) {
        return (matriz[0][0] * matriz[1][1]) - (matriz[0][1] * matriz[1][0]);
    }

    float det = 0;
    float submatriz[10][11];
    int signo = 1;
    int j = 0; // Declaramos 'j' de forma segura

    for (j = 0; j < n; j++) {
        obtenerSubMatriz(matriz, submatriz, 0, j, n);
        
        det += signo * matriz[0][j] * calDeterminante(submatriz, n - 1);
        signo = -signo; 
    }

    return det;
}

void cambiarColumna(float matriz[][11], float matrizDestino[][11], float columnaNueva[], int colACambiar, int n){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == colACambiar) {
                matrizDestino[i][j] = columnaNueva[i];
            } else {
                matrizDestino[i][j] = matriz[i][j];
            }
        }
    }
}
