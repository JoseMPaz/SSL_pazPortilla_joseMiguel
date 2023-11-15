#include "identificador.h"

void agregar_identificador_al_final (nodo_identificador_t ** identificadores, char identificador[])
{
	nodo_identificador_t * nuevo_nodo, * ultimo_nodo;
	
	nuevo_nodo = (nodo_identificador_t *) malloc (sizeof(nodo_identificador_t));
	strcpy (nuevo_nodo->info , identificador);
	nuevo_nodo->sig = NULL;
	
	if(*identificadores == NULL)//Si la lista esta vacia
	{
		*identificadores = nuevo_nodo;
	}
	else
	{
		//Se recorre la lista hasta el utimo nodo
		for (ultimo_nodo = *identificadores; ultimo_nodo->sig != NULL; ultimo_nodo = ultimo_nodo->sig)
			; 
		ultimo_nodo->sig = nuevo_nodo;//El ultimo nodo apunta al nuevo nodo
	}
	
	return;
}

void eliminar_identificadores (nodo_identificador_t * identificadores)
{
	nodo_identificador_t * nodo_actual = identificadores, * nodo_siguiente = NULL;

	while (nodo_actual != NULL)
	{
		nodo_siguiente = nodo_actual->sig;
		free(nodo_actual);
		nodo_actual = nodo_siguiente;	
	}
	
	return;
}


void imprimir_identificadores (nodo_identificador_t * identificadores)
{
	nodo_identificador_t * temporal;
	
	printf ("\n%-20s%-20s%s\n", "############### ", "Identificadores: ", " ###############");
	
	for (temporal = identificadores; temporal != NULL; temporal = temporal->sig)
		printf("%s%-10s\n","Identificador: " ,temporal->info);

	return;
}

int cantidad_de_identificadores (nodo_identificador_t * identificadores)
{
	int contador = 0;
	nodo_identificador_t * temporal;
	
	for (temporal = identificadores; temporal != NULL; temporal = temporal->sig)
		 contador++;
		 
	return contador;
}

int rutina_semantica_validacion_de_repeticion_declaracion (char identificador[], nodo_variable_t * variables, nodo_funcion_t * funciones)
{
	if ( (buscar_variable (variables , identificador) != NULL) || (buscar_funcion (funciones, identificador) != NULL) )
	{
		printf ("%s%s\n", "Repeticion de nombre de identificador: ", identificador);
		return 1;
	}
	return 0;
}

//Espera que identificadores tenga al menos longitud >= 2
int rutina_semantica_validacion_de_repeticion_declaracion_multiple (nodo_identificador_t * identificadores)
{
	nodo_identificador_t * identificador, * sublista;
	
	if (cantidad_de_identificadores (identificadores) >= 2)
	{
		identificador = identificadores;
		sublista = identificadores->sig;
		while (sublista != NULL)
		{
			if (buscar_identificador (sublista,identificador->info) != NULL)
			{
				printf ("%s%s\n", "Hay identificador con igual nombre: ", identificador->info);
				return 1;
			}
			identificador = sublista;
			sublista = sublista->sig;
		}
	}

	return 0;
}

nodo_identificador_t * buscar_identificador (nodo_identificador_t * identificadores, char identificador[])
{
	nodo_identificador_t * temporal = identificadores;
	
	//recorre la lista hasta el final, pero si el nombre de la variable ya fue agregada deja de recorrer
	for(	;temporal != NULL && strcmp ( temporal->info, identificador) != 0/*Son distintos*/; temporal = temporal->sig)
		;	
		
	if (temporal != NULL)
		return temporal;
		
	return NULL;

}

int rutina_semantica_control_de_declaracion (char identificador[], char * tipo_dato, nodo_funcion_t * funciones, nodo_variable_t * variables)
{
	nodo_funcion_t * funcion = NULL;
	nodo_variable_t *variable = NULL;
	
	if (( funcion = buscar_funcion (funciones,identificador)) != NULL)//encontro el nombre de la funcion
	{
		strcpy (tipo_dato, funcion->info.tipo_dato_devuelto);
		return 0;
	}
	else if ( (variable = buscar_variable (variables,identificador)) != NULL)//encontro el nombre de la variable
	{
		strcpy (tipo_dato, variable->info.tipo_dato);
		return 0;
	}
	
	printf ("%s%s\n", "No fue declarado el identificador: ", identificador);
	
	return 1;
}

int rutina_semantica_tipo_dato_suma (char un_tipo_dato[], char otro_tipo_dato[])
{
	return strcmp (un_tipo_dato, otro_tipo_dato);
}

int rutina_semantica_uso_de_variable (nodo_variable_t * variables, char identificador[], char tipo_de_dato[])
{
	int encontrado = 0;
	nodo_variable_t * temporal = variables;
	
	//recorre la lista hasta el final, pero si el nombre de la variable ya fue agregada deja de recorrer
	for(	;temporal != NULL && strcmp ( temporal->info.nombre_variable, identificador) != 0/*Son distintos*/; temporal = temporal->sig)
		;
	
	if (temporal != NULL)
	{
		strcpy (tipo_de_dato, temporal->info.tipo_dato);
		encontrado = 1;
	}
	
	return encontrado;
}






