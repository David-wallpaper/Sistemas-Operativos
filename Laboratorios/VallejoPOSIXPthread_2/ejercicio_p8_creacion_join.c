/*
 * Mod_3_Cap02_HPC - pagina 8 - Ejercicio
 * Ejemplo de creacion de un hilo, verificacion y pthread_join.
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

void *funcion(void *arg) {
    (void)arg;
    printf("Funcion Hilo: INICIO \n");
    sleep(2); /* espera 2 segundos */
    printf("Funcion Hilo: FIN\n");
    return NULL;
}

int main(void) {
    pthread_t hilo;
    int hiloCreacion = pthread_create(&hilo, NULL, &funcion, NULL);
    if (hiloCreacion) {
        printf("Fallo de creacion del hilo :: %d \n", hiloCreacion);
        return 1;
    } else {
        printf("Hilo creado correctamente\n");
    }

    printf("Espera de salida del hilo...\n");
    hiloCreacion = pthread_join(hilo, NULL);
    if (hiloCreacion) {
        printf("Fallo de salida del hilo :: %d \n", hiloCreacion);
        return 1;
    }
    printf("Final de programa principal\n");
    return 0;
}
