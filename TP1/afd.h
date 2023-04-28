#ifndef _AFD_H_
#define _AFD_H_

#include <stdio.h>
#define DELIMITADOR ','
#define SALTO_DE_LINEA '\n'
#define RETORNO_DE_CARRO '\r'
#define FIN_DE_CADENA '\0'

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

void procesar_archivo (FILE * ptr_archivo_entrada, FILE * ptr_archivo_salida);
int Columna (char c);

#endif
