/*****************************************
* Pontificia Universidad Javeriana
* Fecha: 2024-06-10
* Tema: Creación de hilos con Posix
* Autor: D. Vallejo
* Objetivo:
* - Creación de hilos productores y consumidores
* - Sincronización mediante mutex
* - Uso de variables de condición
*******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

// Cantidad de hilos productores y consumidores
#define NUM_HILOS 5

// Capacidad máxima del contador
#define CAPACIDAD 10

// Contador compartido entre productores y consumidores
int counter = 0;

// Mutex que protege el acceso al contador compartido
pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;

// Variable de condición para los productores
pthread_cond_t condVarProd = PTHREAD_COND_INITIALIZER;

// Variable de condición para los consumidores
pthread_cond_t condVarCons = PTHREAD_COND_INITIALIZER;


// Función que ejecutan los hilos productores
void *productor(void *arg) {

    // Ciclo infinito que permite producir continuamente
    while (1) {

        // Bloquea el mutex antes de consultar el contador
        pthread_mutex_lock(&counter_mutex);

        // Verifica si el contador alcanzó su capacidad máxima
        while (counter >= CAPACIDAD) {

            // Suspende el productor hasta que exista espacio
            // Libera temporalmente el mutex mientras espera
            pthread_cond_wait(&condVarProd, &counter_mutex);
        }

        // Incrementa el contador, simulando la producción
        counter++;

        // Muestra el identificador del productor y el contador
        printf("Soy productor %lu, valor contador = %d\n",
               (unsigned long)pthread_self(), counter);

        // Notifica a un consumidor que existen elementos disponibles
        pthread_cond_signal(&condVarCons);

        // Verifica si debe realizar una pausa
        int pausar = (counter == 5);

        // Libera el mutex para permitir el acceso a otros hilos
        pthread_mutex_unlock(&counter_mutex);

        // Si el contador llegó a 5, espera un segundo
        if (pausar) {
            sleep(1);
        }
    }

    return NULL;
}


// Función que ejecutan los hilos consumidores
void *consumidor(void *arg) {

    // Ciclo infinito que permite consumir continuamente
    while (1) {

        // Suspende el consumidor durante un segundo
        sleep(1);

        // Bloquea el mutex antes de consultar el contador
        pthread_mutex_lock(&counter_mutex);

        // Verifica si no existen elementos disponibles
        while (counter <= 0) {

            // Suspende el consumidor hasta que existan elementos
            // Libera temporalmente el mutex mientras espera
            pthread_cond_wait(&condVarCons, &counter_mutex);
        }

        // Muestra el identificador del consumidor y el contador
        printf("Soy consumidor %lu, valor contador = %d\n",
               (unsigned long)pthread_self(), counter);

        // Disminuye el contador, simulando el consumo
        counter--;

        // Notifica a un productor que existe espacio disponible
        pthread_cond_signal(&condVarProd);

        // Libera el mutex para permitir el acceso a otros hilos
        pthread_mutex_unlock(&counter_mutex);
    }

    return NULL;
}


// Función principal del programa
int main(void) {

    // Vectores que almacenan los identificadores de los hilos
    pthread_t proHilo[NUM_HILOS], conHilo[NUM_HILOS];

    int i;

    // Ciclo para crear los hilos productores y consumidores
    for (i = 0; i < NUM_HILOS; i++) {

        // Crea un hilo productor
        int error = pthread_create(&proHilo[i], NULL, productor, NULL);

        // Verifica si el productor se creó correctamente
        if (error != 0) {
            printf("Error al crear productor %d\n", i);
            return 1;
        }

        // Crea un hilo consumidor
        error = pthread_create(&conHilo[i], NULL, consumidor, NULL);

        // Verifica si el consumidor se creó correctamente
        if (error != 0) {
            printf("Error al crear consumidor %d\n", i);
            return 1;
        }
    }

    // Espera a que finalicen los hilos creados
    for (i = 0; i < NUM_HILOS; i++) {

        // Espera la finalización del productor correspondiente
        pthread_join(proHilo[i], NULL);

        // Espera la finalización del consumidor correspondiente
        pthread_join(conHilo[i], NULL);
    }

    return 0;
}