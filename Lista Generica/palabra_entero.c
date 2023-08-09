#include "palabra_entero.h"

void crear_palabra_entero (palabra_entero_t ** nueva_palabra_entero, char pal[], int ent)
{
	*nueva_palabra_entero = (palabra_entero_t *) malloc (sizeof(palabra_entero_t));
	strcpy ((*nueva_palabra_entero)->palabra,pal);
	(*nueva_palabra_entero)->entero = ent;
	return; 
}

void imprimir_palabra_reservada (void * info)
{
	char * categorias[] = {CADENA_TIPO_DE_DATO, CADENA_ESTRUCTURA_DE_CONTROL, CADENA_DIRECTIVA_DE_PREPROCESAMIENTO};
	palabra_entero_t * un_info = (palabra_entero_t *) info;
	printf ("%s%-20s%s%s\n", MSJ_PALABRA_RESERVADA, un_info->palabra, MSJ_CATEGORIA, categorias[un_info->entero]);
	return;
}

int comparar_alfabeticamente (void * info1, void * info2)
{
	palabra_entero_t * un_info = (palabra_entero_t *) info1;
	palabra_entero_t * otro_info = (palabra_entero_t *) info2;
	int resultado;
	return strcmp (un_info->palabra,otro_info->palabra);
}
