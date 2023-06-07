#include "nodo.h"

void agregar_elemento_a_nodo (Nodo ** nodo, void * dato)
{
	*nodo = (Nodo *) malloc (1*sizeof(Nodo));
	(*nodo)->info = dato;
	(*nodo)->sig = NULL;
	return;
}	
