//Programa de prueba del TP2
/* Facultad Regional Buenos Aires
	Materia: SSL
	Codigo: K2052
	Grupo: 11*/
#include <stdio.h>
#include <stdlib.h>
#define MENSAJE_ERROR_ARGUMENTOS "Error: El programa no espera argumentos por la linea de comandos"
#define COMANDO_DE_EJECUCION "Para ejecutar el programa utilizar: "
#define PI 3.14
#define CANTIDAD_DE_ARGUMENTOS_PERMITIDOS 1
#define LONGITUD_VECTOR_ENTERO 5
#define MENSAJE_DE_SUMA_TOTAL "La suma acumulada es: "
#define NUMERO_DECIMAL "decimal: "
#define NUMERO_OCTAL "octal: "
#define NUMERO_HEXADECIMAL "hexadecimal: "
#define NUMERO_NEGATIVO "Numero negativo: "
#define NUMERO_REAL "Numero real: "
#define CONSTANTE_CARACTER "Constante caracter: "

float acumular (float valor);

int main (int argc, const char * argv[]) 
{
	float total = 0;
	unsigned int numeros[LONGITUD_VECTOR_ENTERO] = {1,2,3,4,5}, i;
	int octal1 = 010, octal2 = 011, octal3 = 012;
	int hexadecimal1 = 0x10, hexadecimal2 = 0X11, hexadecimal3 = 0x12, hexadecimal4 = 0xF;
	int numero_negativo = -45;
	float real1 = 25.3, real2 = 78.1, real3 = -42.4;
	char caracter1 = '@', caracter2 = '?';
	
	if (argc != CANTIDAD_DE_ARGUMENTOS_PERMITIDOS)
	{
		puts (MENSAJE_ERROR_ARGUMENTOS);
		return EXIT_FAILURE;
	}
	
	printf ("%s%s\n", COMANDO_DE_EJECUCION, argv[0]);
	
	for ( i = 0; i < LONGITUD_VECTOR_ENTERO; i++)
	{
		total = total + acumular( (float) numeros[i] );
	}
	//Es como sumar (1) + (1+2) + (1+2+3) + (1+2+3+4) + (1+2+3+4+5) = 35
	printf ("%s%.3f\n", MENSAJE_DE_SUMA_TOTAL, total);
	//Muentra un numero octal en base 8 y en base 10
	printf ("%s%-9o%s%d\n", NUMERO_OCTAL, octal1, NUMERO_DECIMAL, octal1);
	printf ("%s%-9o%s%d\n", NUMERO_OCTAL, octal2, NUMERO_DECIMAL, octal2);
	printf ("%s%-9o%s%d\n", NUMERO_OCTAL, octal3, NUMERO_DECIMAL, octal3);
	//Muestra un numero hexadecimal en base 16 y en base 10
	printf ("%s%-9x%s%d\n", NUMERO_HEXADECIMAL, hexadecimal1, NUMERO_DECIMAL, hexadecimal1);
	printf ("%s%-9x%s%d\n", NUMERO_HEXADECIMAL, hexadecimal2, NUMERO_DECIMAL, hexadecimal2);
	printf ("%s%-9x%s%d\n", NUMERO_HEXADECIMAL, hexadecimal3, NUMERO_DECIMAL, hexadecimal3);
	printf ("%s%-9x%s%d\n", NUMERO_HEXADECIMAL, hexadecimal4, NUMERO_DECIMAL, hexadecimal4);
	printf ("%s%-9X%s%d\n", NUMERO_HEXADECIMAL, hexadecimal4, NUMERO_DECIMAL, hexadecimal4);
	//Muestro un numero negativo
	printf ("%s%d\n", NUMERO_NEGATIVO, numero_negativo);
	//Numeros reales con 3 decimales
	printf ("%s%.3f\n",NUMERO_REAL, real1);
	printf ("%s%.3f\n",NUMERO_REAL, real2);
	printf ("%s%.3f\n",NUMERO_REAL, real3);
	//Constantes caracteres
	printf ("%s%c\n", CONSTANTE_CARACTER,caracter1);
	printf ("%s%c\n", CONSTANTE_CARACTER,caracter2);
	printf ("%s%c\n", CONSTANTE_CARACTER,'c');
	
	// CARACTER_NO_RECONOCIDOS: Se deben hacer un comentario multilinea para que este programa funcione
	
	@
	$
	@@$
	#@

	return EXIT_SUCCESS;
}

/*Esta funcion utiliza una variable estatica,
esto quiere decir que solo la primera vez se inicializa en 0
y en los proximos llamado conserva el valor anterior*/
float acumular (float valor)
{
	static float acumulardor = 0;
	
	if (acumulardor == 0)
		acumulardor = valor;
	else
		acumulardor += valor;
		
	return acumulardor;
}

