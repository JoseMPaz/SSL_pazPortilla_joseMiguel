#ifndef _IDENTIFICADOR_H_
#define _IDENTIFICADOR_H_

#include <stdlib.h>
#include <string.h>
#include "variables.h"
#include "funciones.h"

typedef struct nodo_identificador_t
{
	char info[200];
	struct nodo_identificador_t * sig;
}nodo_identificador_t;

void agregar_identificador_al_final (nodo_identificador_t ** identificadores, char identificador[]);
void imprimir_identificadores (nodo_identificador_t * identificadores);
void eliminar_identificadores (nodo_identificador_t * identificadores);
int cantidad_de_identificadores (nodo_identificador_t * identificadores);
int rutina_semantica_validacion_de_repeticion_declaracion(char identificador[], nodo_variable_t * variables, nodo_funcion_t * funciones);
nodo_identificador_t * buscar_identificador (nodo_identificador_t * identificadores, char identificador[]);
int rutina_semantica_validacion_de_repeticion_declaracion_multiple (nodo_identificador_t * identificadores);
int rutina_semantica_control_de_declaracion (char identificador[], char * tipo_dato, nodo_funcion_t * funciones, nodo_variable_t * variables);
int rutina_semantica_tipo_dato_suma (char un_tipo_dato[], char otro_tipo_dato[]);
int rutina_semantica_uso_de_variable (nodo_variable_t * variable, char identificador[], char tipo_de_dato[]);

#endif
