/*****************************************
* Pontificia Universidad Javeriana
* Fecha: 2024-06-10
* Tema: Creación de hilos con Posix
* Autor: D. Vallejo
* Objetivo:
-creacion funcion
-Semaforos
-Llamadas de funcion
*******************************************/
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define N 5

sem_t MUTEX; // Variable global para el semáforo

static void *funcionHilo(void *arg) { //Crear funcion para el hilo

        size_t job = *(size_t*)arg; // Castea a tipos de datos num
        printf("Trabajo %zu \n", job);
        return NULL;
}

int main(int argc, char *argv[]) {
    size_t jobs[N]; // Arreglo de trabajos
    pthread_t hilos[N]; // Declarar N hilos

    for (size_t i = 0; i < N; i++) {
        jobs[i] = i;
        pthread_create(&hilos[i], NULL, funcionHilo, &jobs[i]);
    }

    for (size_t i = 0; i < N; i++) {
        pthread_join(hilos[i], NULL);
    }
    

    return 0;
}