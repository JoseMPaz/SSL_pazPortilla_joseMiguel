/* Calculadora de notacion polaca inversa */
%{
#include <math.h>
#include <stdio.h>

int yyerror (char *s);
int yywrap();
extern int yylex();
extern FILE * yyin;

%}

%token NUMERO

%% /* A continuacion las reglas gramaticales y las acciones */

entrada:	/* sin entrada */
        | 	entrada linea
;

linea:     '\n'								{ printf ("%s\n", "Linea vacia"); }		
        | expresion '\n'  					{ printf ("%d\n", $1); }
;

expresion:		NUMERO								{ $$ = $1;         	}
        		|	expresion expresion '+' 		{ $$ = $1 + $2;    	}
        		|	expresion expresion '-'      	{ $$ = $1 - $2;    	}
        		|	expresion expresion '*'      	{ $$ = $1 * $2;    	}
        		|	expresion expresion '/'      	{ $$ = $1 / $2;    	}
        		|	expresion expresion '^'      	{ $$ = pow ($1, $2); }
;
%%

int main (int argc, const char * argv[])
{
	if (argc != 2)
	{
		puts ("Error: Se espera el nombre del archivo a analizar");
		return 1;
	}
	yyin = fopen (argv[1], "r");
	
	yyparse ();
  
	return 0;
}

int yyerror (char *s)  /* Llamada por yyparse ante un error */
{
  printf ("%s\n", s);
  return 1;
}

int yywrap()
{
	return(1);
}


