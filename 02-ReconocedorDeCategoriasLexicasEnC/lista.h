#ifndef _LISTA_H_
#define _LISTA_H_

#include "nodo.h"



typedef struct Lista
{
	Nodo * cabeza;
	int tamano;
}Lista;

void inicializar_lista (Lista * lista);
void agregar_elemento_a_lista (Lista * lista, void * dato);
void mostrar_lista (Lista lista, void (*pf) (void * un_dato));

#endif
