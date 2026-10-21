/*#############################################
 Pontificia Universidad Javeriana
 Autor: David vallejo
 Fecha: 21 de octubre de 2026
 Tema: ejercicio de POSIX
###############################################*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int arg, char * argv[]) {

	int procesoID = fork();
	if(procesoID>0) {

	 printf("El fork() valor de ID proceso padre =%d", getpid());


	} else if(procesoID==0) {

	 printf("El fork() valor de ID proceso hijo =%d\n",getpid());
	 printf("El proceso padre tiene el id = %d\n", getpid());
	} else {

	 printf("La funcion fork devuelve valor NEGATIVO=ERROR al invocar\n");

	}
	printf("En caso de exito, este mensaje se duplica para el \n");
	printf("PROCESO PADRE como para el PROCESO HIJO \n");


return 0;
}
