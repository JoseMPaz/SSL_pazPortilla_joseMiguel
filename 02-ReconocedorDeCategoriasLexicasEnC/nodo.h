#ifndef _NODO_H_
#define _NODO_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
	void * dato;
	struct Nodo * siguiente;
}Nodo;

void agregar_elemento_a_nodo (Nodo ** nodo, void * un_dato);
#endif
