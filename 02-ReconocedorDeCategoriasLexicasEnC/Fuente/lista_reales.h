#ifndef _LISTA_REALES_H_
#define _LISTA_REALES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Definiciones de tipos de datos utilizados*/

/*Definicion del tipo real*/
typedef struct
{
	int parte_entera;
	float mantisa;
}real_t;

/*Definicion del nodo real*/
typedef struct nodo_real_t
{
	real_t info;
	struct nodo_real_t * sig;
}nodo_real_t;

/*Prototipo de funciones utilizadas*/
int obtener_parte_entera (char cadena[]);
float obtener_mantisa (char cadena[]);
void agregar_reales_al_final_con_repeticion (nodo_real_t ** lista, real_t real);
void imprimir_reales (nodo_real_t * lista);
void eliminar_lista_reales (nodo_real_t * lista);
#endif
