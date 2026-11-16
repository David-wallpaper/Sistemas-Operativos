/*
 * Mod_3_Cap02_HPC - pagina 13 - Sincronizacion de hilos Pthreads
 * Tres hilos ejecutan su funcion sin proteger la salida. El orden de
 * sus mensajes puede cambiar en cada ejecucion.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *funcion(void *job) {
    size_t IDh = *(size_t *)job;
    volatile unsigned long long cont = 5 * IDh;
    printf("\n Hilo %zu ha iniciado\n", IDh);
    for (int i = 0; i < 230; i++) {
        cont *= (cont + 1);
    }
    printf("\n Hilo %zu ha finalizado\n", IDh);
    return NULL;
}

int main(void) {
    size_t jobs[3];
    pthread_t hilos[3];
    int i = 0;
    int error;

    while (i < 3) {
        jobs[i] = (size_t)i;
        error = pthread_create(&hilos[i], NULL, &funcion, jobs + i);
        if (error != 0) {
            printf("\nError en la creacion de hilos: [%s]\n", strerror(error));
            return 1;
        }
        i++;
    }

    pthread_join(hilos[0], NULL);
    pthread_join(hilos[1], NULL);
    pthread_join(hilos[2], NULL);
    return 0;
}
