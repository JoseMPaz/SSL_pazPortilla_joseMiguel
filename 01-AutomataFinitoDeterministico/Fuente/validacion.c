#include "validacion.h"

/*Verifica que se ingresen 2 argumentos seguido del nombre del ejecutable*/
bool_t verificar_argumentos_linea_comando (int argc, const char * argv[])
{
	/*En caso de que argv con cuenta con los 3 elemento
	nombre del ejecutable, nombre del archivo de entrada y 
	nombre del archivo de salidademite un mesaje de error y retorna un estado falso*/
	if (argc != 3)
	{
		puts (ERROR_CANTIDAD_ARGUMENTOS);
		return False;
	}
	return True;
}

/*Verifica que se pueda abrir el archivo en el modo de apertura solicitado,
en caso no poder emite un mensaje de error y devuelve falso*/
bool_t abrir_archivo (FILE ** ptr_archivo, const char * nombre_archivo, const char * modo_apertura)
{
	if ((*ptr_archivo = fopen (nombre_archivo, modo_apertura)) == NULL)
	{
		printf ("%s%s%c", ERROR_AL_ABRIR_ARCHIVO, nombre_archivo, SALTO_DE_LINEA);
		return False;
	}
	return True;
}

/*Cierra el flujo hacia un archivo abierto*/
void cerrar_archivo (FILE ** ptr_archivo)
{
	fclose (*ptr_archivo);
	return;
}
