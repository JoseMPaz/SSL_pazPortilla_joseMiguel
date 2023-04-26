#include "afd.h"

void procesar_archivo (FILE * ptr_archivo_entrada, FILE * ptr_archivo_salida)
{
	char letra;
	//char * tipo_numero = {"DECIMAL","OCTAL","HEXADECIMAL","NA"};
	
	while ((letra = fgetc (ptr_archivo_entrada)) != EOF)
		fprintf (ptr_archivo_salida,"%c",letra);


}
