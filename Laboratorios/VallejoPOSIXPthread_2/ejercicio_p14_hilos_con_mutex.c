/*
 * Mod_3_Cap02_HPC - pagina 14 - Sincronizacion con mutex
 * Mismo ejemplo de pagina 13, ahora una exclusion mutua protege
 * cada seccion completa: inicio, trabajo y final de cada hilo.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

pthread_mutex_t BLOQUEO;

void *funcion(void *job) {
    pthread_mutex_lock(&BLOQUEO);
    size_t IDh = *(size_t *)job;
    volatile unsigned long long cont = 5 * IDh;
    printf("\n Hilo %zu ha iniciado\n", IDh);
    for (int i = 0; i < 230; i++) {
        cont *= (cont + 1);
    }
    printf("\n Hilo %zu ha finalizado\n", IDh);
    pthread_mutex_unlock(&BLOQUEO);
    return NULL;
}

int main(void) {
    size_t jobs[3];
    pthread_t hilos[3];
    int i = 0;
    int error;

    if (pthread_mutex_init(&BLOQUEO, NULL) != 0) {
        printf("\nFallo de inicializacion de MUTEX\n");
        return 1;
    }

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
    pthread_mutex_destroy(&BLOQUEO);
    return 0;
}
