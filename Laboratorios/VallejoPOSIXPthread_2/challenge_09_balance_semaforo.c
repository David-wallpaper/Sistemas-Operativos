/*
 * Hilos SO 2parte - pagina 8 - Challenge 09
 * La diapositiva deja incompletas la creacion del segundo hilo, los
 * pthread_join y el manejo del semaforo. Se completaron.
 * Cada acceso a balance se protege con sem_wait/sem_post.
 */
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#ifndef ITERACIONES
#define ITERACIONES 10000000L
#endif

long balance = 0;
sem_t mutex;

void *increment(void *arg) {
    (void)arg;
    for (long i = 0; i < ITERACIONES; i++) {
        sem_wait(&mutex);
        balance++;
        sem_post(&mutex);
    }
    pthread_exit(NULL);
}

void *decrement(void *arg) {
    (void)arg;
    for (long j = 0; j < ITERACIONES; j++) {
        sem_wait(&mutex);
        balance--;
        sem_post(&mutex);
    }
    pthread_exit(NULL);
}

int main(void) {
    pthread_t thread1, thread2;
    if (sem_init(&mutex, 0, 1) != 0) return 1;
    if (pthread_create(&thread1, NULL, increment, NULL) != 0) return 1;
    if (pthread_create(&thread2, NULL, decrement, NULL) != 0) return 1;

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Value of balance is :%ld\n", balance);
    sem_destroy(&mutex);
    return 0;
}
