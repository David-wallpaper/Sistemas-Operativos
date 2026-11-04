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

sem_t MUTEX; // Variable global para el semáforo

void *funcionHilo(void *arg) { //Crear funcion para el hilo
    sem_wait(&MUTEX); // Bloquear el semáforo
    printf("El hilo esta entrando\n");
    sleep(4);
    printf("El hilo esta saliendo\n");
    sem_post(&MUTEX); // Liberar el semáforo

}

int main() {

    sem_init(&MUTEX, 0, 1); // Inicializar el semáforo
    pthread_t hilo1, hilo2; // Declarar dos hilos

    pthread_create(&hilo1, NULL, funcionHilo, NULL); // Crear el primer hilo
    sleep(4);
    pthread_create(&hilo2, NULL, funcionHilo, NULL); // Crear el segundo hilo

    pthread_join(hilo1, NULL); // Esperar a que el primer hilo termine
    pthread_join(hilo2, NULL); // Esperar a que el segundo hilo termine
    sem_destroy(&MUTEX); // Destruir el semáforo

    return 0;
}