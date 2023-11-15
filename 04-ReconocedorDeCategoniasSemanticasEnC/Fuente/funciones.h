#ifndef _FUNCIONES_H_
#define _FUNCIONES_H_

#include <stdlib.h>
#include <string.h>
#include "parametros.h"

typedef struct
{
	char nombre_funcion[200];
	char tipo_dato_devuelto[200];
	nodo_parametro_t * parametros;
	int esta_definida;
}funcion_t;

typedef struct nodo_funcion_t
{
	funcion_t info;
	struct nodo_funcion_t * sig;
}nodo_funcion_t;

void agregar_funcion_al_final (nodo_funcion_t ** funciones, funcion_t funcion);
void imprimir_funciones (nodo_funcion_t * funciones);
void eliminar_funciones (nodo_funcion_t * funciones);
nodo_funcion_t * buscar_funcion (nodo_funcion_t * funciones, char nombre_funcion[]);
nodo_parametro_t * buscar_funcion_parametros (nodo_funcion_t * funciones, char nombre_funcion[]);

#endif
