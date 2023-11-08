#include "parametros.h"

estado_parametro_t agregar_parametro_sin_repeticion (nodo_parametro_t ** parametros, parametro_t parametro)
{
	nodo_parametro_t * temporal = buscar_parametro (*parametros, parametro);
	
	if (temporal == NULL)//Si aun no fue agregado
	{
		agregar_parametro_al_final (parametros, parametro);
		return OK;
	}
	return REDEFINICION_DE_PARAMETRO;
}

void agregar_parametro_al_final (nodo_parametro_t ** parametros, parametro_t parametro)
{
	nodo_parametro_t * nuevo_nodo, * ultimo_nodo;
	
	nuevo_nodo = (nodo_parametro_t *) malloc (sizeof(nodo_parametro_t));
	nuevo_nodo->info = parametro;
	nuevo_nodo->sig = NULL;
	
	if(*parametros == NULL)//Si la lista esta vacia
	{
		*parametros = nuevo_nodo;
	}
	else
	{
		//Se recorre la lista hasta el utimo nodo
		for (ultimo_nodo = *parametros; ultimo_nodo->sig != NULL; ultimo_nodo = ultimo_nodo->sig)
			; 
		ultimo_nodo->sig = nuevo_nodo;
	}
	
	return;
}

nodo_parametro_t * buscar_parametro (nodo_parametro_t * parametros, parametro_t parametro)
{
	nodo_parametro_t * temporal = parametros;
	
	for(	;temporal != NULL && strcmp( temporal->info.nombre_parametro, parametro.nombre_parametro) != 0; temporal = temporal->sig)
		;	
		
	return temporal;
}

void eliminar_parametros (nodo_parametro_t * parametros)
{
	nodo_parametro_t * nodo_actual = parametros, * nodo_siguiente = NULL;

	while (nodo_actual != NULL)
	{
		nodo_siguiente = nodo_actual->sig;
		free(nodo_actual);
		nodo_actual = nodo_siguiente;	
	}
	
	return;
}


void imprimir_parametros (nodo_parametro_t * parametros, char nombre_funcion[])
{
	nodo_parametro_t * temporal;
	
	printf ("\n%-20s%-20s%s%s\n", "############### ", "Parametros de funcion: ", nombre_funcion, " ###############");
	for (temporal = parametros; temporal != NULL; temporal = temporal->sig)
		 printf ("%s%-20s\t%-3s%s\n","Nombre de parametro: " ,temporal->info.nombre_parametro, "Tipo dato de parametro: ", temporal->info.tipo_dato);
	
	return;
}

