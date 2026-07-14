#include <iostream>
#include "arreglos.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

// ==============Ejercicio 1 ==============

void Ejercicio1() {
    cout << "---Ejercicio Red Neuronal---" << endl;
    float x[5] = {0, 1, 2, 3, 4};
    float y[5] = {1, 3, 5, 7, 9};

    float w0 = 1.0;
    float b = 0.0;

    float alpha = 0.01;

    int epocas = 1000;

    for(int e = 0; e < epocas; e++) {
        for(int i = 0; i < 5; i++) {
            float yp = prediccion(w0, b, x[i]);

            float error = yp - y[i];

            float grad_w0 = 2 * error * x[i];

            float grad_b = 2 * error;

            w0 -= alpha * grad_w0;

            b -= alpha * grad_b;
        }

        if(e % 100 == 0) {
            cout << "Epoca " << e
                 << " W=" << w0
                 << " b=" << b
                 << " MSE=" << calcularError(x, y, 5, w0, b)
                 << endl;
        }
    }

    cout << "\nModelo entrenado" << endl;
    cout << "Peso = " << w0 << endl;
    cout << "Bias = " << b << endl;

    cout << "\n===== RESULTADOS FINALES =====" << endl;
    cout << "X\tY Esperado\tY Predicho" << endl;

    for(int i = 0; i < 5; i++) {
        float y_pred = prediccion(w0, b, x[i]);

        cout << x[i] << "\t"
             << y[i] << "\t\t"
             << y_pred << endl;
    }
}


float activacion(float x){
    return x;
}

float prediccion(float w0,float b,float x){
    return activacion(w0*x+b);
}

float calcularError(float x[], float y[], int n, float w0, float b){
    float mse = 0;

    for(int i=0;i<n;i++){
        float yp = prediccion(w0,b,x[i]);

        mse += (yp-y[i])*(yp-y[i]);
    }

    return mse/n;

}

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

// ==============Ejercicio 3 ==============

int padreX[FILAS][COLUMNAS];
int padreY[FILAS][COLUMNAS];
int g[FILAS][COLUMNAS]; 
int f[FILAS][COLUMNAS]; 
bool listaAbierta[FILAS][COLUMNAS];
bool listaCerrada[FILAS][COLUMNAS];

void Ejercicio3() {
    int laberinto[FILAS][COLUMNAS] = {
        {2, 0, 1, 0, 0, 0, 1, 1, 1, 1},
        {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
        {1, 1, 1, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 1, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 0, 0, 1},
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
        return; // Cambiado de 'return 1;' a 'return;' por ser una función void
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


