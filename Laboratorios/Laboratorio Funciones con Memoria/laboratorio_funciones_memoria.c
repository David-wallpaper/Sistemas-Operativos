/*******************************************************************************/
/*
	Pontificia Universidad Javeriana
	Asignatura: Sistemas Operativos
	Fecha: 2-09-2026
	Autor: David Vallejo
	Asunto: Laboratorio funciones de memoria
*/
/******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/*Se establece variable global con valor 4*/
#define CAPACIDAD_INICIAL 4

/*Se crea una estructura de datos para manipulación de Vectores*/
typedef struct vectorDin{
    int capacidad;
    int totalElementos;
    void **elemento;
}vectorDin;

/*Función para creación e inicio del vector*/
void iniVector(vectorDin *V){
    V->capacidad = CAPACIDAD_INICIAL;
    V->totalElementos = 0;
    V->elemento = malloc(sizeof(void *)*V->capacidad);
}

/*Función para la redimensíón del vector*/
static void resizeVector(vectorDin *V, int capacidad){
    printf("Redimensión: %d a %d\n", V->capacidad, capacidad);
    void **elemento = realloc(V->elemento, sizeof(void *)*capacidad);
    if(elemento){
        V->elemento  = elemento;
        V->capacidad = capacidad;
    }
}

/*Función para obtener el índice de un elemento dentro del vector*/
void *getVector(vectorDin *V, int indice){
    if(indice >=0 && indice < V->totalElementos)
        return V->elemento[indice];
    return NULL;
}

/*Función para agregar elementos al vector*/
void addVector(vectorDin *V, void *elemento){
    if(V->capacidad == V->totalElementos)
        resizeVector(V, V->capacidad*2);
    V->elemento[V->totalElementos++] = elemento;
}

/*Indica la cantidad de elementos del vector*/
int totalVector(vectorDin *V){
    return V->totalElementos;
}

/*Función que borra un elemento en la posición índice*/
void borrarVector(vectorDin *V, int indice){
    if(indice < 0 || indice >= V->totalElementos)
        return;
    V->elemento[indice] = NULL;

    for(int i = indice; i < V->totalElementos-1; i++){
        V->elemento[i] = V->elemento[i+1];
        V->elemento[i+1] = NULL;
    }
    V->totalElementos--;
    if(V->totalElementos > 0 && V->totalElementos == V->capacidad/4)
        resizeVector(V, V->capacidad/2);

}

/*Función para ubicar un elemento en el índice*/
void setVector(vectorDin *V, int indice, void *elemento){
    if(indice >= 0 && indice < V->totalElementos)
        V->elemento[indice]=elemento;
}

/*Función para liberar la memoria reservada*/
void liberarVector(vectorDin *V){
    free(V->elemento);
}

int main(){
    /*Creación de vector para edición*/
    vectorDin editor;
    /*Inicializa el vector*/
    iniVector(&editor);

    /*Aumentar el tamaño del vector*/
    resizeVector(&editor, 8);

    /*Agregar la palabra hola al vector en el índice 0*/
    addVector(&editor, "Hola");
    /* Se agrega al final del vector con la palabra Profesional */
    addVector(&editor, " Profesional");
    /*Se agrega al final del vector con la palabra en*/
    addVector(&editor, " en");
    /*Se agrega al final del vector con la palabra en formación*/
    addVector(&editor, "formación");

    /*Imprimir por elemento del vector*/
    for(int i=0; i< totalVector(&editor); i++)
        printf("%s", (char *) getVector(&editor, i));
    printf("\n\n");

    /*Liberar espacio en memoria*/
    borrarVector(&editor, 1);

    /*Se agrega en la posición 1, el vector con la palabra Excelente*/
    setVector(&editor, 1, "Excelente");

    /*Imprimir por elemento de vector*/
    for(int i=0; i< totalVector(&editor); i++)
        printf("%s", (char *) getVector(&editor, i));
    printf("\n\n");


    /*Liberar espacio en memoria reservado*/
    liberarVector(&editor);
}
    /*            */
