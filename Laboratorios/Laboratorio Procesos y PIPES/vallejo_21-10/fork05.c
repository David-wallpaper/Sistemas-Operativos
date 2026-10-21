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

int main(int arg, char * argcv[]) {

	int procesoID = fork();

	if(procesoID>0) {

	printf("\nPROCESO PADRE ... \n\n");
	for(int i=1; i<=10; i++) {
	printf("%d",i);
	
	}

	} else if(procesoID== 0) {

	printf("\nPROCESO HIJO ...... \n\n");
        printf("\n\n Se imprime ...\n");
        for(int i=10;  i>=1; i--) {

        printf("%d",i);
                }

	} else {

	printf("La funcion FORK devuelve VALOR NEGATIVO= ERROR ERROR \n");

	}

	printf("\nFIN\n");

 return 0;
}

