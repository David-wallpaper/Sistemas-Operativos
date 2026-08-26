/*************************************************************************************************
 *
 *   - INTERFAZ DE FUNCIONES
 *
*************************************************************************************************/

#ifndef __MODULO_H__
#define __MODULO_H__

//Funcion para ingreso de valores y tamaño de matriz
void funcIngreso(int entrada);

//Funcion para inicializar matriz aleatoria 1.0 y 10.0
void iniMatrix(double *mat, int dim);

//Funcion imprimir matriz
void impMatrix(double *mat, int dim);

//Funcion suma de matrices C = A + B
void sumaMatrix(double *matA, double *matB, double *matC, int dim);

#endif
