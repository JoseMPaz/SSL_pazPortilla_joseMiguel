#include "afd.h"

void procesar_archivo (FILE * ptr_archivo_entrada, FILE * ptr_archivo_salida)
{
	char caracter;
	int contador_caracteres = 0;
	estado_t estado_anterior, estado_actual;	
	estado_anterior = estado_actual = INICIAL;
	caracter = fgetc (ptr_archivo_entrada);
	while (caracter != EOF)
	{
		estado_actual = actualizar_estado (estado_anterior, caracter);
		if (estado_actual != INICIAL)
			escribir_caracter (&ptr_archivo_salida, &contador_caracteres, caracter, &estado_actual, &estado_anterior);
		else
			escribir_tipo_de_numero (&ptr_archivo_salida, &contador_caracteres, &estado_actual, &estado_anterior);
		caracter = fgetc (ptr_archivo_entrada);
	}
	return;
}
	
int asignar_columna (char caracter)
{	
	if (caracter == CERO)
		return 0;
	if (caracter >= UNO && caracter <= SIETE)
		return 1;
	if (caracter == OCHO||caracter == NUEVE)
		return 2;
	if ( (toupper (caracter) >= LETRA_A) && (toupper (caracter) <= LETRA_F) )
		return 3;
	if (toupper (caracter) == LETRA_X)
		return 4;
	if (caracter == DELIMITADOR ||caracter ==SALTO_DE_LINEA ||caracter ==RETORNO_DE_CARRO ||caracter == FIN_DE_CADENA)
		return 5;
		
	return 6;
}

estado_t actualizar_estado (estado_t estado_anterior, char caracter)
{
	estado_t tabla_de_transiciones[CANTIDAD_DE_ESTADOS][CANTIDAD_DE_COLUMNAS]={ 
		{CERO_OCTAL,DECIMAL ,DECIMAL ,OTRO_ASCII,OTRO_ASCII,INICIAL,OTRO_ASCII},
		{DECIMAL,DECIMAL,DECIMAL,OTRO_ASCII,OTRO_ASCII,INICIAL,OTRO_ASCII},
		{OCTAL,OCTAL,OTRO_ASCII,OTRO_ASCII,HEXADECIMAL_INCONCLUSO,INICIAL,OTRO_ASCII},
		{OCTAL,OCTAL,OTRO_ASCII,OTRO_ASCII,OTRO_ASCII,INICIAL,OTRO_ASCII},
		{HEXADECIMAL,HEXADECIMAL,HEXADECIMAL,HEXADECIMAL,OTRO_ASCII,INICIAL,OTRO_ASCII},
		{HEXADECIMAL,HEXADECIMAL,HEXADECIMAL,HEXADECIMAL,OTRO_ASCII,INICIAL,OTRO_ASCII},
		{OTRO_ASCII,OTRO_ASCII,OTRO_ASCII,OTRO_ASCII,OTRO_ASCII,INICIAL,OTRO_ASCII}};
														
	return tabla_de_transiciones[(int)estado_anterior][asignar_columna(caracter)];
}

void escribir_caracter (FILE ** ptr_archivo_salida, int * contador_caracteres, char caracter, estado_t * estado_actual, estado_t * estado_anterior)
{
	fprintf (*ptr_archivo_salida,"%c",caracter);
	(*contador_caracteres)++;
	*estado_anterior = *estado_actual;
	return;
}

void escribir_tipo_de_numero (FILE ** ptr_archivo_salida, int * contador_caracteres, estado_t * estado_actual, estado_t * estado_anterior)
{
	int i;
	
	for (i = 0;i < (POSICION_INICIO_TIPO_NUMERO - *contador_caracteres) ;i++)
		fprintf (*ptr_archivo_salida, "%c" ,ESPACIO);
	
	if (*estado_anterior == DECIMAL)
		fprintf (*ptr_archivo_salida,"%s%c", NUMERO_DECIMAL,SALTO_DE_LINEA);
	else if (*estado_anterior == CERO_OCTAL || *estado_anterior == OCTAL)
		fprintf (*ptr_archivo_salida,"%s%c", NUMERO_OCTAL,SALTO_DE_LINEA);
	else if (*estado_anterior == HEXADECIMAL)
		fprintf (*ptr_archivo_salida,"%s%c", NUMERO_HEXADECIMAL,SALTO_DE_LINEA);
	else
		fprintf (*ptr_archivo_salida,"%s%c", NUMERO_NO_RECONOCIDO,SALTO_DE_LINEA);
	*contador_caracteres = 0;
	*estado_anterior = *estado_actual;
	return;
}
