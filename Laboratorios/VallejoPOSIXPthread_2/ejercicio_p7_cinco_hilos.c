/*
 * Mod_3_Cap02_HPC - pagina 7 - Ejercicio
 * Crea cinco hilos, cada uno imprime su numero de trabajo.
 * Transcripcion de la captura, con leves ajustes de estilo.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define N 5

static void *funcion(void *arg) {
    size_t job = *(size_t *)arg;
    printf("Job %zu\n", job);
    return NULL;
}

int main(void) {
    size_t jobs[N];        /* vector de trabajos */
    pthread_t hilos[N];   /* vector de hilos */
    for (size_t i = 0; i < N; i++) {
        jobs[i] = i;
        if (pthread_create(&hilos[i], NULL, funcion, jobs + i) != 0) return 1;
    }

    for (size_t i = 0; i < N; i++) {
        pthread_join(hilos[i], NULL); /* espera a que termine cada hilo */
    }
    return 0;
}
