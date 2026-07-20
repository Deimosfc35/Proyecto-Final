#include <iostream>
#include "proyecto.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

// ==============Ejercicio 1 ==============

void Ejercicio1() {

    cout << "---Ejercicio Red Neuronal---" << endl;

    int n;

    cout << "Ingrese la cantidad de datos de entrenamiento: ";
    cin >> n;

    float *x = new float[n];
    float *y = new float[n];

    cout << "\nIngrese los pares (X,Y)" << endl;

    for(int i = 0; i < n; i++) {

        cout << "\nDato " << i + 1 << endl;

        cout << "X: ";
        cin >> x[i];

        cout << "Y: ";
        cin >> y[i];
    }

    float w0 = 1.0;
    float b = 0.0;
    float alpha = 0.01;
    int epocas = 1000;

    for(int e = 0; e < epocas; e++) {

        for(int i = 0; i < n; i++) {

            float yp = prediccion(w0, b, x[i]);
            float error = yp - y[i];
            float grad_w0 = 2 * error * x[i];
            float grad_b = 2 * error;

            w0 -= alpha * grad_w0;
            b -= alpha * grad_b;
        }

        if(e % 100 == 0) {

            cout << "======== Epoca " << e << " ========" << endl;
            cout << "W = " << w0 << endl;
            cout << "b = " << b << endl;
            cout << "MSE = " << calcularError(x, y, n, w0, b) << endl;
            cout << "============================" << endl;
            cout << endl;
        }
    }

    cout << "\n=========== MODELO ENTRENADO ===========" << endl;
    cout << "Peso (W): " << w0 << endl;
    cout << "Bias (b): " << b << endl;
    cout << "\n=========== RESULTADOS FINALES ===========" << endl;
    cout << "X\tY Esperado\tY Predicho" << endl;


    for(int i = 0; i < n; i++) {

        float y_pred = prediccion(w0, b, x[i]);

        cout << x[i] << "\t";
		cout << y[i] << "\t\t";
		cout << y_pred << endl;
    }

    delete[] x;
    delete[] y;

}

float activacion(float x) {
	
    return x;
    
}


float prediccion(float w0, float b, float x) {

    return activacion(w0 * x + b);

}

float calcularError(float x[], float y[], int n, float w0, float b) {

    float mse = 0;

    for(int i = 0; i < n; i++) {
        float yp = prediccion(w0, b, x[i]);
        mse += (yp - y[i]) * (yp - y[i]);
    }
    return mse / n;

}


