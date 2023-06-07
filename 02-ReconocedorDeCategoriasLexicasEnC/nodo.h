#ifndef _NODO_H_
#define _NODO_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
	void * info;
	struct Nodo * sig;
}Nodo;

void agregar_elemento_a_nodo (Nodo ** nodo, void * dato);
#endif
