%{
#include <stdio.h>
#include <stdlib.h>
extern int yylex();
extern FILE * yyin;
extern int yyerror (char const*s);

%}

%union
{
	char * sval;
	int ival;
}

%token <sval> IDENTIFICADOR
%token <ival> CONSTANTE_DECIMAL
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
%token VOID CHAR SHORT INT LONG FLOAT DOUBLE SIGNED UNSIGNED
%token CONST VOLATILE
%token AUTO REGISTER STATIC EXTERN TYPEDEF	
%token ELIPSIS
%token STRUCT UNION ENUM
%token IF ELSE SWITCH
%token WHILE DO FOR
%token GOTO CONTINUE BREAK RETURN

//Menor Precedencia
%left ','
%right '='
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
%nonassoc THEN
%nonassoc ELSE

%define parse.error verbose

%%

unidad_de_traduccion//1 COMPLETO
	:	declaracion_externa	
	|	unidad_de_traduccion declaracion_externa
	;

declaracion_externa//2 COMPLETO
	:	definicion_de_funcion
	|	declaracion
	;

definicion_de_funcion//3 COMPLETO
	:	declarador sentencia_compuesta
	|	declarador lista_de_declaraciones sentencia_compuesta
	|	especificadores_de_declaracion declarador sentencia_compuesta
	|	especificadores_de_declaracion declarador lista_de_declaraciones sentencia_compuesta
	;

declaracion//4 COMPLETO
	:	especificadores_de_declaracion ';'
	|	especificadores_de_declaracion lista_de_declaradores_inicial ';'
	;
	
lista_de_declaraciones//5 COMPLETO
	:	declaracion
	|	lista_de_declaraciones declaracion
	;

especificadores_de_declaracion//6 COMPLETO
	:	especificador_de_clase_de_almacenamiento
	|	especificador_de_clase_de_almacenamiento especificadores_de_declaracion
	|	especificador_de_tipo
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
		declarador_inicial
	|	lista_de_declaradores_inicial ',' declarador_inicial
	;

declarador_inicial//14 COMPLETO
	:	declarador
	|	declarador '=' inicializador
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
	;

especificador_enum//19 COMPLETO
	:	ENUM '{' lista_de_enumeradores '}'
	|	ENUM IDENTIFICADOR '{' lista_de_enumeradores '}'
	|	ENUM IDENTIFICADOR
	;
	
lista_de_enumeradores//21 COMPLETO
	:	enumerador
	|	lista_de_enumeradores ',' enumerador
	;

enumerador//22 COMPLETO
	:	IDENTIFICADOR
	|	IDENTIFICADOR '=' expresion_constante
	;

declarador//23 COMPLETO
	:	declaracion_directa
	|	puntero declaracion_directa
	;

declaracion_directa//24 COMPLETO
	:	IDENTIFICADOR
	|	'(' declarador ')'
	|	declaracion_directa '[' ']'
	|	declaracion_directa '[' expresion_constante ']'
	|	declaracion_directa '(' lista_de_tipos_de_parametros ')' { printf("Funcion: %s\n", $<sval>1); }
	|	declaracion_directa '(' ')'
	|	declaracion_directa '(' lista_de_identificadores ')'
	;

puntero//25 COMPLETO
	:	'*'
	|	'*' lista_de_calificadores_de_tipo
	|	'*' puntero
	|	'*' lista_de_calificadores_de_tipo puntero
	;

lista_de_calificadores_de_tipo//26 COMPLETO
	:	calificador_de_tipo
	|	lista_de_calificadores_de_tipo calificador_de_tipo
	;
	
lista_de_tipos_de_parametros//27 COMPLETO
	:	lista_de_parametros
	|	lista_de_parametros ',' ELIPSIS
	;

lista_de_parametros//28 COMPLETO
	:	declaracion_de_parametro 
	|	lista_de_parametros ',' declaracion_de_parametro
	;
	
declaracion_de_parametro//29 COMPLETO
	:	especificadores_de_declaracion	
	|	especificadores_de_declaracion declarador { printf("Parametro: %s\n", $<sval>2); }
	|	especificadores_de_declaracion declarador_abstracto
	;
		
lista_de_identificadores//30 COMPLETO
	:	IDENTIFICADOR
	|	lista_de_identificadores ',' IDENTIFICADOR
;

inicializador//31 COMPLETO
	:	expresion_de_asignacion
	|	'{' lista_de_inicializadores '}'
	|	'{' lista_de_inicializadores ',' '}'
	;

lista_de_inicializadores//32 COMPLETO
	:	inicializador
	|	lista_de_inicializadores ',' inicializador
	;

nombre_de_tipo //33
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
	
sentencia//38
	:	sentencia_de_etiqueta	
	|	sentencia_de_expresion
  	|	sentencia_compuesta
  	|	sentencia_de_seleccion
  	|	sentencia_de_iteracion
  	|	sentencia_de_salto
	;

sentencia_de_etiqueta//39 COMPLETO
	:	IDENTIFICADOR ':' sentencia
	|	CASE expresion ':' sentencia
	|	DEFAULT ':' sentencia
	;

sentencia_de_expresion//40 COMPLETO
	:	';'
	|	expresion ';'
	;

sentencia_compuesta//41 COMPLETO
	:	'{' '}'
	|	'{' lista_de_sentencias '}'
	|	'{' lista_de_declaraciones '}' 
	|	'{' lista_de_declaraciones lista_de_sentencias '}' 
	;

lista_de_sentencias//42 COMPLETO
	:	sentencia
	|	lista_de_sentencias sentencia
	;

sentencia_de_seleccion//43 COMPLETO
	:	IF '(' expresion ')' sentencia %prec THEN
		IF '(' expresion ')' sentencia ELSE sentencia
	|	SWITCH '(' expresion ')' sentencia
	;
	
sentencia_de_iteracion//44 COMPLETO
	:	WHILE '(' expresion ')' sentencia 
	|	DO sentencia WHILE '(' expresion ')' ';'
	|	FOR '(' ';' ';' ')' sentencia
	|	FOR '(' expresion ';' ';' ')' sentencia
	|	FOR '(' ';' expresion ';' ')' sentencia
	|	FOR '(' ';' ';' expresion ')' sentencia
	|	FOR '(' expresion ';' expresion ';' ')' sentencia
	|	FOR '(' expresion ';' ';' expresion ')' sentencia
	|	FOR '(' ';' expresion ';' expresion ')' sentencia
	|	FOR '(' expresion ';' expresion ';' expresion ')' sentencia
	;
	
sentencia_de_salto//45 COMPLETO
	:	GOTO IDENTIFICADOR ';'
	|	CONTINUE ';'
	|	BREAK ';'
	|	RETURN ';'
	|	RETURN expresion ';'
	;

expresion//46 COMPLETO
	:	expresion_de_asignacion
	|	expresion ','  expresion_de_asignacion 
	;

expresion_de_asignacion//47 COMPLETO
	:	expresion_condicional	
	|	expresion_unaria '=' expresion_de_asignacion
	;
	
expresion_condicional//48 COMPLETO
	:	expresion_logica_OR
	|	expresion_logica_OR '?' expresion ':' expresion_condicional
	;

expresion_constante//49 COMPLETO
	:	expresion_condicional
	;

expresion_logica_OR//50 COMPLETO
	:	expresion_logica_AND
	|	expresion_logica_OR OPERADOR_LOGICO_OR expresion_logica_AND
	;	

expresion_logica_AND//51 COMPLETO
	:	expresion_OR_inclusiva
	|	expresion_logica_AND OPERADOR_LOGICO_AND expresion_OR_inclusiva
	;

expresion_OR_inclusiva//52 COMPLETO
	:	expresion_OR_exclusiva
	|	expresion_OR_inclusiva '|' expresion_OR_exclusiva
	;

expresion_OR_exclusiva//53 COMPLETO
	:	expresion_AND
	|	expresion_OR_exclusiva '^' expresion_AND
	;

expresion_AND//54 COMPLETO
	:	expresion_de_igualdad
	|	expresion_AND '&' expresion_de_igualdad
	;

expresion_de_igualdad//55 COMPLETO
	:	expresion_relacional
	|	expresion_de_igualdad OPERADOR_DE_IGUALDAD expresion_relacional
	|	expresion_de_igualdad OPERADOR_DE_DESIGUALDAD expresion_relacional
	;

expresion_relacional//56 COMPLETO
	:	expresion_de_desplazamiento
	|	expresion_relacional '<' expresion_de_desplazamiento
	|	expresion_relacional MENOR_O_IGUAL expresion_de_desplazamiento
	|	expresion_relacional '>' expresion_de_desplazamiento
	|	expresion_relacional MAYOR_O_IGUAL expresion_de_desplazamiento
	;

expresion_de_desplazamiento://57 COMPLETO
		expresion_aditiva
	|	expresion_de_desplazamiento OPERADOR_DESPLAZAMIENTO_DE_BITS_A_IZQUIERDA expresion_aditiva
	|	expresion_de_desplazamiento OPERADOR_DESPLAZAMIENTO_DE_BITS_A_DERECHA expresion_aditiva
	;

expresion_aditiva//58 COMPLETO
	:	expresion_multiplicativa
	|	expresion_aditiva '+' expresion_multiplicativa
	|	expresion_aditiva '-' expresion_multiplicativa
	;

expresion_multiplicativa//59 COMPLETO
	:	expresion_de_casteo
	|	expresion_multiplicativa '*' expresion_de_casteo
	|	expresion_multiplicativa '/' expresion_de_casteo
	|	expresion_multiplicativa '%' expresion_de_casteo
	;

expresion_de_casteo//60 COMPLETO
	:	expresion_unaria
	|	'(' nombre_de_tipo ')' expresion_de_casteo
	;
	
expresion_unaria//61 COMPLETO
	:	expresion_posfija
	|	INCREMENTO expresion_unaria
	|	DECREMENTO expresion_unaria
	|	operador_unario expresion_de_casteo
	|	SIZEOF expresion_unaria
	|	SIZEOF '(' nombre_de_tipo ')'
	;

operador_unario//62 COMPLETO
	:	'~'
	|	'!'
	|	'+'
	|	'-'
	|	'*'
	|	'&'
	;

expresion_posfija//63 COMPLETO
	:	expresion_primaria
	|	expresion_posfija '[' expresion ']'  
	|	expresion_posfija '(' ')'
	|	expresion_posfija '(' lista_de_expresiones_de_argumentos ')'
	|	expresion_posfija '.' IDENTIFICADOR
	|	expresion_posfija OPERADOR_FLECHA IDENTIFICADOR
	|	expresion_posfija INCREMENTO
	|	expresion_posfija DECREMENTO
	;
	
expresion_primaria//64
	:	IDENTIFICADOR   
	|	constante	
	|	'(' expresion ')'	 
	;

lista_de_expresiones_de_argumentos//65 COMPLETO
	:	expresion_de_asignacion
	|	lista_de_expresiones_de_argumentos ',' expresion_de_asignacion
	;
 
constante//66
	:	CONSTANTE_DECIMAL
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
  return 0;
}
