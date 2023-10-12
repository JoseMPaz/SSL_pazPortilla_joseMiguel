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

%token <sval> TIPO_DE_DATO IDENTIFICADOR
%token <ival> CONSTANTE_DECIMAL
%token TIPO_CALIFICADOR
%token ESPECIFICADOR_DE_CATEGORIA_DE_ALMACENAMIENTO
%token ASIGNACION_COMPUESTA
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
%token CASE
%token DEFAULT

//Menor Precedencia
%right '='
%left '+' '-'
%left '*' '/' '%'
%left '^'
%left '(' ')'
%left '<' '>'
%left '?' ':'
%left OPERADOR_LOGICO_O
%left OPERADOR_LOGICO_Y
%left '|'
%left '&'
%left OPERADOR_IGUALDAD OPERADOR_DISTINTO
%left MENOR_O_IGUAL MAYOR_O_IGUAL
%left DESPLAZAMIENTO_A_DERECHA DESPLAZAMIENTO_A_IZQUIERDA
%left '~' '!'
%left '[' ']'
%left '{' '}'

//Mayor Precedencia
%%

unidad_de_traduccion:		
		declaracion_externa	
	|	unidad_de_traduccion declaracion_externa
;//ok

declaracion_externa:			
		definicion_de_funcion
	|	declaracion
;//ok

definicion_de_funcion:	
		declarador sentencia_compuesta
	|	declarador lista_de_declaraciones sentencia_compuesta
	|	especificadores_de_declaracion declarador sentencia_compuesta
	|	especificadores_de_declaracion declarador lista_de_declaraciones sentencia_compuesta
;//ok

declaracion:
		especificadores_de_declaracion ';'
	|	especificadores_de_declaracion lista_de_declaraciones_iniciales ';'
;//ok

lista_de_declaraciones: 
			declaracion
		|	lista_de_declaraciones declaracion
;//ok

especificadores_de_declaracion:	ESPECIFICADOR_DE_CATEGORIA_DE_ALMACENAMIENTO
										|	ESPECIFICADOR_DE_CATEGORIA_DE_ALMACENAMIENTO	especificadores_de_declaracion		
										|	TIPO_DE_DATO	
										|	TIPO_DE_DATO especificadores_de_declaracion	
										|	TIPO_CALIFICADOR
										|	TIPO_CALIFICADOR especificadores_de_declaracion							
;//ok ACA FALTA AGREGAR TIPOS UNION STRUCT ...


lista_de_declaraciones_iniciales:
		declaracion_inicial
	|	lista_de_declaraciones_iniciales ',' declaracion_inicial
;//ok

declaracion_inicial:
		declarador
	|	declarador '=' inicializador
;//ok

declarador:		
		declaracion_directa
	| punteros declaracion_directa
;//ok

declaracion_directa:
		IDENTIFICADOR
	|	'(' IDENTIFICADOR ')'
	|	declaracion_directa '[' ']'
	|	declaracion_directa '[' expresion ']'
	|	declaracion_directa '(' lista_de_tipos_de_parametros ')' { printf("Funcion: %s\n", $<sval>1); }
	|	declaracion_directa '(' ')'
	|	declaracion_directa '(' lista_de_identificadores ')'
;//ok FALTA MODIFICAR EXPRESION

punteros:
		'*'
	|	'*' lista_de_tipos_calificadores
	|	'*' punteros
	|	'*' lista_de_tipos_calificadores punteros
;//ok

lista_de_tipos_calificadores:
		TIPO_CALIFICADOR
	|	lista_de_tipos_calificadores TIPO_CALIFICADOR
;//ok

lista_de_tipos_de_parametros:
		lista_de_parametros
	|	lista_de_parametros lista_de_tipos_de_parametros
;//ok

lista_de_parametros:
		declaracion_de_parametro 
	|	lista_de_parametros ',' declaracion_de_parametro
;//ok

declaracion_de_parametro:
		especificadores_de_declaracion declarador { printf("Parametro: %s\n", $<sval>2); }
;//ok
		
lista_de_identificadores:
		IDENTIFICADOR
	|	lista_de_identificadores ',' IDENTIFICADOR
;//ok

inicializador:
		expresion
    |	'{' lista_de_inicializadores '}'
;//ok FALTA MODIFICAR EXPRESION

lista_de_inicializadores:
		inicializador
	| lista_de_inicializadores inicializador
;//ok

sentencia:
		sentencia_de_seleccion_multiple	
	|	sentencia_de_expresion
	|	sentencia_de_asignacion
  	|	sentencia_compuesta
;//ok INCOMPLETO

sentencia_de_seleccion_multiple:
		IDENTIFICADOR ':' sentencia
	|	CASE expresion ':' sentencia
	|	DEFAULT ':' sentencia
;//ok

sentencia_de_expresion:		
		';'
	|	expresion ';'
;//ok

sentencia_compuesta:		'{' '}'
    						|	'{' lista_de_sentencias '}'
    						|	'{' lista_de_declaraciones '}' 
    						|	'{' lista_de_declaraciones lista_de_sentencias '}' 
;//ok

lista_de_sentencias:
		sentencia
	|	lista_de_sentencias sentencia
;//ok

//FALTA AGREGAR MAS SENTENCIAS

sentencia_de_asignacion:
		IDENTIFICADOR '=' expresion ';'
    {
        printf("Asignacion: %s\n", $<sval>1);
    }
    ;
    
expresion:	
		IDENTIFICADOR
				|	CONSTANTE_DECIMAL
				| expresion '+' expresion
   			 | expresion '-' expresion
    			| expresion '*' expresion
   			 | expresion '/' expresion
				| '(' expresion ')'
;
/*
expresion_de_asignacion:
	IDENTIFICADOR '=' expresion ';'
	//	expresion_condicional	
	//|	expresion_unaria operador_de_asignacion expresion_de_asignacion
;*/
/*
operador_de_asignacion:
		'='
	|	ASIGNACION_COMPUESTA
;
*/
//***********
/*
expresion_condicional:		
		expresion_logica_o
	|	expresion_logica_o '?' expresion ':' expresion_condicional
;

expresion_logica_o: 		
		expresion_logica_y
	|	expresion_logica_o OPERADOR_LOGICO_O expresion_logica_y
;

expresion_logica_y:	
		expresion_inclusiva_o
	|	expresion_logica_y OPERADOR_LOGICO_Y expresion_inclusiva_o
;

expresion_inclusiva_o: 
		expresion_exclusiva_o
	|	expresion_inclusiva_o '|' expresion_exclusiva_o
;

expresion_exclusiva_o: 	
		expresion_y
	|	expresion_exclusiva_o '^' expresion_y
;

expresion_y: 
		expresion_de_igualdad
	|	expresion_y '&' expresion_de_igualdad
;

expresion_de_igualdad:	
		expresion_relacional
	|	expresion_de_igualdad OPERADOR_IGUALDAD expresion_relacional
	|	expresion_de_igualdad OPERADOR_DISTINTO expresion_relacional
;
			
expresion_relacional: 
		expresion_de_desplazamiento
	|	expresion_relacional '<' expresion_de_desplazamiento	
	|	expresion_relacional '>' expresion_de_desplazamiento
	|	expresion_relacional MENOR_O_IGUAL expresion_de_desplazamiento
	|	expresion_relacional MAYOR_O_IGUAL expresion_de_desplazamiento
;

expresion_de_desplazamiento: 
		expresion_aditiva
	|	expresion_de_desplazamiento DESPLAZAMIENTO_A_IZQUIERDA expresion_aditiva
	|	expresion_de_desplazamiento DESPLAZAMIENTO_A_DERECHA expresion_aditiva
;

expresion_aditiva: 
		expresion_multiplicativa
	| expresion_aditiva '+' expresion_multiplicativa
	| expresion_aditiva '-' expresion_multiplicativa
;

expresion_multiplicativa: 
		//expresion_de_casteo
		expresion_multiplicativa '*' expresion_de_casteo
	|	expresion_multiplicativa '/' expresion_de_casteo
	|	expresion_multiplicativa '%' expresion_de_casteo
;


///////////////


expresion_de_casteo: 
		expresion_unaria
	|	'(' TIPO_DE_DATO ')' expresion_de_casteo
;

expresion_unaria: 
		expresion_sufija
	|	INCREMENTO expresion_unaria
	|	DECREMENTO expresion_unaria
	|	operador_unario expresion_de_casteo
	| SIZEOF expresion_unaria
	| SIZEOF '(' TIPO_DE_DATO ')'
;

operador_unario:	
		'&'
	|	'*'
	|	'+'
	|	'-'
	|	'~'
	|	'!'	
;

expresion_sufija: 	
		expresion_primaria
	|	expresion_sufija '[' expresion ']'	
	|	expresion_sufija '.' IDENTIFICADOR
	| 	expresion_sufija APUNTA IDENTIFICADOR
	| 	expresion_sufija INCREMENTO
	| 	expresion_sufija DECREMENTO
;

expresion_primaria: 
		IDENTIFICADOR
	|	CONSTANTE_DECIMAL
	|	'(' expresion ')'
;

*/
/*	IDENTIFICADOR
				|	CONSTANTE_DECIMAL
				| expresion '+' expresion
   			 | expresion '-' expresion
    			| expresion '*' expresion
   			 | expresion '/' expresion
				| '(' expresion ')'*/




%%

int main (int argc, const char * argv[])
{
	#if YYDEBUG
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




