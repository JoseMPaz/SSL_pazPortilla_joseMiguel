#include "constante.h"



void agregar_constante (constante_t * constante, int valor)
{
	*constante = (constante_t) malloc (sizeof (int));
	*(*constante) = valor;
	return;
}

void imprimir_constante (void * constante)
{
	int * decimal= (int *) constante; 
	printf ("%d\n", *decimal);

	return;
}

void eliminar_constante (void ** constante)
{
	free (*constante);
	return;
}


