#ifndef _PARAMETROS_H_
#define _PARAMETROS_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct
{
	char nombre_parametro[200];
	char tipo_dato[200];
}parametro_t;

typedef struct nodo_parametro_t
{
	parametro_t info;
	struct nodo_parametro_t * sig;
}nodo_parametro_t;


typedef enum
{
	OK = 0,
	REDEFINICION_DE_PARAMETRO = 1
}estado_parametro_t;

estado_parametro_t agregar_parametro_sin_repeticion (nodo_parametro_t ** parametros, parametro_t parametro);
void agregar_parametro_al_final (nodo_parametro_t ** parametros, parametro_t parametro);
nodo_parametro_t * buscar_parametro (nodo_parametro_t * parametros, parametro_t parametro);	
void eliminar_parametros (nodo_parametro_t * parametros);		
void imprimir_parametros (nodo_parametro_t * parametros, char nombre_funcion[]);
int cantidad_de_parametros (nodo_parametro_t * parametros);						
#endif
