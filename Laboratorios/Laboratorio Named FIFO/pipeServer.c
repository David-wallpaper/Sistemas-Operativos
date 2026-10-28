/*#############################################
 Pontificia Universidad Javeriana
 Autor: David vallejo
 Fecha: 28 de octubre de 2026
 Tema: ejercicio de named pipe FIFO
###############################################*/
#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

#define FIFO_FILE "MYFIFO"

int main() {
    int fd;
    char leerbuf[80];
    char fin[10];
    int final;
    int leer_bytes;

    /*Crear FIFO sino existe*/
    mknod(FIFO_FILE, S_IFIFO|0640, 0); //Error de compilacion debido a que toma S_IFIO como variable sin declarar
    strcpy(fin, "FIN");
    while(1) {
        fd= open(FIFO_FILE, O_RDONLY); // Error de compilacion debido a que toma O_RDONLY como variable sin declarar
        leer_bytes= read(fd, leerbuf, sizeof(leerbuf));
        leerbuf[leer_bytes] = '\0';
        printf("Mensaje recibido: \"%s\" con %d\n", leerbuf, (int)strlen(leerbuf));
        final = strcmp(leerbuf, fin);

        if(final ==0) {
            close(fd);
            break;
        }
    }
    return 0;   
}