#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*************************************

* - INTERFAZ DE FUNCIONES
**************************************/
#ifndef __MODULOH__
#define __MODULO_H__

        //Funcion de ingreso de valores y tamano de matiz
void funcIngreso(int entrada);


void iniMatrix(double ** mat, int dim);


void imprimirMatrix(double **mat, int dim);
void sumarMatrix(double **mA, double **mB, double **mC, int dim);

#endif
