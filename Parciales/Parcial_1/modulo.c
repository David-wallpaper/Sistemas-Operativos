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
#include "modulo.h" // interfaz artesanal
#define PI 3.14159

//Función que calcula el área de circulo: entrada radio
void areaCirculo(float r){
    //cálculo del área de circulo con radio r
    float areaC = PI*r*r;
    printf("Área del circulo = %f \n", areaC);
}

// Función para sacar cuanto mide la circunferencia del círculo
void circunferencia(float r){
    // Variable donde se va guardar el valor de la circunferencia
float perimetroCircunferencia=0;

perimetroCircunferencia=2*PI*r;

printf("El perímetro de la circunferencia es = %f \n", perimetroCircunferencia);
}

// Funcion para sacar el valor del área del rectángulo
void areaRectangulo(float largo, float alto){
    //
 float areaTotal=0;

 areaTotal= largo*alto;
 
 printf("El area del rectángulo es = %f \n",areaTotal);
}

// Función para averiguar el perímetro del rectángulo
void perimetroRect(float largo, float alto){
    //cálculo de perimetro del rectangulo
    float perimetro = 2*(largo + alto);
    printf("Perimetro el rectangulo es = %f \n", perimetro);
}

//Función para imprimir la presentacion del calculador de circulo y circunferencia
void presentaCirculo(){
    printf("\n ====================================================\n");
    printf(" *** Calculador Area y Circunferencia del Circulo *** ");
    printf("\n ====================================================\n\n");
}
//Funcion imprimir presentacion del rectangulo
void presentaRectangulo(){
    printf("\n ====================================================\n");
    printf(" *** Calculador Area y Perimetro del Rectangulo *** ");
    printf("\n ====================================================\n\n");
}


