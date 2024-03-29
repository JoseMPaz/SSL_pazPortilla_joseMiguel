%{
#include <stdio.h>
#include <stdlib.h>
#include "misFunciones.h"
extern int yylex();
extern FILE * yyin;
extern int yyerror (char const*s);
extern int yylineno;
extern nodo_cadena_entero_t * no_reconocidas;

#define ETIQUETA_PALABRAS_O_CARACTERES_NO_RECONOCIDOS "Palabra o caracter no reconocido: "
#define ETIQUETA_NUMERO_DE_LINEA "Numero de linea: "
#define CABECERA_PALABRAS_O_CARACTERES_NO_RECONOCIDOS "ERRORES LEXICOS"
%}

//Se comento alguna variante del error-verbose para que no haya conflicto con las diferentes versiones de bison
%define parse.error verbose

// %define parse.error verbose // Para versiones de bison mayores a 3.0

%union
{
	struct yylval_struct{
		char id[200];
		char sval[200];
		char sval2[200];
		int ival;
		int linea_inicial;
		double dval;
	}s;
}

%token <s> IDENTIFICADOR CADENA_DE_CARACTERES CONSTANTE_CARACTER CONSTANTE_DE_ENUMERACION
%token <s> VOID CHAR SHORT INT LONG FLOAT DOUBLE SIGNED UNSIGNED
%token <s> CONSTANTE_REAL
%token <s> CONSTANTE_DECIMAL CONSTANTE_OCTAL CONSTANTE_HEXADECIMAL
%token OPERADOR_LOGICO_OR OPERADOR_LOGICO_AND OPERADOR_DE_IGUALDAD  OPERADOR_DE_DESIGUALDAD
%token OPERADOR_DESPLAZAMIENTO_DE_BITS_A_IZQUIERDA OPERADOR_DESPLAZAMIENTO_DE_BITS_A_DERECHA
%token MENOR_O_IGUAL
%token MAYOR_O_IGUAL
%token INCREMENTO
%token DECREMENTO
%token SIZEOF
%token OPERADOR_FLECHA
%token CASE
%token DEFAULT
%token CONST VOLATILE
%token AUTO REGISTER STATIC EXTERN TYPEDEF	
%token ELIPSIS
%token <s> STRUCT UNION ENUM
%token <s> IF ELSE SWITCH
%token <s> WHILE DO FOR
%token <s> GOTO CONTINUE BREAK RETURN
%token OPERADOR_ASIGNACION_MULTIPLICACION OPERADOR_ASIGNACION_DIVISION OPERADOR_ASIGNACION_RESTO
%token OPERADOR_ASIGNACION_SUMA OPERADOR_ASIGNACION_RESTA
%token OPERADOR_ASIGNACION_DESPLAZAMIENTO_DE_BITS_A_IZQUIERDA OPERADOR_ASIGNACION_DESPLAZAMIENTO_DE_BITS_A_DERECHA
%token OPERADOR_ASIGNACION_AND_BIT_A_BIT OPERADOR_ASIGNACION_XOR_BIT_A_BIT OPERADOR_ASIGNACION_OR_BIT_A_BIT

//Menor Precedencia
%left ','
%right '=' OPERADOR_ASIGNACION_SUMA OPERADOR_ASIGNACION_RESTA
%right '?' ':'
%left OPERADOR_LOGICO_OR
%left OPERADOR_LOGICO_AND
%left '|' '&'  '^'
%left OPERADOR_DE_IGUALDAD OPERADOR_DE_DESIGUALDAD
%left '<' '>'
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'
%left OPERADOR_ASIGNACION_DESPLAZAMIENTO_DE_BITS_A_DERECHA OPERADOR_ASIGNACION_DESPLAZAMIENTO_DE_BITS_A_IZQUIERDA
%left '~' '!'
%left '[' ']'
//Mayor Precedencia
%nonassoc MENOR_QUE_ELSE
%nonassoc ELSE

//Se comento alguna variante del error-verbose para que no haya conflicto con las diferentes versiones de bison

//%define parse.error verbose // Para versiones de bison mayores a 3.0

%start unidad_de_traduccion

%%

unidad_de_traduccion
	:	declaracion_externa	
	|	unidad_de_traduccion declaracion_externa
	| 	error ';' 	{ printf("Error Sintactico\t Linea: %d\n", yylineno); }
	;

declaracion_externa
	:	definicion_de_funcion
	|	declaracion
	;

definicion_de_funcion
	:	declarador sentencia_compuesta
	|	declarador lista_de_declaraciones sentencia_compuesta
	|	especificadores_de_declaracion declarador sentencia_compuesta 
	|	especificadores_de_declaracion declarador lista_de_declaraciones sentencia_compuesta
	;

declaracion
	:	especificadores_de_declaracion ';'
	|	especificadores_de_declaracion lista_de_declaradores_inicial ';' { printf("Variable declarada: %-10s Tipo de Dato: %s %-10s Linea: %d\n", $<s>2.id, $<s>1.sval2, $<s>1.sval, yylineno); }
	;
	
lista_de_declaraciones
	:	declaracion
	|	lista_de_declaraciones declaracion
	;

especificadores_de_declaracion
	:	especificador_de_clase_de_almacenamiento	
	|	especificador_de_clase_de_almacenamiento especificadores_de_declaracion	
	|	especificador_de_tipo									
	|	especificador_de_tipo especificadores_de_declaracion	//{ printf("ModificadorTipoVariable: %-10s Tipo: %-10s\n", $<s>1.sval, $<s>2.sval); }
	|	calificador_de_tipo
	|	calificador_de_tipo especificadores_de_declaracion
	;

especificador_de_clase_de_almacenamiento
	:	AUTO
	|	REGISTER
	|	STATIC
	|	EXTERN
	|	TYPEDEF	
	;
	
especificador_de_tipo
	:	VOID
	|	CHAR
	|	SHORT
	|	INT
	|	LONG
	|	FLOAT
	|	DOUBLE
	|	SIGNED
	|	UNSIGNED
	|	especificador_de_struct_o_union
	|	especificador_enum
	;
	
calificador_de_tipo
	:	CONST
	|	VOLATILE
	;

especificador_de_struct_o_union 
	:	struct_o_union '{' lista_de_declaraciones_struct '}'
	|	struct_o_union IDENTIFICADOR '{' lista_de_declaraciones_struct '}'	{ printf("Estructura declarada: %-10s Tipo de Dato: %-10s Lineas: %d - %d\n", $<s>2.id, $<s>1.sval, $<s>1.linea_inicial, yylineno); }
	|	struct_o_union IDENTIFICADOR	{ printf("Estructura declarada: %-10s Tipo de Dato: %-10s Linea: %d\n", $<s>2.id, $<s>1.sval, yylineno); }
	;

struct_o_union
	:	STRUCT 
	|	UNION 
	;
	
lista_de_declaraciones_struct
	: 	declaracion_struct
	|	lista_de_declaraciones_struct declaracion_struct
	;

lista_de_declaradores_inicial:
		declarador_inicial	 //{ printf("Declaracion: %-10s %d\n", $<sval>1, yylineno); }
	|	lista_de_declaradores_inicial ',' declarador_inicial //{ printf("Declaracion2: %-10s %d\n", $<sval>1, yylineno); }
	;

declarador_inicial
	:	declarador							
	|	declarador operador_de_asignacion inicializador	
	;

declaracion_struct
	:	lista_de_calificadores_y_especificadores lista_de_declaradores_struct ';' { printf("Variable declarada: %-10s Tipo de Dato: %s %-10s Linea: %d\n", $<s>2.id, $<s>1.sval2, $<s>1.sval, yylineno); }
	;

lista_de_calificadores_y_especificadores
	:	especificador_de_tipo
	|	especificador_de_tipo lista_de_calificadores_y_especificadores
	|	calificador_de_tipo
	|	calificador_de_tipo lista_de_calificadores_y_especificadores
	;

lista_de_declaradores_struct
	:	declarador_struct
	|	lista_de_declaradores_struct ',' declarador_struct
	;
	
declarador_struct
	:	declarador
	|	':' expresion_constante
	|	declarador ':' expresion_constante
	;

especificador_enum
	:	ENUM '{' lista_de_enumeradores '}'
	|	ENUM IDENTIFICADOR '{' lista_de_enumeradores '}'
	|	ENUM IDENTIFICADOR
	;
	
lista_de_enumeradores
	:	enumerador
	|	lista_de_enumeradores ',' enumerador
	;

enumerador
	:	IDENTIFICADOR
	|	IDENTIFICADOR '=' expresion_constante
	;

declarador
	:	declarador_directo	
	|	puntero declarador_directo
	;

declarador_directo
	:	IDENTIFICADOR
	|	'(' declarador ')'
	|	declarador_directo '[' ']'
	|	declarador_directo '[' expresion_constante ']'
	|	declarador_directo '(' lista_de_tipos_de_parametros ')' 	{ printf("Funcion: %-10s \tTipo: %-10s\tLinea: %d\n", $<s>1.id, $<s>1.sval, yylineno); }
	|	declarador_directo '(' ')'									{ printf("Funcion: %-10s \tTipo: %-10s\tLinea: %d\n", $<s>1.id, $<s>1.sval, yylineno); }
	|	declarador_directo '(' lista_de_identificadores ')'
	;

puntero
	:	'*'
	|	'*' lista_de_calificadores_de_tipo
	|	'*' puntero
	|	'*' lista_de_calificadores_de_tipo puntero
	;

lista_de_calificadores_de_tipo
	:	calificador_de_tipo
	|	lista_de_calificadores_de_tipo calificador_de_tipo
	;
	
lista_de_tipos_de_parametros
	:	lista_de_parametros
	|	lista_de_parametros ',' ELIPSIS
	;

lista_de_parametros
	:	declaracion_de_parametro 
	|	lista_de_parametros ',' declaracion_de_parametro
	;
	
declaracion_de_parametro
	:	especificadores_de_declaracion declarador { printf("Parametro: %-10s Tipo de dato: %-10s Linea: %d\n", $<s>2.id, $<s>1.sval, yylineno); }
	|	especificadores_de_declaracion			  { printf("Parametro: -%-10s\t TipoDato: %-10s Linea: %d\n", "", $<s>1.sval, yylineno); }	
	|	especificadores_de_declaracion declarador_abstracto
	;
		
lista_de_identificadores
	:	IDENTIFICADOR
	|	lista_de_identificadores ',' IDENTIFICADOR
;

inicializador
	:	expresion_de_asignacion
	|	'{' lista_de_inicializadores '}'
	|	'{' lista_de_inicializadores ',' '}'
	;

lista_de_inicializadores
	:	inicializador
	|	lista_de_inicializadores ',' inicializador
	;

nombre_de_tipo
	:	lista_de_calificadores_y_especificadores
	|	lista_de_calificadores_y_especificadores declarador_abstracto
	;
	
declarador_abstracto
	:	puntero
	|	declarador_abstracto_directo
	|	puntero declarador_abstracto_directo
	;
	
declarador_abstracto_directo
	: '(' declarador_abstracto ')'
	|	'[' expresion_constante ']'
	|	declarador_abstracto_directo '[' expresion_constante ']'
	|	'(' lista_de_tipos_de_parametros ')'
	|	declarador_abstracto_directo '(' lista_de_tipos_de_parametros ')'
	;
	
sentencia
	:	sentencia_de_etiqueta	
	|	sentencia_de_expresion
  	|	sentencia_compuesta
  	|	sentencia_de_seleccion
  	|	sentencia_de_iteracion 
  	|	sentencia_de_salto
	;

sentencia_de_etiqueta
	:	IDENTIFICADOR ':' sentencia		{ printf("Sentencia de etiqueta en linea: %d\n", yylineno); }
	|	CASE expresion ':' sentencia	{ printf("Sentencia de etiqueta CASE en lineas: %d - %d\n", $<s>1.linea_inicial, yylineno); }
	|	DEFAULT ':' sentencia			{ printf("Sentencia de etiqueta DEFAULT en lineas: %d - %d\n", $<s>1.linea_inicial, yylineno); }
	;

sentencia_de_expresion
	:	';'
	|	expresion ';'
	;

sentencia_compuesta
	:	'{' '}'
	|	'{' lista_de_sentencias '}'
	|	'{' lista_de_declaraciones '}' 
	|	'{' lista_de_declaraciones lista_de_sentencias '}' 
	;

lista_de_sentencias
	:	sentencia
	|	lista_de_sentencias sentencia
	;

sentencia_de_seleccion
	:	IF '(' expresion ')' sentencia %prec MENOR_QUE_ELSE  	{ printf("Sentencia de seleccion IF en lineas: %d - %d\n", $<s>1.linea_inicial, yylineno); }
	|	IF '(' expresion ')' sentencia ELSE sentencia  			{ printf("Sentencia de seleccion IF ELSE en lineas: %d - %d\n", $<s>1.linea_inicial, yylineno); }
	|	SWITCH '(' expresion ')' sentencia 						{ printf("Sentencia de seleccion SWITCH en lineas: %d - %d\n", $<s>1.linea_inicial, yylineno); }
	;
	
sentencia_de_iteracion
	:	WHILE '(' expresion ')' sentencia 					{ printf("Sentencia de iteracion WHILE en lineas: %d - %d\n", $<s>1.linea_inicial, yylineno); }
	|	DO sentencia WHILE '(' expresion ')' ';' 			{ printf("Sentencia de iteracion DO WHILE en lineas: %d - %d\n", $<s>1.linea_inicial, yylineno); }
	|	FOR '(' expresion_opcional ';' expresion_opcional ';' expresion_opcional ')' sentencia	{ printf("Sentencia de iteracion FOR en lineas: %d - %d\n", $<s>1.linea_inicial, yylineno); }
	;

expresion_opcional
	:	expresion
	|
;
	
sentencia_de_salto
	:	GOTO IDENTIFICADOR ';'	{ printf("Sentencia de salto GOTO en linea: %d\n", yylineno); }
	|	CONTINUE ';'			{ printf("Sentencia de salto CONTINUE en linea: %d\n", yylineno); }
	|	BREAK ';'				{ printf("Sentencia de salto BREAK en linea: %d\n", yylineno); }
	|	RETURN ';'				{ printf("Sentencia de salto RETURN en linea: %d\n", $<s>1.linea_inicial); }
	|	RETURN expresion ';'	{ printf("Sentencia de salto RETURN en linea: %d\n", yylineno); }
	;

expresion
	:	expresion_de_asignacion
	|	expresion ','  expresion_de_asignacion 
	;

expresion_de_asignacion
	:	expresion_condicional	
	|	expresion_unaria operador_de_asignacion expresion_de_asignacion
	;
	
operador_de_asignacion
	:	'='
	|	OPERADOR_ASIGNACION_MULTIPLICACION
	|	OPERADOR_ASIGNACION_DIVISION
	|	OPERADOR_ASIGNACION_RESTO
	|	OPERADOR_ASIGNACION_SUMA
	|	OPERADOR_ASIGNACION_RESTA
	|	OPERADOR_ASIGNACION_DESPLAZAMIENTO_DE_BITS_A_IZQUIERDA
	|	OPERADOR_ASIGNACION_DESPLAZAMIENTO_DE_BITS_A_DERECHA
	|	OPERADOR_ASIGNACION_AND_BIT_A_BIT
	|	OPERADOR_ASIGNACION_XOR_BIT_A_BIT
	|	OPERADOR_ASIGNACION_OR_BIT_A_BIT
	;

expresion_condicional
	:	expresion_logica_OR
	|	expresion_logica_OR '?' expresion ':' expresion_condicional
	;

expresion_constante
	:	expresion_condicional
	;

expresion_logica_OR
	:	expresion_logica_AND
	|	expresion_logica_OR OPERADOR_LOGICO_OR expresion_logica_AND
	;	

expresion_logica_AND
	:	expresion_OR_inclusiva
	|	expresion_logica_AND OPERADOR_LOGICO_AND expresion_OR_inclusiva
	;

expresion_OR_inclusiva
	:	expresion_XOR
	|	expresion_OR_inclusiva '|' expresion_XOR
	;

expresion_XOR
	:	expresion_AND
	|	expresion_XOR'^' expresion_AND
	;

expresion_AND
	:	expresion_de_igualdad
	|	expresion_AND '&' expresion_de_igualdad
	;

expresion_de_igualdad
	:	expresion_relacional
	|	expresion_de_igualdad OPERADOR_DE_IGUALDAD expresion_relacional
	|	expresion_de_igualdad OPERADOR_DE_DESIGUALDAD expresion_relacional
	;

expresion_relacional
	:	expresion_de_desplazamiento
	|	expresion_relacional '<' expresion_de_desplazamiento
	|	expresion_relacional MENOR_O_IGUAL expresion_de_desplazamiento
	|	expresion_relacional '>' expresion_de_desplazamiento
	|	expresion_relacional MAYOR_O_IGUAL expresion_de_desplazamiento
	;

expresion_de_desplazamiento
	:	expresion_aditiva
	|	expresion_de_desplazamiento OPERADOR_DESPLAZAMIENTO_DE_BITS_A_IZQUIERDA expresion_aditiva
	|	expresion_de_desplazamiento OPERADOR_DESPLAZAMIENTO_DE_BITS_A_DERECHA expresion_aditiva
	;

expresion_aditiva
	:	expresion_multiplicativa
	|	expresion_aditiva '+' expresion_multiplicativa
	|	expresion_aditiva '-' expresion_multiplicativa
	;

expresion_multiplicativa
	:	expresion_de_casteo
	|	expresion_multiplicativa '*' expresion_de_casteo
	|	expresion_multiplicativa '/' expresion_de_casteo
	|	expresion_multiplicativa '%' expresion_de_casteo
	;

expresion_de_casteo
	:	expresion_unaria
	|	'(' nombre_de_tipo ')' expresion_de_casteo
	;
	
expresion_unaria
	:	expresion_posfija
	|	INCREMENTO expresion_unaria
	|	DECREMENTO expresion_unaria
	|	operador_unario expresion_de_casteo
	|	SIZEOF expresion_unaria
	|	SIZEOF '(' nombre_de_tipo ')'
	;

operador_unario
	:	'~'
	|	'!'
	|	'+'
	|	'-'
	|	'*'
	|	'&'
	;

expresion_posfija
	:	expresion_primaria
	|	expresion_posfija '[' expresion ']'  
	|	expresion_posfija '(' ')'
	|	expresion_posfija '(' lista_de_expresiones_de_argumentos ')'
	|	expresion_posfija '.' IDENTIFICADOR
	|	expresion_posfija OPERADOR_FLECHA IDENTIFICADOR
	|	expresion_posfija INCREMENTO
	|	expresion_posfija DECREMENTO
	;
	
expresion_primaria
	:	IDENTIFICADOR   
	|	constante	
	| 	CADENA_DE_CARACTERES
	|	'(' expresion ')'	 
	;

lista_de_expresiones_de_argumentos
	:	expresion_de_asignacion
	|	lista_de_expresiones_de_argumentos ',' expresion_de_asignacion
	;
 
constante
	:	constante_entera
	|	CONSTANTE_CARACTER
	|	CONSTANTE_REAL
	;
	
constante_entera
	:	CONSTANTE_DECIMAL
	|	CONSTANTE_OCTAL
	|	CONSTANTE_HEXADECIMAL
	|	CONSTANTE_DE_ENUMERACION
	;

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
  
  /*Imprime y luego elimina la lista de las palabras reservadas*/
	imprimir_cadena_entero(no_reconocidas, ETIQUETA_PALABRAS_O_CARACTERES_NO_RECONOCIDOS, 
									ETIQUETA_NUMERO_DE_LINEA,CABECERA_PALABRAS_O_CARACTERES_NO_RECONOCIDOS);
	eliminar_lista_cadena_entero(no_reconocidas);
	fclose (yyin);
	return 0;
}
