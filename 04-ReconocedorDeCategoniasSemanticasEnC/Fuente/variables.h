#ifndef _VARIABLES_H_
#define _VARIABLES_H_

#include <stdlib.h>
#include <string.h>

typedef struct
{
	char nombre_variable[200];
	char tipo_dato[200];
	char ambito[200];
}variable_t;

typedef struct nodo_variable_t
{
	variable_t info;
	struct nodo_variable_t * sig;
}nodo_variable_t;

/*
estado_t agregar_simbolo (nodo_simbolo_t * simbolos[], char nombre[], char tipo[], tipo_de_estructuta_t tipo_de_estructuta);
nodo_simbolo_t * buscar_simbolo (nodo_simbolo_t * simbolos, char nombre[], char tipo[]);
void agregar_simbolo_al_final(nodo_simbolo_t * simbolos, nodo_simbolo_t * nuevo_nodo);
*/
#endif
