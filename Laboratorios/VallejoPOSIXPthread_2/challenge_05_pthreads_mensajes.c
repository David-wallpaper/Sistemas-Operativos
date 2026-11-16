/*
 * Hilos SO 2parte - pagina 2 - Challenge 05
 * Tres hilos imprimen fragmentos de una frase SIN controlar el orden.
 * Ajustes: encabezados, return NULL, e identificadores de hilo correctos.
 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *f1(void *arg) {
    (void)arg;
    printf(" porque soy el mejor!!");
    return NULL;
}

void *f2(void *arg) {
    (void)arg;
    printf(" de forma rapida y divertida ");
    return NULL;
}

void *f3(void *arg) {
    (void)arg;
    printf(" Estoy aprendiendo ");
    return NULL;
}

int main(void) {
    pthread_t thread01, thread02, thread03;
    if (pthread_create(&thread01, NULL, f1, NULL) != 0) return 1;
    if (pthread_create(&thread02, NULL, f2, NULL) != 0) return 1;
    if (pthread_create(&thread03, NULL, f3, NULL) != 0) return 1;

    pthread_join(thread01, NULL);
    pthread_join(thread02, NULL);
    pthread_join(thread03, NULL);
    printf("\n");
    return 0;
}
