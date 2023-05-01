#include "validacion.h"

bool_t verificar_argumentos_linea_comando (int argc, const char * argv[])
{
	if (argc != 3)
	{
		puts ("Error de ingreso de argumentos, ingresar: ./tp1 <nombre_archivo_entrada> <_nombre_archivo_salida>");
		return False;
	}
	return True;
}

bool_t abrir_archivo (FILE ** ptr_archivo, const char * nombre_archivo, const char * modo_apertura)
{
	if ((*ptr_archivo = fopen (nombre_archivo,modo_apertura)) == NULL)
	{
		printf ("%s%s%c","Error de apertura del archivo ", nombre_archivo, SALTO_DE_LINEA);
		return False;
	}
	return True;
}

void cerrar_archivo (FILE ** ptr_archivo)
{
	fclose (*ptr_archivo);
	return;
}
