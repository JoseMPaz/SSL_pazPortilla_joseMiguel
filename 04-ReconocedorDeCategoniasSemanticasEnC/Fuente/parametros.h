#ifndef _PARAMETROS_H_
#define _PARAMETROS_H_

#include <stdlib.h>
#include <string.h>

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

#endif
