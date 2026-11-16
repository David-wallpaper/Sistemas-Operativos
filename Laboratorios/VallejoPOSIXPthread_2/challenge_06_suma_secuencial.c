/*
 * Hilos SO 2parte - pagina 3 - Challenge 06
 * Suma secuencial: primero +1 y luego -1. Resultado esperado: 0.
 * El PDF establece NUM_LOOPS = 900000000.
 * Para pruebas rapidas: gcc ... -DNUM_LOOPS=10000.
 */
#include <stdio.h>

#ifndef NUM_LOOPS
#define NUM_LOOPS 900000000
#endif

long long sum = 0;

void function(int valor) {
    for (int i = 0; i < NUM_LOOPS; i++) {
        sum += valor;
    }
}

int main(void) {
    function(1);
    function(-1);
    printf("Sum = %lld\n", sum);
    return 0;
}
