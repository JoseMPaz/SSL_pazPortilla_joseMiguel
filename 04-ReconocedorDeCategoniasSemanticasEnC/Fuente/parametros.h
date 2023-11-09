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
	NO = 0, 
	SI = 1
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
estado_parametro_t validar_que_los_parametros_se_llamen_distinto (nodo_parametro_t * parametros);			
#endif
