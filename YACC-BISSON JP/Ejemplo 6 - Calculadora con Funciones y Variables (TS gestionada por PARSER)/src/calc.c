#include "calc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definición de la función putsym

simbolo_t * establecer_simbolo (char const * nombre_de_simbolo , int tipo_de_simbolo)
{
  simbolo_t *auxiliar = (simbolo_t *) malloc (sizeof (simbolo_t));
  
  auxiliar->nombre = (char *) malloc (	(sizeof(char *)) * (strlen (nombre_de_simbolo) + 1));
  strcpy ( auxiliar->nombre , nombre_de_simbolo );
  auxiliar->tipo = tipo_de_simbolo;
  auxiliar->valor.variable = TYP_VAR;
  auxiliar->next = (simbolo_t *) tabla_de_simbolos;
  tabla_de_simbolos = auxiliar;
  
  return auxiliar;
}

//Definición de la función getsym

simbolo_t * obtener_simbolo (char const * nombre_de_simbolo)
{
 	simbolo_t * auxiliar;
	for (auxiliar = tabla_de_simbolos; auxiliar != NULL; auxiliar = auxiliar->next)
		if (strcmp (auxiliar->nombre, nombre_de_simbolo) == 0)
			return auxiliar;

  return NULL;
}
