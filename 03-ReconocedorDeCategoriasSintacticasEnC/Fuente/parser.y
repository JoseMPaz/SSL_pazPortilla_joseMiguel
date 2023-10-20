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

%union
{
	char sval[200];
	int ival;
	double dval;
}

%token <sval> IDENTIFICADOR CADENA_DE_CARACTERES CONSTANTE_CARACTER CONSTANTE_DE_ENUMERACION
%token <sval> VOID CHAR SHORT INT LONG FLOAT DOUBLE SIGNED UNSIGNED
%token <dval> CONSTANTE_REAL
%token <ival> CONSTANTE_DECIMAL CONSTANTE_OCTAL CONSTANTE_HEXADECIMAL
%token OPERADOR_LOGICO_OR OPERADOR_LOGICO_AND OPERADOR_DE_IGUALDAD  OPERADOR_DE_DESIGUALDAD
%token OPERADOR_DESPLAZAMIENTO_DE_BITS_A_IZQUIERDA OPERADOR_DESPLAZAMIENTO_DE_BITS_A_DERECHA OPERADOR_DE_COMPARACION
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
%token STRUCT UNION ENUM
%token <sval> IF ELSE SWITCH
%token <sval> WHILE DO FOR
%token <sval> GOTO CONTINUE BREAK RETURN
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
%left DESPLAZAMIENTO_A_DERECHA DESPLAZAMIENTO_A_IZQUIERDA
%left '~' '!'
%left '[' ']'
//Mayor Precedencia
%nonassoc MENOR_QUE_ELSE
%nonassoc ELSE


%define parse.error verbose

%start unidad_de_traduccion

%%

unidad_de_traduccion//1 COMPLETO
	:	declaracion_externa	
	|	unidad_de_traduccion declaracion_externa
	| 	error ';' 	{ printf("%s\tLinea:%d\n", "Error Sintactico", yylineno);              	}
	;

declaracion_externa//2 COMPLETO
	:	definicion_de_funcion
	|	declaracion
	;

definicion_de_funcion//3 COMPLETO
	:	declarador sentencia_compuesta
	|	declarador lista_de_declaraciones sentencia_compuesta
	|	especificadores_de_declaracion declarador sentencia_compuesta { printf("Definicion: %-10s TipoDato: %-10s Linea: %d\n",$<sval>2, $<sval>1, yylineno); }
	|	especificadores_de_declaracion declarador lista_de_declaraciones sentencia_compuesta { printf("Definicion: %-10s TipoDato: %-10s Linea: %d\n",$<sval>2, $<sval>1, yylineno); }
	;

declaracion//4 COMPLETO
	:	especificadores_de_declaracion ';'
	|	especificadores_de_declaracion lista_de_declaradores_inicial ';' { printf("TipoDato: %-10s Linea: %d\n", $<sval>1, yylineno); }
	;
	
lista_de_declaraciones//5 COMPLETO
	:	declaracion
	|	lista_de_declaraciones declaracion
	;

especificadores_de_declaracion//6 COMPLETO
	:	especificador_de_clase_de_almacenamiento
	|	especificador_de_clase_de_almacenamiento especificadores_de_declaracion
	|	especificador_de_tipo							//{ printf("Tipo: %s\n", $<sval>1); }
	|	especificador_de_tipo especificadores_de_declaracion	
	|	calificador_de_tipo
	|	calificador_de_tipo especificadores_de_declaracion
	;

especificador_de_clase_de_almacenamiento//7 COMPLETO
	:	AUTO
	|	REGISTER
	|	STATIC
	|	EXTERN
	|	TYPEDEF	
	;
	
especificador_de_tipo//8
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
	
calificador_de_tipo//9 COMPLETO
	:	CONST
	|	VOLATILE
	;

especificador_de_struct_o_union //10 COMPLETO
	:	struct_o_union '{' lista_de_declaraciones_struct '}'	
	|	struct_o_union IDENTIFICADOR '{' lista_de_declaraciones_struct '}'	
	|	struct_o_union IDENTIFICADOR
	;
	
struct_o_union//11 COMPLETO
	:	STRUCT
	|	UNION
	;
	
lista_de_declaraciones_struct//12 COMPLETO
	: 	declaracion_struct
	|	lista_de_declaraciones_struct declaracion_struct
	;

lista_de_declaradores_inicial://13 COMPLETO
		declarador_inicial	 { printf("Declaracion: %-10s\t", $<sval>1); }
	|	lista_de_declaradores_inicial ',' declarador_inicial { printf("Declaracion: %-10s\t", $<sval>1); }
	;

declarador_inicial//14 COMPLETO
	:	declarador							
	|	declarador operador_de_asignacion inicializador	
	;

declaracion_struct//15 COMPLETO
	:	lista_de_calificadores_y_especificadores lista_de_declaradores_struct ';'
	;

lista_de_calificadores_y_especificadores //16 COMPLETO
	:	especificador_de_tipo
	|	especificador_de_tipo lista_de_calificadores_y_especificadores
	|	calificador_de_tipo
	|	calificador_de_tipo lista_de_calificadores_y_especificadores
	;

lista_de_declaradores_struct//17 COMPLETO
	:	declarador_struct
	|	lista_de_declaradores_struct ',' declarador_struct
	;
	
declarador_struct//18 COMPLETO
	:	declarador
	|	':' expresion_constante
	|	declarador ':' expresion_constante
	;

especificador_enum//19 COMPLETO
	:	ENUM '{' lista_de_enumeradores '}'
	|	ENUM IDENTIFICADOR '{' lista_de_enumeradores '}'
	|	ENUM IDENTIFICADOR
	;
	
lista_de_enumeradores//20 COMPLETO
	:	enumerador
	|	lista_de_enumeradores ',' enumerador
	;

enumerador//21 COMPLETO
	:	IDENTIFICADOR
	|	IDENTIFICADOR '=' expresion_constante
	;

declarador//22 COMPLETO
	:	declarador_directo	
	|	puntero declarador_directo
	;

declarador_directo//23 COMPLETO
	:	IDENTIFICADOR
	|	'(' declarador ')'
	|	declarador_directo '[' ']'
	|	declarador_directo '[' expresion_constante ']'
	|	declarador_directo '(' lista_de_tipos_de_parametros ')' //{ printf("Funcion: %-10s\t", $<sval>1); }
	|	declarador_directo '(' ')'
	|	declarador_directo '(' lista_de_identificadores ')'
	;

puntero//24 COMPLETO
	:	'*'
	|	'*' lista_de_calificadores_de_tipo
	|	'*' puntero
	|	'*' lista_de_calificadores_de_tipo puntero
	;

lista_de_calificadores_de_tipo//25 COMPLETO
	:	calificador_de_tipo
	|	lista_de_calificadores_de_tipo calificador_de_tipo
	;
	
lista_de_tipos_de_parametros//26 COMPLETO
	:	lista_de_parametros
	|	lista_de_parametros ',' ELIPSIS
	;

lista_de_parametros//27 COMPLETO
	:	declaracion_de_parametro 
	|	lista_de_parametros ',' declaracion_de_parametro
	;
	
declaracion_de_parametro//28 COMPLETO
	:	especificadores_de_declaracion declarador { printf("Parametro: %-10s\t TipoDato: %-10s linea: %d\n", $<sval>2, $<sval>1,yylineno); }
	|	especificadores_de_declaracion	
	|	especificadores_de_declaracion declarador_abstracto
	;
		
lista_de_identificadores//29 COMPLETO
	:	IDENTIFICADOR
	|	lista_de_identificadores ',' IDENTIFICADOR
;

inicializador//30 COMPLETO
	:	expresion_de_asignacion
	|	'{' lista_de_inicializadores '}'
	|	'{' lista_de_inicializadores ',' '}'
	;

lista_de_inicializadores//31 COMPLETO
	:	inicializador
	|	lista_de_inicializadores ',' inicializador
	;

nombre_de_tipo//32 COMPLETO
	:	lista_de_calificadores_y_especificadores
	|	lista_de_calificadores_y_especificadores declarador_abstracto
	;
	
declarador_abstracto//33 COMPLETO
	:	puntero
	|	declarador_abstracto_directo
	|	puntero declarador_abstracto_directo
	;
	
declarador_abstracto_directo//34 COMPLETO
	: '(' declarador_abstracto ')'
	|	'[' expresion_constante ']'
	|	declarador_abstracto_directo '[' expresion_constante ']'
	|	'(' lista_de_tipos_de_parametros ')'
	|	declarador_abstracto_directo '(' lista_de_tipos_de_parametros ')'
	;
	
/*Falta la regla 35 nombre_de_typedef que se utilizaria en especificador_de_tipo regla 8, hay errores si se agrega*/

sentencia//36
	:	sentencia_de_etiqueta	
	|	sentencia_de_expresion
  	|	sentencia_compuesta
  	|	sentencia_de_seleccion
  	|	sentencia_de_iteracion 
  	|	sentencia_de_salto
	;

sentencia_de_etiqueta//37 COMPLETO
	:	IDENTIFICADOR ':' sentencia
	|	CASE expresion ':' sentencia
	|	DEFAULT ':' sentencia
	;

sentencia_de_expresion//38 COMPLETO
	:	';'
	|	expresion ';'
	;

sentencia_compuesta//39 COMPLETO
	:	'{' '}'
	|	'{' lista_de_sentencias '}'
	|	'{' lista_de_declaraciones '}' 
	|	'{' lista_de_declaraciones lista_de_sentencias '}' 
	;

lista_de_sentencias//40 COMPLETO
	:	sentencia
	|	lista_de_sentencias sentencia
	;

sentencia_de_seleccion//41 COMPLETO
	:	IF '(' expresion ')' sentencia %prec MENOR_QUE_ELSE  { printf("Sentencia de seleccion: %-10s\t linea: %d\n", $<sval>1, yylineno); }
	|	IF '(' expresion ')' sentencia ELSE sentencia  { printf("Sentencia de seleccion: %s %-10s\t linea: %d\n", $<sval>1, $<sval>6, yylineno); }
	|	SWITCH '(' expresion ')' sentencia { printf("Sentencia de seleccion: %-10s\t linea: %d\n", $<sval>1, yylineno); }
	;
	
sentencia_de_iteracion//42 COMPLETO
	:	WHILE '(' expresion ')' sentencia 		{ printf("Sentencia de iteracion: %-10s\t linea: %d\n", $<sval>1, yylineno); }
	|	DO sentencia WHILE '(' expresion ')' ';' { printf("Sentencia de iteracion: %s %-10s\t linea: %d\n", $<sval>1, $<sval>3, yylineno); }
	|	FOR '(' ';' ';' ')' sentencia	{ printf("Sentencia de iteracion: %-10s\t linea: %d\n", $<sval>1, yylineno); }
	|	FOR '(' expresion ';' ';' ')' sentencia	{ printf("Sentencia de iteracion: %-10s\t linea: %d\n", $<sval>1, yylineno); }
	|	FOR '(' ';' expresion ';' ')' sentencia	{ printf("Sentencia de iteracion: %-10s\t linea: %d\n", $<sval>1, yylineno); }
	|	FOR '(' ';' ';' expresion ')' sentencia	{ printf("Sentencia de iteracion: %-10s\t linea: %d\n", $<sval>1, yylineno); }
	|	FOR '(' expresion ';' expresion ';' ')' sentencia	{ printf("Sentencia de iteracion: %-10s\t linea: %d\n", $<sval>1, yylineno); }
	|	FOR '(' expresion ';' ';' expresion ')' sentencia	{ printf("Sentencia de iteracion: %-10s\t linea: %d\n", $<sval>1, yylineno); }
	|	FOR '(' ';' expresion ';' expresion ')' sentencia	{ printf("Sentencia de iteracion: %-10s\t linea: %d\n", $<sval>1, yylineno); }
	|	FOR '(' expresion ';' expresion ';' expresion ')' sentencia	{ printf("Sentencia de iteracion: %-10s\t linea: %d\n", $<sval>1, yylineno); }
	;
	
sentencia_de_salto//43 COMPLETO
	:	GOTO IDENTIFICADOR ';'	{ printf("Sentencia de salto: %-10s\t linea: %d\n", $<sval>1, yylineno); }
	|	CONTINUE ';'	{ printf("Sentencia de salto: %-10s\t linea: %d\n", $<sval>1, yylineno); }
	|	BREAK ';'	{ printf("Sentencia de salto: %-10s\t linea: %d\n", $<sval>1, yylineno); }
	|	RETURN ';'	{ printf("Sentencia de salto: %-10s\t linea: %d\n", $<sval>1, yylineno); }
	|	RETURN expresion ';'	{ printf("Sentencia de salto: %-10s\t linea: %d\n", $<sval>1, yylineno); }
	;

expresion//44 COMPLETO
	:	expresion_de_asignacion
	|	expresion ','  expresion_de_asignacion 
	;

expresion_de_asignacion//45 COMPLETO
	:	expresion_condicional	
	|	expresion_unaria operador_de_asignacion expresion_de_asignacion
	;
	
operador_de_asignacion//46 COMPLETO
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

expresion_condicional//47 COMPLETO
	:	expresion_logica_OR
	|	expresion_logica_OR '?' expresion ':' expresion_condicional
	;

expresion_constante//48 COMPLETO
	:	expresion_condicional
	;

expresion_logica_OR//49 COMPLETO
	:	expresion_logica_AND
	|	expresion_logica_OR OPERADOR_LOGICO_OR expresion_logica_AND
	;	

expresion_logica_AND//50 COMPLETO
	:	expresion_OR_inclusiva
	|	expresion_logica_AND OPERADOR_LOGICO_AND expresion_OR_inclusiva
	;

expresion_OR_inclusiva//51 COMPLETO
	:	expresion_XOR
	|	expresion_OR_inclusiva '|' expresion_XOR
	;

expresion_XOR//52 COMPLETO
	:	expresion_AND
	|	expresion_XOR'^' expresion_AND
	;

expresion_AND//53 COMPLETO
	:	expresion_de_igualdad
	|	expresion_AND '&' expresion_de_igualdad
	;

expresion_de_igualdad//54 COMPLETO
	:	expresion_relacional
	|	expresion_de_igualdad OPERADOR_DE_IGUALDAD expresion_relacional
	|	expresion_de_igualdad OPERADOR_DE_DESIGUALDAD expresion_relacional
	;

expresion_relacional//55 COMPLETO
	:	expresion_de_desplazamiento
	|	expresion_relacional '<' expresion_de_desplazamiento
	|	expresion_relacional MENOR_O_IGUAL expresion_de_desplazamiento
	|	expresion_relacional '>' expresion_de_desplazamiento
	|	expresion_relacional MAYOR_O_IGUAL expresion_de_desplazamiento
	;

expresion_de_desplazamiento//56 COMPLETO
	:	expresion_aditiva
	|	expresion_de_desplazamiento OPERADOR_DESPLAZAMIENTO_DE_BITS_A_IZQUIERDA expresion_aditiva
	|	expresion_de_desplazamiento OPERADOR_DESPLAZAMIENTO_DE_BITS_A_DERECHA expresion_aditiva
	;

expresion_aditiva//57 COMPLETO
	:	expresion_multiplicativa
	|	expresion_aditiva '+' expresion_multiplicativa
	|	expresion_aditiva '-' expresion_multiplicativa
	;

expresion_multiplicativa//58 COMPLETO
	:	expresion_de_casteo
	|	expresion_multiplicativa '*' expresion_de_casteo
	|	expresion_multiplicativa '/' expresion_de_casteo
	|	expresion_multiplicativa '%' expresion_de_casteo
	;

expresion_de_casteo//59 COMPLETO
	:	expresion_unaria
	|	'(' nombre_de_tipo ')' expresion_de_casteo
	;
	
expresion_unaria//60 COMPLETO
	:	expresion_posfija
	|	INCREMENTO expresion_unaria
	|	DECREMENTO expresion_unaria
	|	operador_unario expresion_de_casteo
	|	SIZEOF expresion_unaria
	|	SIZEOF '(' nombre_de_tipo ')'
	;

operador_unario//61 COMPLETO
	:	'~'
	|	'!'
	|	'+'
	|	'-'
	|	'*'
	|	'&'
	;

expresion_posfija//62 COMPLETO
	:	expresion_primaria
	|	expresion_posfija '[' expresion ']'  
	|	expresion_posfija '(' ')'
	|	expresion_posfija '(' lista_de_expresiones_de_argumentos ')'
	|	expresion_posfija '.' IDENTIFICADOR
	|	expresion_posfija OPERADOR_FLECHA IDENTIFICADOR
	|	expresion_posfija INCREMENTO
	|	expresion_posfija DECREMENTO
	;
	
expresion_primaria//63 COMPLETO
	:	IDENTIFICADOR   
	|	constante	
	| 	CADENA_DE_CARACTERES
	|	'(' expresion ')'	 
	;

lista_de_expresiones_de_argumentos//64 COMPLETO
	:	expresion_de_asignacion
	|	lista_de_expresiones_de_argumentos ',' expresion_de_asignacion
	;
 
constante//65
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
