/*
##################################################

# Pontificia Universidad Javeriana
# Autor: David Vallejo
# fecha: 21 de octubre de 2026
# Asunto: segundo ejercicio de POSIX
#################################################
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char * argcv[]) {

	int processID= fork();


	if(processID>0) {

	printf("\n 'proceso padre' .... \n");


	} else if(processID==0) {

	 printf("\n 'proceso hijo' recien creado \n");

	} else {

	printf("\n llamada al sistema fork() fallo\n");

	}

	printf("\n\n Imprimiendo ... \n");

	for(int i=0;i<5;i++) {

	printf(" %d ", i);
	}

	printf("\n Fin \n");


return 0;
}
