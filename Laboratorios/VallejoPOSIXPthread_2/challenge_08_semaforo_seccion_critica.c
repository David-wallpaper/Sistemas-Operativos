/*
 * Hilos SO 2parte - pagina 7 - Challenge 08
 * Se usa un semaforo binario para impedir entradas simultaneas.
 */
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

sem_t mutex;

void *operation(void *arg) {
    (void)arg;
    sem_wait(&mutex); /* wait: se bloquea si otro hilo ocupa la seccion */
    printf("\nEntered race..\n");
    /* critical section */
    sleep(4);
    printf("\nJust Exiting race...\n");
    sem_post(&mutex); /* signal: libera la seccion */
    return NULL;
}

int main(void) {
    pthread_t thread01, thread02;
    if (sem_init(&mutex, 0, 1) != 0) return 1;
    if (pthread_create(&thread01, NULL, operation, NULL) != 0) return 1;
    sleep(2);
    if (pthread_create(&thread02, NULL, operation, NULL) != 0) return 1;

    pthread_join(thread01, NULL);
    pthread_join(thread02, NULL);
    sem_destroy(&mutex);
    return 0;
}
