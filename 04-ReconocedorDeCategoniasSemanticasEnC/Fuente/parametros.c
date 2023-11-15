#include "parametros.h"

estado_parametro_t rutina_semantica_validacion_de_parametros (nodo_parametro_t * parametros)
{
	nodo_parametro_t * parametro;
	nodo_parametro_t * sublista;
	
	if (cantidad_de_parametros (parametros) >= 2)
	{
		parametro = parametros; 
		sublista = parametros->sig;
		while (sublista != NULL)
		{
			if (buscar_parametro (sublista,parametro->info) == CON_REPETICION)
			{
				printf ("%s%s\n", "Hay parametros con igual nombre: ", parametro->info.nombre_parametro);
				return REDEFINICION_DE_PARAMETRO;
			}
			parametro = sublista;
			sublista = sublista->sig;
		}
	}
	
	return OK;
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

//Espera que la lista de parametros no este vacia
repeticion_t buscar_parametro (nodo_parametro_t * parametros, parametro_t parametro)
{
	nodo_parametro_t * temporal = parametros;
	
	
	if (strcmp (parametro.nombre_parametro,"") == 0)
		return SIN_REPETICION;
	
	for(	;temporal != NULL && strcmp( temporal->info.nombre_parametro, parametro.nombre_parametro) != 0; temporal = temporal->sig)
		;	
		
	if (temporal == NULL)
		return SIN_REPETICION;
		
	return CON_REPETICION;
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
	
	printf ("%-20s%-20s%s%s\n", "**************** ", "Parametros de funcion: ", nombre_funcion, " ****************");
	for (temporal = parametros; temporal != NULL; temporal = temporal->sig)
	{
		if (!(strcmp(temporal->info.nombre_parametro,"")))
		{
			printf("%s%-10s\t%-3s%s\n","Nombre de parametro: -" ,temporal->info.nombre_parametro, "Tipo dato de parametro: ", 
					temporal->info.tipo_dato);
		}
		else
		{
			printf ("%s%-10s\t%-3s%s\n","Nombre de parametro: " ,temporal->info.nombre_parametro, "Tipo dato de parametro: ", 
						temporal->info.tipo_dato);	
		}
	}
	
	
	return;
}

int cantidad_de_parametros (nodo_parametro_t * parametros)
{
	int contador = 0;
	nodo_parametro_t * temporal;
	
	for (temporal = parametros; temporal != NULL; temporal = temporal->sig)
		 contador++;
	return contador;
}

void copiar_parametros (nodo_parametro_t ** parametros_destino, nodo_parametro_t * parametros_origen)
{
	nodo_parametro_t * temporal = parametros_origen;
	
	for (	;	temporal != NULL ; temporal = temporal->sig)
	{
		agregar_parametro_al_final (parametros_destino, temporal->info);
	}

	return;
}

int rutina_semantica_cantidad_y_tipos_de_parametros (nodo_parametro_t * parametros, nodo_parametro_t * argumentos)
{
	int estado = 0; 
	
	if (cantidad_de_parametros (parametros) != cantidad_de_parametros (argumentos))
		estado = 1;
	
	if (tipos_de_parametros_iguales (parametros,argumentos) == 1)
		estado = 2;
		
	return estado;
}

//longitud de p1 y p2 debe coincidir
int tipos_de_parametros_iguales (nodo_parametro_t * p1, nodo_parametro_t * p2)
{
	nodo_parametro_t * q1 = p1, * q2 = p2;
	
	for ( ; q1 != NULL; q1 = q1->sig, q2 = q2->sig)
	{
		if (strcmp (q1->info.tipo_dato, q2->info.tipo_dato) != 0)//Son distinto los tipos de dato
			return 1;
	}
	
	return 0;
}

