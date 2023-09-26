/* Calculadora de notacion polaca inversa */
%{
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include "misFunciones.h"
#define MENSAJE_INGRESO_ENTER "Ingreso una linea vacia"
int yylex();
int yyerror (char *s);
extern FILE * yyin;
int yywrap()
{
	return(1);
}
%}

%token NUM

%% /* A continuacion las reglas gramaticales y las acciones */

input:    /* vacio */
        | input line
;

line:     '\n'					{ printf ("\t %s\n", MENSAJE_INGRESO_ENTER); }		
        | exp '\n'  			{ printf ("\t %d\n", $1); }
;

exp:      NUM					{ $$ = $1;         }
        | exp exp '+'      { $$ = $1 + $2;    }
        | exp exp '-'      { $$ = $1 - $2;    }
        | exp exp '*'      { $$ = $1 * $2;    }
        | exp exp '/'      { $$ = $1 / $2;    }
        | exp exp '^'      { $$ = pow ($1, $2); }

;
%%

int yyerror (char *s)  /* Llamada por yyparse ante un error */
{
  printf ("%s\n", s);
  return 1;
}

int main (int argc, const char * argv[])
{
	if (argc != 2)
	{
		puts ("Error: Se espera el nombre del archivo a analizar");
		return 1;
	}
	yyin = fopen (argv[1], "r");
	
#ifdef BISON_DEBUG
        yydebug = 1;
#endif

  yyparse ();
  return 0;
}
