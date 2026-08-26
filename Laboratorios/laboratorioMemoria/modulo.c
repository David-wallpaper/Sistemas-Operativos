/*************************************************************************************************
 * Pontificia Universidad Javeriana
 *
 * Autor: David Vallejo
 * Fecha: 26 de Agosto 2026
 * Materia: Sistemas Operativos
 * Tema: laboratorio Memoria
 * Objetivos:
 *   -Implementar en funcionas la funcion principal
 *   - Implementar una funcion: suma de matrices
 *   - Implementar un fichero de funciones
 *   - Implementar un ficher de iterfaz de funciones
 *   - Crear un fichero de Automtizacion de Compilacion
 *   - Documentar y anunciar las instrucciones significativas
 *   - Comprimir todo y enviarlo a asignacion
 *
 * Fichero: funciones
*************************************************************************************************/

#include <stdio.h>   //Interfaz de Input Output
#include <stdlib.h>
#include <time.h>
#include "modulo.h"  //Interfaz Artesanal

//Funcion para ingreso de valores y tamaño de matriz
void funcIngreso(int entrada){
    if(entrada != 2){
	printf("\n Use: \n\n\t $ejecutable valor \n\n");
	exit(0);
    }
}

//Funcion para inicializar matriz aleatoria 1.0 y 10.0
void iniMatrix(double *mat, int dim){
    srand(time(NULL));                          //Se crea semilla para aleatoriedad
    for(int i=0; i<dim;i++)                     //Recorrido por el vector dim*dim
     	 mat[i]= (double)rand()/RAND_MAX*(10.0-1.0);
}

//Funcion imprimir matriz
void impMatrix(double *mat, int dim){
     if(dim < 12){
	 for(int i=0; i<dim;i++){                   //Recorrido por todo el vector
		printf(" %f ", mat[i]);
		if((i + 1) % dim == 0) printf("\n");
	 }
	 printf("=================================== \n");
     }
}

//Funcion suma de matrices C = A + B
void sumaMatrix(double *matA, double *matB, double *matC, int dim){
	for(int i=0; i<dim; i++)               //Recorrido por vector
	 matC[i]=matA[i]+matB[i];

}