#ifndef _FUNCIONES_H_
#define _FUNCIONES_H_

#include <stdlib.h>
#include <string.h>
#include "parametros.h"

typedef struct
{
	char nombre_funcion[200];
	char tipo_dato_devuelto[200];
}funcion_t;

typedef struct nodo_funcion_t
{
	funcion_t info;
	struct nodo_funcion_t * sig;
}nodo_funcion_t;

#endif
