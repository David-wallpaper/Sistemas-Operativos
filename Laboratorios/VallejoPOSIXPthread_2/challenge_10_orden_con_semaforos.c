/*
 * Hilos SO 2parte - pagina 9 - Challenge 10
 * Misma frase que Challenge 05, pero ahora en orden determinado:
 * f3: Estoy aprendiendo, f2: de forma rapida..., f1: porque soy...

 */
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

sem_t listo_primero;
sem_t listo_segundo;

void *f1(void *arg) {
    (void)arg;
    sem_wait(&listo_segundo);
    printf(" porque soy el mejor!!");
    return NULL;
}

void *f2(void *arg) {
    (void)arg;
    sem_wait(&listo_primero);
    printf(" de forma rapida y divertida ");
    sem_post(&listo_segundo);
    return NULL;
}

void *f3(void *arg) {
    (void)arg;
    printf(" Estoy aprendiendo ");
    sem_post(&listo_primero);
    return NULL;
}

int main(void) {
    pthread_t thread01, thread02, thread03;
    if (sem_init(&listo_primero, 0, 0) != 0) return 1;
    if (sem_init(&listo_segundo, 0, 0) != 0) return 1;
    if (pthread_create(&thread01, NULL, f1, NULL) != 0) return 1;
    if (pthread_create(&thread02, NULL, f2, NULL) != 0) return 1;
    if (pthread_create(&thread03, NULL, f3, NULL) != 0) return 1;

    pthread_join(thread01, NULL);
    pthread_join(thread02, NULL);
    pthread_join(thread03, NULL);
    sem_destroy(&listo_primero);
    sem_destroy(&listo_segundo);
    printf("\n");
    return 0;
}
