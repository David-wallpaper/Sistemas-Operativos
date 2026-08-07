#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "modulo.h" // interfaz artesanal
/*************************************
*Pontificia universidad javeriana
* Autor: David Vallejo
*Fecha: 29 de julio de 2025
*Materia: Sistemas operativos
*Fichero: Principal
*Objetivos:
* - Implementar en funciones la función principal
* - Implementear una función de suma de matrices
* - Implementar un fichero de interfaz de funciones
* - Crear un ficherp de Automatización de Compilación
* - Docummentar y anunciar las instrucciones significativas
* - Comprimir todo y enviarlo asignación
**************************************/


        //Funcion de ingreso de valores y tamano de matiz
void funcIngreso(int entrada) {
        if(entrada !=2) {
        printf("\n Use: \n\n\t $ejecutable valor\n\n");
        exit(0);
	}
}

void iniMatrix(double ** mat, int dim) {

        srand(time(NULL));
        for(int i=0; i<dim; i++)
         for(int j=0; j<dim;j++)

        mat[i][j] = (double)rand()/RAND_MAX*(10.0-1.0);
}

void imprimirMatrix(double **mat, int dim) {
if(dim<=10 && dim>-1) {
for(int i=0; i<dim; i++) {

          for(int j=0; j<dim;j++) {
        printf(" %f ", mat[i][j]);
        }
        printf("\n");
	
	}
	printf("\n========================\n");
} else {
	printf("\nMatriz no válida\n");
}

}

 void sumarMatrix(double **mA, double **mB, double **mC, int dim) {
	for(int i=0; i<dim;i++) {
	for(int j=0;j<dim;j++) {

	     mC[i][j]=mA[i][j]+mB[i][j];

		}
	}

}


