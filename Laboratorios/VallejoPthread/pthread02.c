/*****************************************
* Pontificia Universidad Javeriana
* Fecha: 2024-06-10
* Tema: Creación de hilos con Posix
* Autor: D. Vallejo
* Objetivo:
-creacion funcion
-Llamadas de funcion
*******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

// Función que ejecutará el hilo
void *funcion(void *arg) {

    printf("Función Hilo: INICIO\n");

    // Suspende la ejecución del hilo durante 2 segundos
    sleep(2);

    printf("Función Hilo: FIN\n");

    // Finaliza la función del hilo sin devolver un resultado
    return NULL;
}

int main(int argc, char **argv) {

    // Variable que almacena el identificador del hilo
    pthread_t hilo;

    // Crea un hilo que ejecutará la función "funcion"
    // NULL indica que se utilizan los atributos predeterminados
    // El último NULL indica que no se envían argumentos a la función
    int hiloCreacion = pthread_create(&hilo, NULL, &funcion, NULL);

    // Verifica si el hilo se creó correctamente
    if (hiloCreacion) {
        printf("Fallo de creación del hilo :: %d\n", hiloCreacion);
    } else {
        printf("Hilo creado con ID :: %d\n", hiloCreacion);
    }

    printf("Espera de salida del hilo...\n");

    // Espera a que el hilo termine su ejecución
    hiloCreacion = pthread_join(hilo, NULL);

    // Verifica si la espera del hilo terminó correctamente
    if (hiloCreacion) {
        printf("Fallo de salida del hilo :: %d\n", hiloCreacion);
    }

    // Se ejecuta después de finalizar la espera del hilo
    printf("Final de programa principal\n");

    return 0;
}