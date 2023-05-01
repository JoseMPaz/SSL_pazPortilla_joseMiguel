#include <stdlib.h>
#include "validacion.h"
#include "afd.h"

int main (int argc, const char * argv[])
{
	FILE * ptr_archivo_entrada, * ptr_archivo_salida;
	bool_t estado_apertura = True;

	if (verificar_argumentos_linea_comando (argc,argv) == False 
	|| abrir_archivo (&ptr_archivo_entrada,argv[1],"r") == False 
	|| (estado_apertura = abrir_archivo (&ptr_archivo_salida,argv[2],"w")) == False)
	{
		if (estado_apertura == False)
			cerrar_archivo (&ptr_archivo_entrada);
		return EXIT_FAILURE;
	}

	procesar_archivo (ptr_archivo_entrada, ptr_archivo_salida);

	cerrar_archivo (&ptr_archivo_entrada);
	cerrar_archivo (&ptr_archivo_salida);
	return EXIT_SUCCESS;
}
