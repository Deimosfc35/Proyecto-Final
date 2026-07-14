#include <iostream>
#include "arreglos.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

int main() {

// ==============Ejercicio 1 ==============

// Investigue el funcionamiento del algoritmo de una Red Neuronal.
// Implemente una red neuronal que sea capaz de predecir el valor de Y
// recibiendo una entrada X.
cout << "---Ejercicio Red Neuronal---" << endl;
    float x[5]={0,1,2,3,4};
    float y[5]={1,3,5,7,9};

    float w0=1.0;
    float b=0.0;

    float alpha=0.01;

    int epocas=1000;

    for(int e=0;e<epocas;e++)
    {
        for(int i=0;i<5;i++)
        {
            float yp = prediccion(w0,b,x[i]);

            float error = yp-y[i];

            float grad_w0 = 2*error*x[i];

            float grad_b = 2*error;

            w0 -= alpha*grad_w0;

            b -= alpha*grad_b;
        }

        if(e%100==0)
        {
            cout<<"Epoca "<<e
                <<" W="<<w0
                <<" b="<<b
                <<" MSE="<<calcularError(x,y,5,w0,b)
                <<endl;
        }
    }

    cout<<"\nModelo entrenado"<<endl;
    cout<<"Peso = "<<w0<<endl;
    cout<<"Bias = "<<b<<endl;

cout << "\n===== RESULTADOS FINALES =====" << endl;
cout << "X\tY Esperado\tY Predicho" << endl;

for(int i = 0; i < 5; i++){
    float y_pred = prediccion(w0, b, x[i]);

    cout << x[i] << "\t"
         << y[i] << "\t\t"
         << y_pred << endl;
}

// ==============Ejercicio 2 ==============

// Realice un algoritmo que permita resolver sistemas de ecuaciones lineales.


// ==============Ejercicio 3 ==============

// Genere un algoritmo para resolver laberintos. Representa el laberinto
// utilizando arreglos bidimensionales, donde las paredes se deben
// representar con 1s, los espacios con 0s, la salida con un 2 y la llegada con un 3.

	
    return 0;
}




