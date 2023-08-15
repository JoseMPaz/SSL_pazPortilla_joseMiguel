#ifndef _LISTA_REALES_H_
#define _LISTA_REALES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int parte_entera;
	float mantisa;
}real_t;

typedef struct nodo_real_t
{
	real_t info;
	struct nodo_real_t * sig;
}nodo_real_t;

int obtener_parte_entera (char cadena[]);
float obtener_mantisa (char cadena[]);
void imprimir_reales (nodo_real_t * lista);
void agregar_reales_al_final_con_repeticion (nodo_real_t ** lista, real_t real);
void eliminar_lista_reales (nodo_real_t * lista);
#endif
