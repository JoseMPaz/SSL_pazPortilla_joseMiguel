#ifndef _LISTA_ENTEROS_H_
#define _LISTA_ENTEROS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo_enteros_t
{
	int info;
	struct nodo_enteros_t * sig;
}nodo_enteros_t;

void agregar_enteros_al_final_con_repeticion (nodo_enteros_t ** lista, int informacion);
void imprimir_enteros (nodo_enteros_t * lista);
void imprimir_caracteres (nodo_enteros_t * lista);
int convertir_cadena_entera_a_entero (char cadena[]);
int convertir_cadena_octal_a_entero (char cadena[]);
int convertir_cadena_hexadecimal_a_entero (char cadena[]);
void contar_enteros (nodo_enteros_t * lista);
void eliminar_lista_enteros (nodo_enteros_t * lista);
#endif
