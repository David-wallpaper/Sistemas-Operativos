/****************************************************
#        Pontificia Universidad Javeriana
#
# Autor:David Vallejo
# Fecha:2 de septiembre de 2026
# Materia: Sistemas Operativos
# Tema: I parcial de Sistemas Operativos
# Funciones:
            - Área del circulo
            - Perímetro del circulo (Circunferencia)
            - Área del rectángulo
            - Perímetro del rectángulo
****************************************************/

#include <stdlib.h>
#include <stdio.h>

#define PI 3.14159

#ifndef __MODULOH__
#define __MODULO_H__

//Función que calcula el área de circulo: entrada radio
void areaCirculo(float r);

// Función para sacar cuanto mide la circunferencia del círculo
void circunferencia(float r);


// Funcion para sacar el valor del área del rectángulo
void areaRectangulo(float largo, float alto);


// Función para averiguar el perímetro del rectángulo
void perimetroRect(float largo, float alto);

//Función para imprimir la presentacion del calculador del circulo y circcunferencia
void presentaCirculo();

//Funcion para imprimir la presentacion del calculador del rectangulo
void presentaRectangulo();
#endif
