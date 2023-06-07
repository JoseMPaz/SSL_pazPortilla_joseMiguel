#include "lista.h"
#include <stdlib.h>
#include "identificador.h"

void imprimir_entero (void * dato);

int main (void)
{
	int * dato;
	Lista lista_enteros;

	inicializar_lista (&lista_enteros);	
	
	dato = (int *) malloc (1*sizeof (int));
	*dato = 5;	
	agregar_elemento_a_lista (&lista_enteros, (int *) dato);
	
	dato = (int *) malloc (1*sizeof (int));
	*dato = 7;
	agregar_elemento_a_lista (&lista_enteros, (int *) dato);
	
	dato = (int *) malloc (1*sizeof (int));
	*dato = 3;
	agregar_elemento_a_lista (&lista_enteros, (int *) dato);
	
	mostrar_lista (lista_enteros, imprimir_entero);
	
	return 0;
}

void imprimir_entero (void * dato)
{
	int * dato_entero = (int *) dato; 
	printf ("%d\n", *dato_entero);

	return;
}
