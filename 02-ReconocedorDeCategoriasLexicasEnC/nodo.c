#include "nodo.h"

void agregar_elemento_a_nodo (Nodo ** nodo, void * un_dato)
{
	*nodo = (Nodo *) malloc (1*sizeof(Nodo));
	(*nodo)->dato = un_dato;
	(*nodo)->siguiente = NULL;
	return;
}	
