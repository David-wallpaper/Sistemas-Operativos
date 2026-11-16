/*
 * Hilos SO 2parte - pagina 4 - Challenge 07
 * Diapositiva INCOMPLETA. Se completaron las llamadas pthread_create,
 * function(-1) y pthread_join para mostrar una posible condicion de carrera.
 * La variable global sum se modifica SIN proteccion por ambos hilos.
 * Por eso el resultado NO tiene por que ser 0.
 */
#include <pthread.h>
#include <stdio.h>

#ifndef NUM_LOOPS
#define NUM_LOOPS 900000000
#endif

long long sum = 0;

void *function(void *arg) {
    int valor = *(int *)arg;
    for (int i = 0; i < NUM_LOOPS; i++) {
        sum += valor;  /* carrera de datos intencional */
    }
    return NULL;
}

int main(void) {
    pthread_t id01;
    int positivo = 1;
    int negativo = -1;

    if (pthread_create(&id01, NULL, function, &positivo) != 0) return 1;
    /* El hilo principal trabaja a la vez que id01. */
    function(&negativo);
    pthread_join(id01, NULL);

    printf("Sum = %lld\n", sum);
    return 0;
}
