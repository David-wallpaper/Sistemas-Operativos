#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "modulo.h"
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

//Funcion principal del programa que llama a la intefaz modulo.h
 int main(int argc, char *argv[]) {

	//Funcion de modulo.h que valida el numero de argumentos de entrada
	funcIngreso(argc);

	//Variables iniciales
    double **matrixA; //Sumando
    double **matrixB; //Sumando
    double **matrixC; // Resultado
    int N = (int)atoi(argv[1]); // Castear a entero el segundo argumento de entrada
	
	//Reserva de memoria
matrixA = (double **)malloc(N*sizeof(double *));
matrixB = (double **)malloc(N*sizeof(double *));
matrixC = (double **)malloc(N*sizeof(double *));
    for(int i=0; i<N;i++) {
        matrixA[i] = (double *)malloc(N*sizeof(double));
		matrixB[i] = (double *)malloc(N*sizeof(double));
		matrixC[i] = (double *)malloc(N*sizeof(double));
}

//Inicializacion de las matrices
iniMatrix(matrixA,N);
iniMatrix(matrixB,N);



	//Imprimir matrices
	 imprimirMatrix(matrixA,N);
	 imprimirMatrix(matrixB,N);

	//Suma de matrices A+B=C
	sumarMatrix(matrixA,matrixB,matrixC,N);

	imprimirMatrix(matrixC,N);
	//Liberar espacio en memoria

    for(int i=0; i<N;i++) {
    free(matrixA[i]);
	free(matrixB[i]);
	free(matrixC[i]);
} 
    free(matrixA);
    free(matrixB);
    free(matrixC);
    return 0;
}

