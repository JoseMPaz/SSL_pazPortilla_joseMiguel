#include "funciones.h"

void agregar_funcion_al_final (nodo_funcion_t ** funciones, funcion_t funcion)
{
	nodo_funcion_t * nuevo_nodo, * ultimo_nodo;
	
	nuevo_nodo = (nodo_funcion_t *) malloc (sizeof(nodo_funcion_t));
	nuevo_nodo->info = funcion;
	nuevo_nodo->sig = NULL;
	
	if(*funciones == NULL)//Si la lista esta vacia
	{
		*funciones = nuevo_nodo;
	}
	else
	{
		//Se recorre la lista hasta el utimo nodo
		for (ultimo_nodo = *funciones; ultimo_nodo->sig != NULL; ultimo_nodo = ultimo_nodo->sig)
			; 
		ultimo_nodo->sig = nuevo_nodo;
	}
	
	return;
}

void imprimir_funciones (nodo_funcion_t * funciones)
{
	nodo_funcion_t * temporal;
	
	printf ("\n%-20s%-20s%s\n\n", "############### ", "FUNCIONES", " ###############");
	
	for (temporal = funciones; temporal != NULL; temporal = temporal->sig)
	{
		printf ("%s%-10s\t%-3s%s\n",		"Nombre de funcion: " ,temporal->info.nombre_funcion, 
													"Tipo dato que devuelve: ", temporal->info.tipo_dato_devuelto);	
		imprimir_parametros (temporal->info.parametros, temporal->info.nombre_funcion);
		printf("%s%d\n", "Cantidad de Parametros: ", cantidad_de_parametros (temporal->info.parametros) );
		if (temporal->info.esta_definida == 1)
			printf ("%s\n\n","Esta Definida");
		else
			printf ("%s\n\n","Esta Declarada");
	}
	return;
}

void eliminar_funciones (nodo_funcion_t * funciones)
{
	nodo_funcion_t * nodo_actual = funciones, * nodo_siguiente = NULL;

	while (nodo_actual != NULL)
	{
		nodo_siguiente = nodo_actual->sig;
		eliminar_parametros (nodo_actual->info.parametros);
		free(nodo_actual);
		nodo_actual = nodo_siguiente;	
	}
	
	return;
}

nodo_funcion_t * buscar_funcion (nodo_funcion_t * funciones, char nombre_funcion[])
{
	nodo_funcion_t * temporal = funciones;
	
	//recorre la lista hasta el final, pero si el nombre de la variable ya fue agregada deja de recorrer
	for(	;temporal != NULL && strcmp ( temporal->info.nombre_funcion, nombre_funcion) != 0/*Son distintos*/; temporal = temporal->sig)
		;	
		
	if (temporal != NULL)
		return temporal;
		
	return NULL;
}

nodo_parametro_t * buscar_funcion_parametros (nodo_funcion_t * funciones, char nombre_funcion[])
{
	nodo_funcion_t * temporal = funciones;
	
	//recorre la lista hasta el final, pero si el nombre de la variable ya fue agregada deja de recorrer
	for(	;temporal != NULL && strcmp ( temporal->info.nombre_funcion, nombre_funcion) != 0/*Son distintos*/; temporal = temporal->sig)
		;	
		
	if (temporal != NULL)
		return temporal->info.parametros;
		
	return NULL;
}




