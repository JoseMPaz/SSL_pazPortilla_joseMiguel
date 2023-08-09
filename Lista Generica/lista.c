#include "lista.h"

void agregar_al_final (nodo_t ** lista, void * elemento)
{
	nodo_t * nuevo_nodo = (nodo_t *) malloc ( sizeof(nodo_t) );
	nodo_t * ultimo_nodo; 
	
	nuevo_nodo->info = elemento;
	nuevo_nodo->sig = NULL;
	
	if(*lista == NULL)
	{
		*lista = nuevo_nodo;
	}
	else
	{
		for (ultimo_nodo = *lista; ultimo_nodo->sig != NULL; ultimo_nodo = ultimo_nodo->sig)
			; 
		ultimo_nodo->sig = nuevo_nodo;
	}
	return;
}

void imprimir (nodo_t * lista, void (*puntero_a_funcion)(void * info))
{
	nodo_t * nodo_actual;
	
	if (lista == NULL)
		puts (MENSAJE_LISTA_VACIA);
	for (nodo_actual = lista; nodo_actual != NULL; nodo_actual = nodo_actual->sig)
		(*puntero_a_funcion)(nodo_actual->info);

	return;
}

void eliminar (nodo_t * lista)
{
	nodo_t * nodo_actual = lista, * nodo_siguiente = NULL;

	while (nodo_actual != NULL)
	{
		nodo_siguiente = nodo_actual->sig;
		free(nodo_actual->info);
		free(nodo_actual);
		nodo_actual = nodo_siguiente;	
	}
	return;
}
