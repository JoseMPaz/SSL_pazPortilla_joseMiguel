#include "simbolo.h"

estado_t agregar_simbolo (nodo_simbolo_t * simbolos[], char nombre[], char tipo[], tipo_de_estructuta_t tipo_de_estructuta)
{
	nodo_simbolo_t * temporal = buscar_simbolo (simbolos[tipo_de_estructuta], nombre,tipo);
	
	if (temporal == NULL)//Si no fue agregado
	{
		temporal = (nodo_simbolo_t *) malloc (sizeof(nodo_simbolo_t));
		
		strcpy (temporal->info.nombre, nombre);
		strcpy (temporal->info.tipo, tipo);
		temporal->info.parametros = NULL;
		temporal->sig = NULL;
		//agregar_simbolo_al_final(simbolo[tipo_de_estructuta],temporal);
		return YA_FUE_AGREGADO;//Retorna TRUE si logra agregar una nueva estructura
	}
	
	return NO_FUE_AGREGADO;
}

nodo_simbolo_t * buscar_simbolo (nodo_simbolo_t * simbolos, char nombre[], char tipo[])
{
	nodo_simbolo_t * temporal;
	
	for (temporal = simbolos; temporal != NULL; temporal = temporal->sig)
		if (!strcmp (temporal->info.nombre,nombre))
			return temporal;
			
	return NULL;
}

void agregar_simbolo_al_final(nodo_simbolo_t * simbolos, nodo_simbolo_t * nuevo_nodo)
{
	nodo_simbolo_t * temporal;

	if (simbolos == NULL)
		simbolos = nuevo_nodo;
	else
	{
		for (temporal = simbolos; temporal->sig != NULL; temporal = temporal->sig)
			;
		temporal->sig = nuevo_nodo;			
	}
	return;
}
