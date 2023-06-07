#include "lista.h"
#include <stdlib.h>
#include "cadena_repeticion.h"
#include "constante.h"

void imprimir_entero (void * dato);

int main (void)
{
	int * dato;
	Lista lista_constantes;
	constante_t constante;

	inicializar_lista (&lista_constantes);	

	
	agregar_constante (&constante,5);
	agregar_elemento_a_lista (&lista_constantes, (constante_t) constante);
	
	agregar_constante (&constante,7);
	agregar_elemento_a_lista (&lista_constantes, (constante_t) constante);
	
	agregar_constante (&constante,2);
	agregar_elemento_a_lista (&lista_constantes, (constante_t) constante);
	
	mostrar_lista (lista_constantes, imprimir_constante);
	
	return 0;
}


