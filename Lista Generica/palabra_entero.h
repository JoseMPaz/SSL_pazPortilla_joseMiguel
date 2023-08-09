#ifndef _PALABRA_ENTERO_H_
#define _PALABRA_ENTERO_H_

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define LONGITUD 100
#define CADENA_TIPO_DE_DATO "Tipo de Dato"
#define CADENA_ESTRUCTURA_DE_CONTROL "Estructura de Control"
#define CADENA_DIRECTIVA_DE_PREPROCESAMIENTO "Directiva de Preprocesamiento"
#define MSJ_PALABRA_RESERVADA "Palabra reservada: "
#define MSJ_CATEGORIA "Categoria: "

typedef enum
{
	TIPO_DE_DATO = 0,
	ESTRUCTURA_DE_CONTROL = 1, 
	DIRECTIVA_DE_PREPROCESAMIENTO = 2
}categoria_t;

typedef struct
{
	char palabra[LONGITUD];
	int entero;
}palabra_entero_t;

void crear_palabra_entero(palabra_entero_t ** nueva_palabra_entero, char pal[], int ent);
void imprimir_palabra_reservada (void * info);
int comparar_alfabeticamente (void * info1, void * info2);

#endif
