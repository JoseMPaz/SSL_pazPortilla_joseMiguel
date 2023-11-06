#ifndef _SIMBOLO_H_
#define _SIMBOLO_H_

#include <stdlib.h>
#include <string.h>
typedef enum
{
	DEFINICION_DE_FUNCION = 0,
	DECLARACION_DE_VARIABLE = 1,
	DECLARACION_DE_FUNCION = 2
}tipo_de_estructuta_t;

typedef enum
{
	NO_FUE_AGREGADO = 0,
	YA_FUE_AGREGADO = 1
}estado_t;

typedef struct simbolo_t
{
	char nombre[200];
	char tipo[200];
	struct simbolo_t * parametros;
}simbolo_t;

typedef struct nodo_simbolo_t
{
	simbolo_t info;
	struct nodo_simbolo_t * sig;
}nodo_simbolo_t;

estado_t agregar_simbolo (nodo_simbolo_t * simbolos[], char nombre[], char tipo[], tipo_de_estructuta_t tipo_de_estructuta);
nodo_simbolo_t * buscar_simbolo (nodo_simbolo_t * simbolos, char nombre[], char tipo[]);
void agregar_simbolo_al_final(nodo_simbolo_t * simbolos, nodo_simbolo_t * nuevo_nodo);

#endif
