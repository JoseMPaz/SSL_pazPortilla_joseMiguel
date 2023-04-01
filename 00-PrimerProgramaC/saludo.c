/*Este programa saluda por pantalla a la materia SSL en distintos idiomas*/
#include <stdio.h>
#include "idioma.h"

int main (void)
{
	/*Utilizo puts y no printf ya que utiliza menos recursos y no necesito agregar formato al texto*/
	puts (SALUDO);
	return 0;
}
