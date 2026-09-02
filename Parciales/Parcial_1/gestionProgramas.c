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
#include "modulo.h"
#define PI 3.14159

//Función principal para la ejecucion del codigo
int main(){
    float radio;            //variable que almacena el valor del radio
    float altura;
    float anchura;
    presentaCirculo();

    printf("Ingrese el radio de la circunferencia : ");
    //captura de valor ingresado por usuario
    scanf("%f", &radio);
    //calculo del area del circulo
    areaCirculo(radio);
    //calculo del valor de la circunferencia
    circunferencia(radio);

    presentaRectangulo();

    printf("Ingrese el alto del rectangulo : ");
    //captura de valor ingresado por usuario
    scanf("%f", &altura);
    //captura de valor ingresado por usuario
    printf("Ingrese el ancho del rectangulo : ");
    scanf("%f", &anchura);
    //calculo del area del rectangulo
    areaRectangulo(anchura,altura);
    //calculo del perímetro del rectangulo
    perimetroRect(anchura,altura);

    return 0;
}
