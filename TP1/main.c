#include <stdio.h>

typedef enum
{
	True = 1,
	False = 0
}bool_t;

bool_t verificar_argumentos_lineas_comandos (int argc, char * argv[]);

int main (int argc, char * argv[])
{
	if (verificar_argumentos_lineas_comandos (argc,argv) == False)
	{
		puts ("Error de ingresp de argumentos, ingresar: ./tp1 <nombre_archivo_entrada> <_nombre_archivo_salida>");
		return 1;
	}

	return 0;
}

bool_t verificar_argumentos_lineas_comandos (int argc, char * argv[])
{
	if (argc != 3)
		return False;
	return True;
}
