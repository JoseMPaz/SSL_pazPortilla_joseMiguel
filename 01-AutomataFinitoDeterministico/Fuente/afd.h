#ifndef _AFD_H_
#define _AFD_H_

#include <stdio.h>
#include <ctype.h>
#include "idioma.h"

#define DELIMITADOR ','
#define SALTO_DE_LINEA '\n'
#define RETORNO_DE_CARRO '\r'
#define FIN_DE_CADENA '\0'
#define ESPACIO ' '
#define POSICION_INICIO_TIPO_NUMERO 15
#define CERO '0'
#define UNO '1'
#define SIETE '7'
#define OCHO '8'
#define NUEVE '9'
#define LETRA_X 'X'
#define LETRA_A 'A'
#define LETRA_F 'F'
#define CANTIDAD_DE_ESTADOS 7
#define CANTIDAD_DE_COLUMNAS 7

/*Estados del automata*/
typedef enum
{
	INICIAL = 0,
	DECIMAL = 1,
	CERO_OCTAL = 2,
	OCTAL = 3,
	HEXADECIMAL_INCONCLUSO = 4,
	HEXADECIMAL = 5,
	OTRO_ASCII = 6
}estado_t;

/*Prototipo de funciones*/
void automata_finito_deterministico_multiple (FILE * ptr_archivo_entrada, FILE * ptr_archivo_salida);
int asignar_columna (char caracter);
estado_t funcion_de_transicion (estado_t estado_anterior, char caracter);
void escribir_caracter (FILE ** ptr_archivo_salida, int * contador_caracteres, char caracter);
void escribir_tipo_de_numero (FILE ** ptr_archivo_salida, int * contador_caracteres, estado_t  estado_anterior);
void actualizar_estado (estado_t * estado_anterior, estado_t  estado_actual);
void escribir_etiqueta (estado_t estado_anterior, FILE ** ptr_archivo_salida);

#endif
