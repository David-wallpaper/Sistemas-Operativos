/*#############################################
 Pontificia Universidad Javeriana
 Autor: David vallejo
 Fecha: 28 de octubre de 2026
 Tema: ejercicio de named pipe FIFO
###############################################*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define FIFO_FILE "MYFIFO"



int main() {
    int fd;
    int fin_proceso;
    int tamMensaje;
    char leerbuf[80];
    char fin_men[5];


    printf("CLIENTE_FIFO: Mensajes recibidos, infinitamente, para finalizar ingrese \"fin\"\n");
    fd = open(FIFO_FILE, O_WRONLY); // Error de compilacion debido a que toma O_WRONLY como variable sin declarar
    strcpy(fin_men, "fin");

    while (1) {
    printf("Ingrese Mensaje: ");
    fgets(leerbuf, sizeof(leerbuf), stdin);
    tamMensaje = strlen(leerbuf);
    leerbuf[tamMensaje - 1] = '\0';
    fin_proceso = strcmp(leerbuf, fin_men);

    //printf("fin procesros es %d\n", fin_proceso);
    if (fin_proceso != 0) {
        write(fd, leerbuf, strlen(leerbuf));
        printf("Mensaje enviado: \"%s\" con %d\n", leerbuf, (int)strlen(leerbuf));
    } else {
        write(fd, leerbuf, strlen(leerbuf));
        printf("Mensaje enviado: \"%s\" con %d\n", leerbuf, (int)strlen(leerbuf));
        close(fd);
        break;
    }
    }
    return 0;
}