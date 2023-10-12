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

%token TIPO_DE_DATO
%token ESPECIFICADOR_DE_CATEGORIA_DE_ALMACENAMIENTO
%token IDENTIFICADOR
%token CONSTANTE_DECIMAL
%token ASIGNACION
%token OPERADOR_LOGICO_O
%token OPERADOR_LOGICO_Y
%token OPERADOR_IGUALDAD
%token OPERADOR_DISTINTO
%token MENOR_O_IGUAL
%token MAYOR_O_IGUAL
%token DESPLAZAMIENTO_A_IZQUIERDA
%token DESPLAZAMIENTO_A_DERECHA
%token INCREMENTO
%token DECREMENTO
%token SIZEOF
%token APUNTA

//Menor Precedencia
%left '+' '-'
%left '*' '/'
//Mayor Precedencia
%%

unidad_de_traduccion:		declaracion_externa	
								|	unidad_de_traduccion declaracion_externa
;

declaracion_externa:			definicion_de_funcion
								|	declaracion
;

definicion_de_funcion:	especificadores_de_declaracion declarador '(' lista_de_parametros ')' sentencia_compuesta
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
    especificadores_de_declaracion IDENTIFICADOR
    {
        printf("Parametro: %s\n", $<sval>2);
    }
    ;

declaracion:	especificadores_de_declaracion lista_de_declaraciones_de_variables ';'
;

lista_de_declaraciones_de_variables:
    	declaracion_inicial
    | lista_de_declaraciones_de_variables ',' declaracion_inicial
    ;

declaracion_inicial:
    	declarador
    | declarador ASIGNACION inicializador
    ;

declarador:		IDENTIFICADOR
    ;

inicializador:
    expresion
    ;

sentencia_compuesta:		'{' '}'
    						|	'{' lista_de_sentencias '}'
;

lista_de_sentencias:
    	sentencia
    | lista_de_sentencias sentencia
    ;

sentencia:
    	sentencia_de_expresion
    	|	sentencia_de_asignacion
   
sentencia_de_expresion:		';'
    							|	expresion ';'
;

    
especificadores_de_declaracion:	ESPECIFICADOR_DE_CATEGORIA_DE_ALMACENAMIENTO
										|	ESPECIFICADOR_DE_CATEGORIA_DE_ALMACENAMIENTO	especificadores_de_declaracion		
										|	TIPO_DE_DATO	
										|	TIPO_DE_DATO especificadores_de_declaracion								
;

sentencia_de_asignacion:
    IDENTIFICADOR ASIGNACION expresion ';'
    {
        printf("Asignacion: %s\n", $<sval>1);
    }
    ;
    
expresion:		IDENTIFICADOR
				|	CONSTANTE_DECIMAL
				| expresion '+' expresion
   			 | expresion '-' expresion
    			| expresion '*' expresion
   			 | expresion '/' expresion
				| '(' expresion ')'
;



%%

int main (int argc, const char * argv[])
{
#ifdef BISON_DEBUG
        yydebug = 1;
#endif
	if (argc != 2)
	{
		puts ("Error: Se espera el nombre del archivo a analizar");
		return 1;
	}
	yyin = fopen (argv[1], "r");
	
  yyparse ();
  return 0;
}




