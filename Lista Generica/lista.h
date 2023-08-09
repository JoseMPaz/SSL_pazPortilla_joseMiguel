#ifndef _LISTA_H_
#define _LISTA_H_

#include <stdio.h>
#include <stdlib.h>
#define MENSAJE_LISTA_VACIA "La lista esta vacia."

typedef struct nodo_t
{
	void * info;
	struct nodo_t * sig;
}nodo_t;

void agregar_al_final (nodo_t ** lista, void * elemento);
void imprimir (nodo_t * lista, void (*puntero_a_funcion)(void * info));
void eliminar (nodo_t * lista);
#endif
