#include <iostream>
#include "arreglos.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

// ==============Ejercicio 1 ==============
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



// ==============Ejercicio 3 ==============



