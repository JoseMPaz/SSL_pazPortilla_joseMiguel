%{
#include <stdio.h>
#include <stdlib.h>
#include "errores.h"
#include "variables.h"
#include "funciones.h"
#include "identificador.h"
#include "operaciones.h"

extern int yylex();
extern FILE * yyin;
extern void yyerror(const char *s);
extern int yylineno;
extern nodo_error_t * errores_lexicos;
nodo_error_t * errores_sintacticos = NULL;
extern error_t error;

#define ETIQUETA_PALABRAS_O_CARACTERES_NO_RECONOCIDOS "Palabra o caracter no reconocido: "
#define ETIQUETA_NUMERO_DE_LINEA "Numero de linea: "
#define CABECERA_PALABRAS_O_CARACTERES_NO_RECONOCIDOS "ERRORES LEXICOS"
#define ETIQUETA_SENTENCIAS_NO_RECONOCIDAS "Sentencia no reconocida "
#define CABECERA_SENTENCIAS_NO_RECONOCIDAS "ERRORES SINTACTICOS"

nodo_parametro_t * parametros_declaracion = NULL, * parametros_definicion = NULL, * parametros = NULL, * argumentos = NULL;
parametro_t parametro, argumento;
nodo_identificador_t * identificadores = NULL, * identificador_temporal = NULL;
int nroParametro = 0;
char identificador[200];
char tipo_dato[200];
variable_t variable;
nodo_variable_t * variables = NULL;
bool_t es_funcion = FALSE, identificador_repetido = FALSE, hubo_error_con_argumentos = FALSE, tiene_un_tipo = FALSE;
char ambito[200], nombre_llamada_funcion[200], tipo_dato_argumento[200];
char un_tipo_dato[200], otro_tipo_dato[200], un_identificador[200], otro_identificador[200];
nodo_funcion_t * funciones = NULL;
funcion_t funcion;
operacion_t elem1, elem2;

%}

//Mostrar descripcion detallada de error sintactico
//%error-verbose //En Windows
/* %define parse.error verbose //En Linux  */

%union
{
	struct yylval_struct{
		char sval[200];
		int nro_linea_inicio;
		int tipo;
		double dval;
	}s;
}

%token <s> IDENTIFICADOR CADENA_DE_CARACTERES CONSTANTE_DE_ENUMERACION
%token <s> VOID CHAR SHORT INT LONG FLOAT DOUBLE SIGNED UNSIGNED
%token <s> CONSTANTE_DECIMAL CONSTANTE_OCTAL CONSTANTE_HEXADECIMAL CONSTANTE_REAL CONSTANTE_CARACTER
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

%start unidad_de_traduccion

%%

unidad_de_traduccion
	:	declaracion_externa	
	|	unidad_de_traduccion declaracion_externa
	| 	error ';' 	
	{
		error.nro_linea = yylineno;
		agregar_error_al_final_con_repeticion (&errores_sintacticos, error);
	}
	;

declaracion_externa
	:	definicion_de_funcion 
	|	declaracion	
	;

definicion_de_funcion
	:	declarador sentencia_compuesta 
	|	declarador lista_de_declaraciones sentencia_compuesta 
	|	especificadores_de_declaracion declarador sentencia_compuesta 
	{
		strcpy (funcion.tipo_dato_devuelto, $<s>1.sval);
		strcpy (funcion.nombre_funcion, $<s>2.sval);
		funcion.parametros = parametros;
		funcion.esta_definida = 1;
		agregar_funcion_al_final (&funciones, funcion);
		parametros = NULL;
		es_funcion = FALSE;
	}
	|	especificadores_de_declaracion declarador lista_de_declaraciones sentencia_compuesta  
	;

declaracion
	:	especificadores_de_declaracion ';'										 
	|	especificadores_de_declaracion lista_de_declaradores_inicial ';' 
	{
		nodo_identificador_t * temporal;
		
		if (cantidad_de_identificadores (identificadores) == 1)//Declaracion de variable simple o funcion
		{
			if (es_funcion == TRUE && !strcmp (ambito,identificadores->info))//Declaracion de funcion
			{
				if (identificador_repetido == TRUE)
					identificador_repetido = FALSE;
				else
				{
					strcpy (funcion.tipo_dato_devuelto, $<s>1.sval);
					strcpy (funcion.nombre_funcion, identificadores->info);
					funcion.parametros = parametros;
					funcion.esta_definida = 0;
					agregar_funcion_al_final (&funciones, funcion);
					parametros = NULL;
					es_funcion = FALSE;
				}
			}
			else//Declaracion simple de variable
			{
				strcpy (variable.nombre_variable, identificadores->info);
				strcpy (variable.tipo_dato, $<s>1.sval);
				strcpy (variable.ambito, ambito);
				variable.valor = $<s>1.dval;
				agregar_variable_al_final (&variables, variable);
			}
			eliminar_identificadores (identificadores);
			identificadores = NULL;
		}
		else//Declaracion multiple de variables
		{
			if (rutina_semantica_validacion_de_repeticion_declaracion_multiple (identificadores) == 0)
			{
				for (temporal = identificadores; temporal != NULL; temporal = temporal->sig)
				{
					strcpy (variable.nombre_variable, temporal->info);
					strcpy (variable.tipo_dato, $<s>1.sval);
					strcpy (variable.ambito, ambito);//En principio puede ser una variable global
					variable.valor = $<s>1.dval;
					agregar_variable_al_final (&variables, variable);
				}		
				eliminar_identificadores (identificadores);
				identificadores = NULL;
			}
			else
			{
				eliminar_identificadores (identificadores);
				identificadores = NULL;
			}
		}
	}
	| 	especificadores_de_declaracion error ';' 	
	{
		yyerrok;
		error.nro_linea = yylineno;
		agregar_error_al_final_con_repeticion (&errores_sintacticos, error);
	}
	;
	
lista_de_declaraciones
	:	declaracion
	|	lista_de_declaraciones declaracion
	/* |	lista_de_declaraciones error ';' { yyerrok; printf("Error Sintactico en la declaracion2\t Linea: %d\n", yylineno); } */
	;

especificadores_de_declaracion
	:	especificador_de_clase_de_almacenamiento	
	|	especificador_de_clase_de_almacenamiento especificadores_de_declaracion	
	|	especificador_de_tipo								
	|	especificador_de_tipo especificadores_de_declaracion	
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
	|	struct_o_union IDENTIFICADOR '{' lista_de_declaraciones_struct '}'	
	|	struct_o_union IDENTIFICADOR	
	;

struct_o_union
	:	STRUCT 
	|	UNION 
	;
	
lista_de_declaraciones_struct
	: 	declaracion_struct
	|	lista_de_declaraciones_struct declaracion_struct
	;

lista_de_declaradores_inicial
	:	declarador_inicial	 
	|	lista_de_declaradores_inicial ',' declarador_inicial 
	;

declarador_inicial
	:	declarador										 
	{
		if (rutina_semantica_validacion_de_repeticion_declaracion ($<s>1.sval, variables, funciones) == 0)
			agregar_identificador_al_final (&identificadores, $<s>1.sval);
		else
			identificador_repetido = TRUE;
		
			
	}//Para declaracion de funcion o variable sin asignacion
	|	declarador operador_de_asignacion inicializador	  
	{
		if (rutina_semantica_validacion_de_repeticion_declaracion ($<s>1.sval, variables, funciones) == 0)
			agregar_identificador_al_final (&identificadores, $<s>1.sval);
		else
			identificador_repetido = TRUE;
	}	//Para declaracion de variable con asignacion
	|	declarador error ';' 	
	{
		error.nro_linea = yylineno;
		agregar_error_al_final_con_repeticion (&errores_sintacticos, error);
	}
	|	declarador operador_de_asignacion error ';' 	
	{
		error.nro_linea = yylineno;
		agregar_error_al_final_con_repeticion (&errores_sintacticos, error);
	}
	;

declaracion_struct
	:	lista_de_calificadores_y_especificadores lista_de_declaradores_struct ';' 
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
	|	declarador_directo '(' lista_de_tipos_de_parametros ')' 	
	{
		es_funcion = TRUE;
		strcpy (ambito, $<s>1.sval);
	}
	|	declarador_directo '(' ')'											
	{ 
		strcpy(parametro.nombre_parametro, "-"); 
		strcpy(parametro.tipo_dato, "void");
		agregar_parametro_al_final (&parametros, parametro);
		strcpy (ambito, $<s>1.sval);
		es_funcion = TRUE;
	}
	|	declarador_directo '(' lista_de_identificadores ')' 
	| 	declarador_directo '(' error ')'	
	{
		error.nro_linea = yylineno;
		agregar_error_al_final_con_repeticion (&errores_sintacticos, error);
	}
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
	:	especificadores_de_declaracion declarador	
	{
	 	strcpy(parametro.nombre_parametro, $<s>2.sval); 
		strcpy(parametro.tipo_dato, $<s>1.sval);
		agregar_parametro_al_final (&parametros, parametro);

	}//Sirve para declaracion o definicion de funciones*/
	|	especificadores_de_declaracion				
	{	
		strcpy(parametro.nombre_parametro, "-"); 
		strcpy(parametro.tipo_dato, $<s>1.sval); 
		agregar_parametro_al_final (&parametros, parametro);
	}//Sirve para definicion y declaracion de funciones con argumento void o solo tipo de datos sin parametro
	|	especificadores_de_declaracion declarador_abstracto	
	| 	especificadores_de_declaracion error ';' 	
	{
		error.nro_linea = yylineno;
		agregar_error_al_final_con_repeticion (&errores_sintacticos, error);
	}
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
	:	'(' declarador_abstracto ')'
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
	:	IDENTIFICADOR ':' sentencia		
	|	CASE expresion ':' sentencia	
	|	DEFAULT ':' sentencia			
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
	| 	'{' error '}' 	
	{
		error.nro_linea = yylineno;
		agregar_error_al_final_con_repeticion (&errores_sintacticos, error);
	}
	| 	'{' error ';' lista_de_declaraciones lista_de_sentencias '}' 	{ printf("Error Sintactico en sentencia compuesta\t Linea: %d\n", yylineno); }
	| 	'{' lista_de_declaraciones error ';' lista_de_sentencias '}' 	{ printf("Error Sintactico en sentencia compuesta\t Linea: %d\n", yylineno); }
	;

lista_de_sentencias
	:	sentencia
	|	lista_de_sentencias sentencia
	;

sentencia_de_seleccion
	:	IF '(' expresion ')' sentencia %prec MENOR_QUE_ELSE  	
	|	IF '(' expresion ')' sentencia ELSE sentencia  			
	|	SWITCH '(' expresion ')' sentencia 			
	| 	IF '(' error ')' 	
	{
		error.nro_linea = yylineno;
		agregar_error_al_final_con_repeticion (&errores_sintacticos, error);	
	}		
	| 	SWITCH '(' error ')' 	
	{
		error.nro_linea = yylineno;
		agregar_error_al_final_con_repeticion (&errores_sintacticos, error);
	}			
	;
	

sentencia_de_iteracion
	:	WHILE '(' expresion ')' sentencia 					
	|	DO sentencia WHILE '(' expresion ')' ';' 			
	|	FOR '(' expresion_opcional ';' expresion_opcional ';' expresion_opcional ')' sentencia	
	| 	WHILE '(' error ')'		
	{
		error.nro_linea = yylineno;
		agregar_error_al_final_con_repeticion (&errores_sintacticos, error);
	}
	|	DO sentencia WHILE '(' error ')' ';' 			
	{
		error.nro_linea = yylineno;
		agregar_error_al_final_con_repeticion (&errores_sintacticos, error);
	}		
	|	FOR '(' error ')' sentencia			
	{
		error.nro_linea = yylineno;
		agregar_error_al_final_con_repeticion (&errores_sintacticos, error);
	}
	;

expresion_opcional
	:	expresion
	|
	;
	
sentencia_de_salto
	:	GOTO IDENTIFICADOR ';'	
	|	CONTINUE ';'			
	|	BREAK ';'				
	|	RETURN ';'				
	|	RETURN expresion ';'	
	| 	RETURN error ';' 	
	{
		error.nro_linea = yylineno;
		agregar_error_al_final_con_repeticion (&errores_sintacticos, error);
	}
	;

expresion
	:	expresion_de_asignacion
	|	expresion ','  expresion_de_asignacion 	
	;

expresion_de_asignacion
	:	expresion_condicional	
	|	expresion_unaria operador_de_asignacion expresion_de_asignacion
	| 	expresion_unaria operador_de_asignacion error ';' 	
	{
		error.nro_linea = yylineno;
		agregar_error_al_final_con_repeticion (&errores_sintacticos, error);
	}
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
	|	expresion_logica_OR OPERADOR_LOGICO_OR error ';'	
	{
		error.nro_linea = yylineno;
		agregar_error_al_final_con_repeticion (&errores_sintacticos, error);
	}
	;	

expresion_logica_AND
	:	expresion_OR_inclusiva
	|	expresion_logica_AND OPERADOR_LOGICO_AND expresion_OR_inclusiva
	|	expresion_logica_AND OPERADOR_LOGICO_AND error ';' 
	{
		error.nro_linea = yylineno;
		agregar_error_al_final_con_repeticion (&errores_sintacticos, error);
	}
	;

expresion_OR_inclusiva
	:	expresion_XOR
	|	expresion_OR_inclusiva '|' expresion_XOR
	|	expresion_OR_inclusiva '|' error ';' 
	{
		error.nro_linea = yylineno;
		agregar_error_al_final_con_repeticion (&errores_sintacticos, error);
	}
	;

expresion_XOR
	:	expresion_AND
	|	expresion_XOR '^' expresion_AND
	;

expresion_AND
	:	expresion_de_igualdad
	|	expresion_AND '&' expresion_de_igualdad
	|	expresion_AND '&' error ';' 
	{
		error.nro_linea = yylineno;
		agregar_error_al_final_con_repeticion (&errores_sintacticos, error);
	}
	;

expresion_de_igualdad
	:	expresion_relacional
	|	expresion_de_igualdad OPERADOR_DE_IGUALDAD expresion_relacional
	|	expresion_de_igualdad OPERADOR_DE_DESIGUALDAD expresion_relacional
	|	expresion_de_igualdad OPERADOR_DE_IGUALDAD error ';' 
	{
		error.nro_linea = yylineno;
		agregar_error_al_final_con_repeticion (&errores_sintacticos, error);
	}
	|	expresion_de_igualdad OPERADOR_DE_DESIGUALDAD error ';' 
	{
		error.nro_linea = yylineno;
		agregar_error_al_final_con_repeticion (&errores_sintacticos, error);
	}
	;

expresion_relacional
	:	expresion_de_desplazamiento
	|	expresion_relacional '<' expresion_de_desplazamiento
	|	expresion_relacional MENOR_O_IGUAL expresion_de_desplazamiento
	|	expresion_relacional '>' expresion_de_desplazamiento
	|	expresion_relacional MAYOR_O_IGUAL expresion_de_desplazamiento
	|	expresion_relacional '<' error ';' 	
	{
		error.nro_linea = yylineno;
		agregar_error_al_final_con_repeticion (&errores_sintacticos, error);
	}
	|	expresion_relacional MENOR_O_IGUAL error ';' 	
	{
		error.nro_linea = yylineno;
		agregar_error_al_final_con_repeticion (&errores_sintacticos, error);
	}
	|	expresion_relacional '>' error ';' 	
	{
		error.nro_linea = yylineno;
		agregar_error_al_final_con_repeticion (&errores_sintacticos, error);
	}
	|	expresion_relacional MAYOR_O_IGUAL error ';' 	
	{
		error.nro_linea = yylineno;
		agregar_error_al_final_con_repeticion (&errores_sintacticos, error);
	}
	;

expresion_de_desplazamiento
	:	expresion_aditiva 
	|	expresion_de_desplazamiento OPERADOR_DESPLAZAMIENTO_DE_BITS_A_IZQUIERDA expresion_aditiva 
	|	expresion_de_desplazamiento OPERADOR_DESPLAZAMIENTO_DE_BITS_A_DERECHA expresion_aditiva 
	;

expresion_aditiva
	:	expresion_multiplicativa  
	{		
		strcpy (un_tipo_dato, tipo_dato);
		if (!strcmp (un_tipo_dato, "identificador"))
		{
			strcpy (un_identificador, $<s>1.sval);
			if ( rutina_semantica_uso_de_variable (variables,un_identificador,un_tipo_dato) == 0)
				printf ("Variable no declarada: %s\n", un_identificador);
		}
		else
			strcpy (un_identificador, "-");
			
	}
	|	expresion_aditiva '+' expresion_multiplicativa 
	{ 	
			strcpy (otro_tipo_dato, tipo_dato);
			if (!strcmp (otro_tipo_dato, "identificador"))
			{
				strcpy (otro_identificador, $<s>3.sval);

				if ( rutina_semantica_uso_de_variable (variables, otro_identificador, otro_tipo_dato) == 0)
					printf ("Variable no declarada: %s\n", otro_identificador);
			}
			else
				strcpy (otro_identificador, "-");
							
			if (rutina_semantica_tipo_dato_suma (un_tipo_dato, otro_tipo_dato) == 0)
			{
				printf ("Suma ok\n");
				printf ("Identificador: %s, Tipo Dato: %s\n", un_identificador,un_tipo_dato);
				printf ("Identificador: %s, Tipo Dato: %s\n", otro_identificador ,otro_tipo_dato);
			}
			else
			{
				printf ("Error en los tipos de dato en la Suma\n");
				printf ("Identificador: %s, Tipo Dato: %s\n", un_identificador, un_tipo_dato);
				printf ("Identificador: %s, Tipo Dato: %s\n", otro_identificador , otro_tipo_dato);
			}
			
	}
	|	expresion_aditiva '-' expresion_multiplicativa
	|	expresion_aditiva '-' error ';' 	
	{
		error.nro_linea = yylineno;
		agregar_error_al_final_con_repeticion (&errores_sintacticos, error);
	}
	;

expresion_multiplicativa
	:	expresion_de_casteo	
	|	expresion_multiplicativa '*' expresion_de_casteo 
	|	expresion_multiplicativa '/' expresion_de_casteo 
	|	expresion_multiplicativa '%' expresion_de_casteo
	|	expresion_multiplicativa '*' error ';' 	
	{
		error.nro_linea = yylineno;
		agregar_error_al_final_con_repeticion (&errores_sintacticos, error);
	}
	|	expresion_multiplicativa '/' error ';' 	
	{
		error.nro_linea = yylineno;
		agregar_error_al_final_con_repeticion (&errores_sintacticos, error);
	}
	|	expresion_multiplicativa '%' error ';' 	
	{
		error.nro_linea = yylineno;
		agregar_error_al_final_con_repeticion (&errores_sintacticos, error);
	}
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
	|	INCREMENTO error ';'  	
	{
		error.nro_linea = yylineno;
		agregar_error_al_final_con_repeticion (&errores_sintacticos, error);
	}
	|	DECREMENTO error ';'	
	{
		error.nro_linea = yylineno;
		agregar_error_al_final_con_repeticion (&errores_sintacticos, error);
	}
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
	{
		int estado = 0;
		if (hubo_error_con_argumentos == TRUE)
		{
			eliminar_parametros (argumentos);
			argumentos = NULL;
		}
		else
		{
			nodo_parametro_t * parametros_encontrados = NULL;
			if ( (parametros_encontrados = buscar_funcion_parametros (funciones, $<s>1.sval) ) != NULL) //Encontro la funcion
			{
				if ( (estado = rutina_semantica_cantidad_y_tipos_de_parametros (parametros_encontrados,argumentos)) == 0)
					printf("LLamada a funcion correcta: %-10s\n", $<s>1.sval);
				else if (estado == 1)
					printf("Cantidad de argumentos incorrectos en funcion: %s\n", $<s>1.sval);
				else if (estado == 2)
					printf("Tipo de argumentos incorrectos en funcion: %s\n", $<s>1.sval);
			}
			else
			{
				printf("No encontro la funcion: %-10s\n", $<s>1.sval);
			}
			//strcpy (nombre_llamada_funcion, $<s>1.sval);
			//imprimir_parametros (argumentos, $<s>1.sval);
			eliminar_parametros (argumentos);
			argumentos = NULL;
		}
		//printf("Llamada a funcion: %-10s\n", $<s>1.sval);
	}
	|	expresion_posfija '.' IDENTIFICADOR
	|	expresion_posfija OPERADOR_FLECHA IDENTIFICADOR
	|	expresion_posfija INCREMENTO
	|	expresion_posfija DECREMENTO
	;
	
expresion_primaria
	:	IDENTIFICADOR   			{strcpy (tipo_dato, "identificador");}
	|	constante	
	| 	CADENA_DE_CARACTERES		{strcpy (tipo_dato, "cadena_de_caracteres");}
	|	'(' expresion ')'	 
	;

lista_de_expresiones_de_argumentos
	:	expresion_de_asignacion 
	{
		if (!strcmp (tipo_dato , "identificador"))
		{
			if (rutina_semantica_control_de_declaracion ($<s>1.sval,tipo_dato_argumento,funciones,variables) == 0)//Fue encontrado
			{
				strcpy(argumento.nombre_parametro, $<s>1.sval); 
				strcpy(argumento.tipo_dato, tipo_dato_argumento);
				agregar_parametro_al_final (&argumentos, argumento);
			}
			else
				hubo_error_con_argumentos = TRUE;
				
			//printf("%s%-20s\t%s%s\n", "Identificador: ", $<s>1.sval,"Tipo Dato: ", tipo_dato);
		}
		else
		{
			strcpy(argumento.nombre_parametro, ""); 
			strcpy(argumento.tipo_dato, tipo_dato);
			agregar_parametro_al_final (&argumentos, argumento);
		}
		//printf("Tipo Dato Primer Argumento: %s\n", tipo_dato);
		//printf("Tipo Dato Primer Argumento: %s\t%s%s\n", $<sval>1,"Tipo Dato: ", tipo_dato);
	}
	|	lista_de_expresiones_de_argumentos ',' expresion_de_asignacion 
	{
		if (!strcmp (tipo_dato , "identificador"))
		{
			if (rutina_semantica_control_de_declaracion ($<s>1.sval,tipo_dato_argumento,funciones,variables) == 0)//Fue encontrado
			{
				strcpy(argumento.nombre_parametro, $<s>1.sval); 
				strcpy(argumento.tipo_dato, tipo_dato_argumento);
				agregar_parametro_al_final (&argumentos, argumento);
			}
			else
				hubo_error_con_argumentos = TRUE;
			//printf("%s%-20s\t%s%s\n", "Identificador: ", $<s>3.sval,"Tipo Dato: ", tipo_dato);
		}
		else
		{
			strcpy(argumento.nombre_parametro, ""); 
			strcpy(argumento.tipo_dato, tipo_dato);
			agregar_parametro_al_final (&argumentos, argumento);
			//printf("Tipo Dato Otro Argumento: %s\n", tipo_dato);
		}
		//printf("Otro Argumento Llamada a Funcion: %s\t%s%s\n", $<s>3.sval, "Tipo Dato: ", tipo_dato);
	}
	;
 
constante
	:	constante_entera  	{strcpy (tipo_dato, "int");}
	|	CONSTANTE_CARACTER	{strcpy (tipo_dato, "char");}
	|	CONSTANTE_REAL			{strcpy (tipo_dato, "double");}
	;
	
constante_entera
	:	CONSTANTE_DECIMAL
	|	CONSTANTE_OCTAL
	|	CONSTANTE_HEXADECIMAL
	;

%%



int main (int argc, const char * argv[])
{
	#if YYDEBUG
        yydebug = 1;
	#endif
	if (argc != 2)
	{
		puts ("Error: El nobre de archivo a analizar debe ser pasado junto con el ejecutable.");
		return 1;
	}
	yyin = fopen (argv[1], "r");
	
	yyparse ();
 
	imprimir_variables (variables);
	eliminar_variables (variables);
	
	imprimir_funciones (funciones);
	eliminar_funciones (funciones);

	imprimir_errores_lexicos( errores_lexicos, ETIQUETA_PALABRAS_O_CARACTERES_NO_RECONOCIDOS,
								ETIQUETA_NUMERO_DE_LINEA, CABECERA_PALABRAS_O_CARACTERES_NO_RECONOCIDOS	);
	eliminar_lista_errores( errores_lexicos );
	imprimir_errores_sintacticos( errores_sintacticos, ETIQUETA_SENTENCIAS_NO_RECONOCIDAS,
								ETIQUETA_NUMERO_DE_LINEA, CABECERA_SENTENCIAS_NO_RECONOCIDAS);
	eliminar_lista_errores( errores_sintacticos );
	
	fclose (yyin);
	
	return 0;
}

