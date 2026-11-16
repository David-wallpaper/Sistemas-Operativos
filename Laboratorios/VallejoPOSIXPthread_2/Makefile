###############################
# Pontificia Universidad Javeriana
# Makefile para compilar los programas
# Autor: Vallejo, David
###############################

GCC = gcc
FLAGS = -Wall -Wextra -pthread
LIBS = -lm

PROGRAMAS = pthread01 pthread02 productorConsumidor \
            challenge_05_pthreads_mensajes \
            challenge_06_suma_secuencial \
            challenge_07_suma_con_hilos \
            challenge_08_semaforo_seccion_critica \
            challenge_09_balance_semaforo \
            challenge_10_orden_con_semaforos \
            ejercicio_p7_cinco_hilos \
            ejercicio_p8_creacion_join \
            ejercicio_p13_hilos_sin_sincronizacion \
            ejercicio_p14_hilos_con_mutex

.PHONY: all clear

all: $(PROGRAMAS)

$(PROGRAMAS): %: %.c
	$(GCC) $(FLAGS) $< -o $@ $(LIBS)

clear:
	rm -f $(PROGRAMAS)
