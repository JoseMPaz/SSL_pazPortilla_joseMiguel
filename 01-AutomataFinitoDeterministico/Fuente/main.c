/* TP 1: Automata Finito Deterministico
Autor: Paz Portilla Jose Miguel*/

/*Bibliotecas utilizadas*/
#include <stdlib.h>
#include "validacion.h"
#include "afd.h"

/* argv es la dirección de una vector que contiene los argumento(es decir palabras, tipo [char *]) que espera recibir el programa al momento de su ejecución.
argc es un entero que indica cantidad de argumento contenidas en el vector argv.
Cuando un programa no espera recibir argumento, entonces la cantidad de argumentos solo es 1(argc == 1) y en un primer elemento del vector
solo contendra el nombre del ejecutable(arg[0] == "nombre_del_ejecutable").
          ________________________
         |                        |
argv:    |"nombre_del_ejecutable" |    ----> argc == 1
         |________________________|
                 argv[0]
  
En nuestro trabajo practico valor a utilizar 2 argumentos por linea de comando más para indicarle al programa
el nombre del archivo a procesar(que llamaremos entrada.txt) 
y el nombre del archivo procesado(que llamaremos salidad.txt)
y llamaremos al ejecutable tp1
Entonces habran 3 argumentos, por lo tanto argc debe ser 3.
el vector de argumento contendra la siguiente informacion
         ________________________________________________________________________________
        |                      |                            |                            |
argv:   |        "tp1"         |        "entrada.txt"       |       "salidad.txt"        |         ----> argc == 3
        |______________________|____________________________|____________________________|          |
                argv[0]                   argv[1]                     argv[2]

Este programa se puede configurar en varios idiomas, 
basta con retirar el comentario del idioma que se quiere utilizar y comentar el que se utiliza actualmente en el archivo "configuracion.h"

Para generar el ejecutable se puede escribir en terminal:
gcc *.c -o tp1
o tambien si puede utilizar el archivo makefile y simplemente escribir en terminal:
make
Una vez obtenido el ejecutable tp1, se debe ejecutar pasandole los argumento por linea de comandos,
en este caso los nombres de los archivos de entrada y salida de la siguiente manera:
./tp1 entrada.txt salida.txt
*/

int main (int argc, const char * argv[])
{
	/*Esto 2 punteros a archivos permitiran trabajar tanto con el archivo a procesar y el archivo procesado*/
	FILE * ptr_archivo_entrada, * ptr_archivo_salida;
	/*Esta variable permitira cerrar el archivo de entrada en caso no se pueda abrir el archivo de salida*/
	bool_t estado_apertura = True;

	if (/*Se verifica que se ingresaron 3 argumentos para no caer desbordamientos*/
		verificar_argumentos_linea_comando (argc,argv) == False 
		/*Abre el archivo de entrada en modo lectura, en caso de no poder hacerlo muestra un mensaje del error y retorna el estado como falso*/
	|| abrir_archivo (&ptr_archivo_entrada,argv[1],"r") == False 
	/*Abre el archivo de salida en modo escritura, en caso de no poder hacerlo muestra un mensaje del error y retorna el estado como falso*/
	|| (estado_apertura = abrir_archivo (&ptr_archivo_salida,argv[2],"w")) == False)
	{
		/*Si no logra el archivo de salida*/
		if (estado_apertura == False)
			/*cierra el archivo de entrada que fue abierto previamente*/
			cerrar_archivo (&ptr_archivo_entrada);
		/*Avisa al sistema operativo que cerro el programa con una falla*/
		return EXIT_FAILURE;
	}
	
	/*Determina cada una de las palabras del archivo CSV("Comma Separated Values") y determina si forma 
	parte del lenguaje de los numeros decimales, octales y hexadecimales. 
	Imprime en el archivo de salida las cadena leida junto a la etiqueta correspondiente.
	Es decir si no forma parte del Lenguaje indica que la palabra es NO RECONOCIDA
	y si forma parte del lenguaje indica el tipo de numero que representa
	*/
	automata_finito_deterministico_multiple (ptr_archivo_entrada, ptr_archivo_salida);

	/*Una vez finalizado de procesar se deben cerrar los punteros a archivos*/
	cerrar_archivo (&ptr_archivo_entrada);
	cerrar_archivo (&ptr_archivo_salida);
	/*Avisa al sistema operativo que cerro el programa exitosamente*/
	return EXIT_SUCCESS;
}
