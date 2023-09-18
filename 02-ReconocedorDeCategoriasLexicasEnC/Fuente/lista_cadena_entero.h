#ifndef _LISTA_CADENA_ENTERO_H_
#define _LISTA_CADENA_ENTERO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef enum 
{
	FALSE = 0,
	TRUE = 1
}bool_t;


// LO UTILIZAMOS EN UN VECTOR DONDE CADA POSICION ES UNA PARA CATEGORIA 
typedef enum
{
	TIPO_DE_DATO = 0,
	ESTRUCTURA_DE_CONTROL = 1, 
	DIRECTIVA_DE_PREPROCESAMIENTO = 2,
	PUNTO_DE_ENTRADA_AL_PROGRAMA = 3,
	MODIFICADOR_DE_ALMACENAMIENTO = 4,
	MODIFICADOR_DE_TIPO_DE_DATO = 5, 
	MODIFICADOR_VARIABLE_NUMERICA = 6,
	TIPOS_DE_DATOS_COMPUESTOS = 7
}categoria_t;


// LO UTILIZAMOS PARA LOS COMENTARIOS Y SABER SI SON DE LINEA O NO
typedef enum
{
	UNA_LINEA = 0,
	MULTIPLE_LINEAS = 1
}comentario_t;


// DEFINO LA ESTRUCTURA DE LA LISTA 
typedef struct
{
	char cadena[300];
	int entero;
}cadena_entero_t;

typedef struct nodo_cadena_entero_t
{
	cadena_entero_t info;
	struct nodo_cadena_entero_t * sig;
}nodo_cadena_entero_t;


// FUNCIONES A UTILIZAR 

void agregar_cadena_entero_al_final_con_repeticion (nodo_cadena_entero_t ** lista, cadena_entero_t cadena_entero);
void agregar_cadena_entero_al_final_con_repeticion_y_bandera (nodo_cadena_entero_t ** lista, cadena_entero_t cadena_entero, 
																					bool_t * hay_un_caracter_no_reconocido);
void imprimir_cadena_entero (nodo_cadena_entero_t * lista, char etiqueta_cadena[], char etiqueta_entero[], char cabecera[]);
void eliminar_lista_cadena_entero (nodo_cadena_entero_t * lista);
nodo_cadena_entero_t * buscar (nodo_cadena_entero_t * lista, cadena_entero_t cadena_entero);
void agregar_cadena_entero_sin_repeticion (nodo_cadena_entero_t ** lista, cadena_entero_t cadena_entero, void (*accion)(nodo_cadena_entero_t * aux));
int criterio_longitud (cadena_entero_t dato1, cadena_entero_t dato2);
int criterio_alfabetico (cadena_entero_t dato1, cadena_entero_t dato2);
void agregar_uno_a_entero (nodo_cadena_entero_t * nodo);
void desechar (nodo_cadena_entero_t * nodo);
void agregar_ordenado (nodo_cadena_entero_t ** lista, cadena_entero_t dato, int (*criterio)(cadena_entero_t dato1, cadena_entero_t dato2));
void agregar_cadena_entero_ordenado_sin_repeticion (nodo_cadena_entero_t ** lista, 
																	cadena_entero_t cadena_entero, 
																	void (*accion)(nodo_cadena_entero_t * aux), 
																	int (*criterio)(cadena_entero_t dato1,
																	cadena_entero_t dato2));
int strcmp_insensible (const char *s1, const char *s2);
void imprimir_palabra_reservada (nodo_cadena_entero_t * lista);
void imprimir_comentarios (nodo_cadena_entero_t * lista);
#endif
