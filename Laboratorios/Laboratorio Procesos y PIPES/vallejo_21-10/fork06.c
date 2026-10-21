/*
##################################################

# Pontificia Universidad Javeriana
# Autor: David Vallejo
# fecha: 21 de octubre de 2026
# Asunto: sexto ejercicio de POSIX (comunicar entre procesos fork), (Padre envia mensaje al hijo)
#################################################
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int arg, char * argcv[]) {

	int pipeComunication[2]; //Tuberia comunicacion IN: 0, OUT: 1
	pid_t phijo_PID;	 //Identidad de proceso hijo


	if(pipe(pipeComunication)== -1) { // Caso de error creacion pipe

	perror("FALLO DE CREACION DE TUBERIA(pipeComunication)\n");
	exit(EXIT_FAILURE);

	}

	phijo_PID=fork(); // Creacion de proceso hijo y padre

	if(phijo_PID== -1) { // Error de creacion de procesos

	perror("FALLO DE CREACION DE PROCESOS (fork())\n");
	exit(EXIT_FAILURE);

	}

	if(phijo_PID == 0) {	//Proceso hijo

	close(pipeComunication[1]); //Cierre salida para escribir (PIPE)
	
	char mensaje[100];	//captura del mensaje completo (MAX 100 letras)
	int lectura;		//captura cantidad de letras del mensaje
	lectura = read(pipeComunication[0], mensaje, sizeof(mensaje));

	if(lectura==-1) {
	
	perror("FALLO EN LECTURA DE MENSAJE\n");
	exit(EXIT_FAILURE);

	 }

	printf("Proceso hijo recibe mensaje del padre\n");
	printf("MENSAJE: %.*s\n",lectura, mensaje);
	
	close(pipeComunication[0]); // Cierre entrada para leer (PIPE)

	} else {	//Ya esta en proceso padre

	close(pipeComunication[0]);	//Cierre de entrada para escribir (PIPE)
	char mensajePadre[]= "HOLA HIJO, SALUDOS";		//Vector para escribir mensaje maximo 100 letras
	
	int escritura;			//Cantidad de letras del mensaje a enviar por el padre

	escritura = write(pipeComunication[1], mensajePadre, strlen(mensajePadre));

	if(escritura == -1) {

	perror("FALLO en escritura de mensaje\n");
	exit(EXIT_FAILURE);
 	 }
	
	close(pipeComunication[1]); // Cierre salida para escritura (PIPE)

	}
	printf("\nFIN\n");

 return 0;
}

