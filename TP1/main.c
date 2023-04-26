#include <stdio.h>
#include "afd.h"

typedef enum
{
	True = 1,
	False = 0
}bool_t;

bool_t verificar_argumentos_lineas_comandos (int argc, char * argv[]);
bool_t abrir_archivo (FILE ** ptr_archivo, char * nombre_archivo,char * modo_apertura);
void cerrar_archivo (FILE ** ptr_archivo);


int main (int argc, char * argv[])
{
	FILE * ptr_archivo_entrada, * ptr_archivo_salida;

	if (verificar_argumentos_lineas_comandos (argc,argv) == False)
	{
		puts ("Error de ingreso de argumentos, ingresar: ./tp1 <nombre_archivo_entrada> <_nombre_archivo_salida>");
		return 1;
	}

	if (abrir_archivo (&ptr_archivo_entrada,argv[1],"r") == False)
	{
		printf ("%s%s","Error de apertura del archivo ",argv[1]);
		return 1;
	}

	if (abrir_archivo (&ptr_archivo_salida,argv[2],"w") == False)
	{
		printf ("%s%s","Error de apertura del archivo ",argv[2]);
		
		cerrar_archivo (&ptr_archivo_entrada);
		return 1;
	}

	procesar_archivo (ptr_archivo_entrada, ptr_archivo_salida);

	cerrar_archivo (&ptr_archivo_entrada);
	cerrar_archivo (&ptr_archivo_salida);
	return 0;
}

bool_t verificar_argumentos_lineas_comandos (int argc, char * argv[])
{
	if (argc != 3)
		return False;
	return True;
}

bool_t abrir_archivo (FILE ** ptr_archivo, char * nombre_archivo,char * modo_apertura)
{
	if ((*ptr_archivo = fopen (nombre_archivo,modo_apertura)) == NULL)
		return False;
	return True;
}

void cerrar_archivo (FILE ** ptr_archivo)
{
	fclose (*ptr_archivo);
	return;
}
