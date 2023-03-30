/*Este programa saluda por pantalla a la materia SSL*/
#include <stdio.h>
#define SALUDO "Hola Sintaxis y Semántica de los Lenguajes"

int main (void)
{
	/*Utilizo puts y no printf ya que utiliza menos recursos y no necesito agregar formato al texto*/
	puts (SALUDO);
	return 0;
}
