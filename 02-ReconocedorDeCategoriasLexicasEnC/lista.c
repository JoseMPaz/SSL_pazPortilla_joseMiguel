#include "lista.h"

void inicializar_lista (Lista * lista)
{
	lista->cabeza = NULL;
	lista->tamano = 0;
	return;
}

void agregar_elemento_a_lista (Lista * lista, void * dato)
{
	Nodo * nodo, * tmp;
	agregar_elemento_a_nodo (&nodo,dato);
	
	if (lista->cabeza == NULL)
		lista->cabeza = nodo;
	else
	{
		for (tmp = lista->cabeza; tmp->siguiente != NULL; tmp = tmp->siguiente);
		tmp->siguiente = nodo;
	}
	(lista->tamano)++;
	return;
}

void mostrar_lista (Lista lista, void (*pf) (void * un_dato))
{
	Nodo * tmp;
	
	for (tmp = lista.cabeza; tmp != NULL; tmp = tmp->siguiente)
		(*pf)(tmp->dato);

	return;
}
