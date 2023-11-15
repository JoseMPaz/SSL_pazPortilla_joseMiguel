#ifndef _VARIABLES_H_
#define _VARIABLES_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>


typedef struct
{
	char nombre_variable[200];
	char tipo_dato[200];
	char ambito[200];
	double valor;
}variable_t;

typedef struct nodo_variable_t
{
	variable_t info;
	struct nodo_variable_t * sig;
}nodo_variable_t;

void agregar_variable_al_final (nodo_variable_t ** variables, variable_t variable);
void imprimir_variables (nodo_variable_t * variables);
void eliminar_variables (nodo_variable_t * valiables);
nodo_variable_t * buscar_variable (nodo_variable_t * variables, char nombre_variable[]);


#endif
