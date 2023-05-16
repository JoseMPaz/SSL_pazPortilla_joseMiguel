#include "afd.h"

/* La funcion automata_finito_deterministico_multiple se encarga de leer todo el archivo de entrada caracter por caracter
	Como el archivo de entrada contiene palabras separadas por coma(un archivo CSV, Comma Separated Values), entonces utilizo 2 estados del automata,
	uno indica el estado actual y el otro el estado anterior al actual, ambos inician en el estado inicial,
	de modo que va leyendo cada caracter y junto al estado anterior se ingresan a la funcion de transion,
	La funcion de transion devuelve el seguiente estado del automada y lo almacena en la variable actual.
	este estado actual es analizado luego de cada lectura de un caracter.
	Si el estado actual no es el INICIAL simplemente envia el caracter leido al archivo de salida y actualiza el estado anterior por el estado estado actual,
	mientras que si el estado actual si es el INICIAL, es porque el caracter leido era una coma o un fin de cadena o un salto de linea o un retorno de carro.
	es decir termino de leer una palabra, entonces revisa cual fue su estado anterior.
	Si su estado anterior no era un estado terminal, entonces escribe en el archivo de salida la etiqueta NO RECONOCIDA, 
	mientras que si su estado era el estado DECIMAL, escribe la etiqueta DECIMAL
	si era CERO_OCTAL o bien OCTAL, escribe la etiqueta OCTAL
	y si era HEXADECIMAL, escribe la etiqueta HEXADECIMAL, 
	por ultimo actualiza el estado anterior por el estado estado actual que en este caso deja a ambos en el estado INICIAL,
	de modo que pueda iniciar la lectura de una nueva palabra entre comas.	
*/
void automata_finito_deterministico_multiple (FILE * ptr_archivo_entrada, FILE * ptr_archivo_salida)
{
	/*Buffer para la lectura del archivo*/
	char caracter;
	/*Para contabilizar los caracteres leido, esto permite luego imprimir la etiqueta a cierta distancia de la palabra leida*/
	int contador_caracteres = 0;
	/*Estado del automata, se usaron 2 para poder identidicar el tipo de numero*/
	estado_t estado_anterior, estado_actual;	
	/*Se inicializan en INICIAL para que poder inicial el procesamiento*/
	estado_anterior = estado_actual = INICIAL;
	
	/*Lee el primer caracter para validar que no este vacio el archivo*/
	caracter = fgetc (ptr_archivo_entrada);
	
	/*Va analizar todos los caracteres mientras no encuentre el Final del Archivo(es decir el End Of File)*/
	while (caracter != EOF)
	{
		/*Transiciona al proximo estado*/
		estado_actual = funcion_de_transicion (estado_anterior, caracter);
		
		/*Si no es una coma, un fin de cadena, un salto de linea o un retorno de carro*/
		if (estado_actual != INICIAL)
		{
			/*Guarda el caracter leido en el archivo de salida e incrementa en uno al contador de caracteres*/
			escribir_caracter (&ptr_archivo_salida, &contador_caracteres, caracter);
			/*Actualiza el estado anterior por el estado actual*/
			actualizar_estado (&estado_anterior, estado_actual);
		}
		else
		{
			/*Imprime espacios y al final segun el estado final etiqueta a la palabra*/
			escribir_tipo_de_numero (&ptr_archivo_salida, &contador_caracteres, estado_anterior);
			actualizar_estado (&estado_anterior, estado_actual);
		}
		/*Lee un nuevo caracter del archivo de entrada*/
		caracter = fgetc (ptr_archivo_entrada);
	}
	return;
}
	
/*Dato la matriz de transicion del automata:

_________________________________________________________________________________________________________________________________________________
                        |               |              |              |                |                        |               |               |
TT                      |  0            |    [1-7]     |      8,9     |    [a-fA-F]    |      X,x               |      COMA     |     Otro      |
________________________|_______________|______________|______________|________________|________________________|_______________|_______________|
                        |               |              |              |                |                        |               |               |
INICIAL                 |  CERO_OCTAL   |   DECIMAL    |  DECIMAL     |   OTRO_ASCII   |      OTRO_ASCII        |    INICIAL    |  OTRO_ASCII   |
________________________|_______________|______________|______________|________________|________________________|_______________|_______________|
                        |               |              |              |                |                        |               |               |
DECIMAL                 |    DECIMAL    |   DECIMAL    |    DECIMAL   |   OTRO_ASCII   |     OTRO_ASCII         |    INICIAL    | OTRO_ASCII    |
________________________|_______________|______________|______________|________________|________________________|_______________|_______________|
                        |               |              |              |                |                        |               |               |
CERO_OCTAL              |    OCTAL      |    OCTAL     |  OTRO_ASCII  |   OTRO_ASCII   | HEXADECIMAL_INCONCLUSO |    INCIAL     |   OTRO_ASCII  |
________________________|_______________|______________|______________|________________|________________________|_______________|_______________|
                        |               |              |              |                |                        |               |               |
OCTAL                   |    OCTAL      |    OCTAL     |  OTRO_ASCII  |    OTRO_ASCII  |      OTRO_ASCII        |    INICIAL    | OTRO_ASCII    |
________________________|_______________|______________|______________|________________|________________________|_______________|_______________|
                        |               |              |              |                |                        |               |               |
HEXADECIMAL_INCONCLUSO  | HEXADECIMAL   | HEXADECIMAL  |  HEXADECIMAL |  HEXADECIMAL   |      OTRO_ASCII        |    INICIAL    |  OTRO_ASCII   |
________________________|_______________|______________|______________|________________|________________________|_______________|_______________|
                        |               |              |              |                |                        |               |               |
HEXADECIMAL             | HEXADECIMAL   | HEXADECIMAL  |  HEXADECIMAL |  HEXADECIMAL   |      OTRO_ASCII        |    INICIAL    |  OTRO_ASCII   |
________________________|_______________|______________|______________|________________|________________________|_______________|_______________|
                        |               |              |              |                |                        |               |               |
OTRO_ASCII              |  OTRO_ASCII   |  OTRO_ASCII  |   OTRO_ASCII |   OTRO_ASCII   |       OTRO_ASCII       |    INICIAL    |  OTRO_ASCII   |
________________________|_______________|______________|______________|________________|________________________|_______________|_______________|

Esta funcion asigna un posicion en la columna segun el caracter indicado.
*/
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

/*Esta funcion devuelve la posicion en una matriz de estados, 
las filas seran el estado anterior y las columnas seran establecidas por el caracter*/
estado_t funcion_de_transicion  (estado_t estado_anterior, char caracter)
{
	/*Tabla de transiciones*/
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

/*Escribe el caracter leido en el archivo de salida e incrementa el contador de caracteres en 1*/
void escribir_caracter (FILE ** ptr_archivo_salida, int * contador_caracteres, char caracter)
{
	fprintf (*ptr_archivo_salida,"%c",caracter);
	(*contador_caracteres)++;

	return;
}

/*Escribe espacios luego de cada palabra leida, seguido de una etiqueta que indica
 si el palabra pertenece al lenguaje de los decimales, octales y hexadecimales
 o bien indica que tipo de numero representa la palabra
*/
void escribir_tipo_de_numero (FILE ** ptr_archivo_salida, int * contador_caracteres, estado_t  estado_anterior)
{
	int i;
	
	/*Agrega espacios de ancho POSICION_INICIO_TIPO_NUMERO a la derecha de la palabra leida*/
	for (i = 0;i < (POSICION_INICIO_TIPO_NUMERO - *contador_caracteres) ;i++)
		fprintf (*ptr_archivo_salida, "%c" ,ESPACIO);
	
	/*Agrega la equiqueta del tipo de numero al final de los espacios seguido de un salto de linea*/
	escribir_etiqueta (estado_anterior, ptr_archivo_salida);
		
	/*Vuelve a colocar el contador a cero para la proxima palabra leida*/
	*contador_caracteres = 0;

	return;
}

/*Actualiza el estado anterior por el estado actual*/
void actualizar_estado (estado_t * estado_anterior, estado_t  estado_actual)
{
	*estado_anterior = estado_actual;
	return;
}

/*Segun el estado anterior, escribe en el archivo de salida el tipo de numero que representa 
o si no representa ninguna palabra del lenguaje*/
void escribir_etiqueta (estado_t estado_anterior, FILE ** ptr_archivo_salida)
{
	if (estado_anterior == DECIMAL)
		fprintf (*ptr_archivo_salida,"%s%c", NUMERO_DECIMAL,SALTO_DE_LINEA);
	else if (estado_anterior == CERO_OCTAL || estado_anterior == OCTAL)
		fprintf (*ptr_archivo_salida,"%s%c", NUMERO_OCTAL,SALTO_DE_LINEA);
	else if (estado_anterior == HEXADECIMAL)
		fprintf (*ptr_archivo_salida,"%s%c", NUMERO_HEXADECIMAL,SALTO_DE_LINEA);
	else
		fprintf (*ptr_archivo_salida,"%s%c", NUMERO_NO_RECONOCIDO,SALTO_DE_LINEA);
	return;
}
