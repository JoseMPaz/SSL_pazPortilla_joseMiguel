#ifndef _LISTA_CADENA_ENTERO_H_
#define _LISTA_CADENA_ENTERO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char cadena[100];
	int entero;
}cadena_entero_t;

typedef struct nodo_cadena_entero_t
{
	cadena_entero_t info;
	struct nodo_cadena_entero_t * sig;
}nodo_cadena_entero_t;

void agregar_cadena_entero_al_final_con_repeticion (nodo_cadena_entero_t ** lista, cadena_entero_t cadena_entero);
void imprimir_cadena_entero (nodo_cadena_entero_t * lista, char etiqueta_cadena[], char etiqueta_entero[]);
void eliminar_lista_cadena_entero (nodo_cadena_entero_t * lista);
nodo_cadena_entero_t * buscar (nodo_cadena_entero_t * lista, cadena_entero_t cadena_entero);
void agregar_cadena_entero_sin_repeticion (nodo_cadena_entero_t ** lista, cadena_entero_t cadena_entero, void (*accion)(nodo_cadena_entero_t * aux));
int criterio_longitud (cadena_entero_t dato1, cadena_entero_t dato2);
int criterio_alfabetico(cadena_entero_t dato1, cadena_entero_t dato2);
void agregar_uno_a_entero(nodo_cadena_entero_t * nodo);
void desechar(nodo_cadena_entero_t * nodo);
void agregar_ordenado (nodo_cadena_entero_t ** lista, cadena_entero_t dato, int (*criterio)(cadena_entero_t dato1, cadena_entero_t dato2));
void agregar_cadena_entero_ordenado_sin_repeticion (nodo_cadena_entero_t ** lista, cadena_entero_t cadena_entero, void (*accion)(nodo_cadena_entero_t * aux), int (*criterio)(cadena_entero_t dato1,cadena_entero_t dato2));
#endif
