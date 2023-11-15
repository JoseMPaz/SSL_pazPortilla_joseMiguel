#ifndef _ERRORES_H_
#define _ERRORES_H_

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
	int nro_linea;
}error_t;

typedef struct nodo_error_t
{
	error_t info;
	struct nodo_error_t * sig;
}nodo_error_t;


// FUNCIONES A UTILIZAR 

void agregar_error_al_final_con_repeticion (nodo_error_t ** lista, error_t error);
void agregar_error_al_final_con_repeticion_y_bandera (nodo_error_t ** lista, error_t error, 
																					bool_t * hay_un_caracter_no_reconocido);
void imprimir_errores_lexicos(nodo_error_t * lista, char etiqueta_cadena[], char etiqueta_nro_linea[], char cabecera[]);
void imprimir_errores_sintacticos(nodo_error_t * lista, char etiqueta_cadena[], char etiqueta_nro_linea[], char cabecera[]);
void eliminar_lista_errores (nodo_error_t * lista);
nodo_error_t * buscar (nodo_error_t * lista, error_t error);
void agregar_error_sin_repeticion (nodo_error_t ** lista, error_t error, void (*accion)(nodo_error_t * aux));
int criterio_longitud (error_t dato1, error_t dato2);
int criterio_alfabetico (error_t dato1, error_t dato2);
void agregar_uno_a_error (nodo_error_t * nodo);
void desechar (nodo_error_t * nodo);
void agregar_ordenado (nodo_error_t ** lista, error_t dato, int (*criterio)(error_t dato1, error_t dato2));
void agregar_error_ordenado_sin_repeticion (nodo_error_t ** lista, 
																	error_t error, 
																	void (*accion)(nodo_error_t * aux), 
																	int (*criterio)(error_t dato1,
																	error_t dato2));
int strcmp_insensible (const char *s1, const char *s2);
void imprimir_palabra_reservada (nodo_error_t * lista);
void imprimir_comentarios (nodo_error_t * lista);

#endif
