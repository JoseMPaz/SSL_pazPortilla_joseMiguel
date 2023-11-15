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
	SIN_REPETICION = 0, 
	CON_REPETICION = 1
}repeticion_t;

typedef enum
{
	OK = 0,
	REDEFINICION_DE_PARAMETRO = 1
}estado_parametro_t;


void agregar_parametro_al_final (nodo_parametro_t ** parametros, parametro_t parametro);
repeticion_t buscar_parametro (nodo_parametro_t * parametros, parametro_t parametro);	
void eliminar_parametros (nodo_parametro_t * parametros);		
void imprimir_parametros (nodo_parametro_t * parametros, char nombre_funcion[]);
int cantidad_de_parametros (nodo_parametro_t * parametros);		
estado_parametro_t rutina_semantica_validacion_de_parametros (nodo_parametro_t * parametros);		
void copiar_parametros (nodo_parametro_t ** parametros_destino, nodo_parametro_t * parametros_origen);	
int rutina_semantica_cantidad_y_tipos_de_parametros (nodo_parametro_t * parametros, nodo_parametro_t * argumentos);
int tipos_de_parametros_iguales (nodo_parametro_t * p1, nodo_parametro_t * p2);

#endif
