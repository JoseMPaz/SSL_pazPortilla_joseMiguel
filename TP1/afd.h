#ifndef _AFD_H_
#define _AFD_H_

#include <stdio.h>
#define DELIMITADOR ','
#define SALTO_DE_LINEA '\n'
#define RETORNO_DE_CARRO '\r'
#define FIN_DE_CADENA '\0'

typedef enum
{
	Q0 = 0,
	Q1 = 1,
	Q2 = 2,
	Q3 = 3,
	Q4 = 4,
	Q5 = 5,
	Q6 = 6
}estado_t;

void procesar_archivo (FILE * ptr_archivo_entrada, FILE * ptr_archivo_salida);
int Columna (int c);

#endif
