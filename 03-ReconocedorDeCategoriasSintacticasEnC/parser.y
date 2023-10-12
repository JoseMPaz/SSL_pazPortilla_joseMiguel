%{
#include <stdio.h>
#include <stdlib.h>
extern int yylex();
extern FILE * yyin;
extern int yyerror (char *s);

%}
%union
{
	char * sval;
	int ival;
}
%token INT
%token IDENTIFICADOR
%token PUNTO_Y_COMA
%token ABRE_PARENTESIS
%token CIERRA_PARENTESIS
%token ABRE_LLAVE
%token CIERRA_LLAVE
%token ASIGNACION
%token NUMBER
%left '+' '-'
%left '*' '/'

%%

programaC:
    | programaC declaracion_externa
    ;

declaracion_externa:
    definicion_de_funcion
    | declaracion_de_variables
    ;

definicion_de_funcion:
    INT IDENTIFICADOR ABRE_PARENTESIS lista_de_parametros CIERRA_PARENTESIS sentencia_compuesta
    {
        printf("Definicion de funcion: %s\n", $<sval>2);
    }
    ;

lista_de_parametros:
    /* sin parametros */
    | declaracion_de_parametro
    | lista_de_parametros ',' declaracion_de_parametro
    ;

declaracion_de_parametro:
    INT IDENTIFICADOR
    {
        printf("Parametro: %s\n", $<sval>2);
    }
    ;

declaracion_de_variables:
    INT lista_de_declaraciones_de_variables PUNTO_Y_COMA
    ;

lista_de_declaraciones_de_variables:
    	declaracion_inicial
    | lista_de_declaraciones_de_variables ',' declaracion_inicial
    ;

declaracion_inicial:
    	declarador
    | declarador ASIGNACION inicializador
    ;

declarador:
    IDENTIFICADOR
    ;

inicializador:
    expresion
    ;

sentencia_compuesta:
    ABRE_LLAVE CIERRA_LLAVE
    | ABRE_LLAVE lista_de_sentencias CIERRA_LLAVE
    ;

lista_de_sentencias:
    	sentencia
    | lista_de_sentencias sentencia
    ;

sentencia:
    	sentencia_de_expresion
    | sentencia_de_asignacion
    ;

sentencia_de_expresion:
    	PUNTO_Y_COMA
    | expresion PUNTO_Y_COMA
    ;

sentencia_de_asignacion:
    IDENTIFICADOR ASIGNACION expresion PUNTO_Y_COMA
    {
        printf("Asignacion: %s\n", $<sval>1);
    }
    ;

expresion:
    	NUMBER
    | IDENTIFICADOR
    | expresion '+' expresion
    | expresion '-' expresion
    | expresion '*' expresion
    | expresion '/' expresion
    | ABRE_PARENTESIS expresion CIERRA_PARENTESIS
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




