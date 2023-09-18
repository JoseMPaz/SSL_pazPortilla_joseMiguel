#ifndef _VALIDACION_H_
#define _VALIDACION_H_

#include <stdio.h>

#define SALTO_DE_LINEA '\n'
#define ERROR_CANTIDAD_ARGUMENTOS "Error de ingreso de argumentos, ingrese por terminal: ./tp2 <nombre_archivo_entrada>"
#define ERROR_AL_ABRIR_ARCHIVO "Error de apertura del archivo: "

typedef enum
{
	True = 1,
	False = 0
}booleano_t;

booleano_t verificar_argumentos_linea_comando (int argc, const char * argv[]);
booleano_t abrir_archivo (FILE ** ptr_archivo, const char * nombre_archivo,const char * modo_apertura);
void cerrar_archivo (FILE ** ptr_archivo);

#endif
