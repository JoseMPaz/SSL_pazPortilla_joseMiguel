#include "palabra_entero.h"

void crear_palabra_entero(palabra_entero_t ** nueva_palabra_entero, char pal[], int ent)
{
	*nueva_palabra_entero = (palabra_entero_t *) malloc (sizeof(palabra_entero_t));
	strcpy ((*nueva_palabra_entero)->palabra,pal);
	(*nueva_palabra_entero)->entero = ent;
	return; 
}

void imprimir_palabra_reservada (void * info)
{
	char * categorias[] = {CADENA_TIPO_DE_DATO, CADENA_ESTRUCTURA_DE_CONTROL, CADENA_DIRECTIVA_DE_PREPROCESAMIENTO};
	palabra_entero_t * temporal = (palabra_entero_t *) info;
	printf ("%s%-20s%s%s\n", MSJ_PALABRA_RESERVADA, temporal->palabra, MSJ_CATEGORIA, categorias[temporal->entero]);
	return;
}
