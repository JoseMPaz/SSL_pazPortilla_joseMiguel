%option noyywrap

/**************** INICIO DEFINICIONES ******************/
%{
// Inclusion de Bibliotecas
#include <stdio.h>
#include "lista.h"
#include "palabra_entero.h"
// Definicion de Variables Globales 
//nodo_t * lista_palabras_reservadas = NULL;
//palabra_reservada_t * palabra_reservada;
//void (*pf_imprimir) (void * info);


%}
CARACTER_ESPACIO		[" "]
LETRA						[a-zA-z]
DIGITO_HEXADECIMAL 	[0-9A-Fa-f]
DIGITO_DECIMAL	  		[0-9]
DIGITO_OCTAL			[0-7]
GUION_BAJO				"_"
TABULACION				"\t"
VACIO						""

CONSTANTE_DECIMAL 						[1-9]{DIGITO_DECIMAL} 
CONSTANTE_OCTAL							0{DIGITO_OCTAL}* 
IDENTIFICADOR								({LETRA}|{GUION_BAJO})({LETRA}|{DIGITO_DECIMAL}|GUION_BAJO)*
OPERADOR_O_CARACTER_DE_PUNTUACION 	"<"|">"|";"|"."
CONSTANTE_LITERAL_CADENA				\"[^\n"]*\"	
FUNCION_PRINCIPAL							["main"]
PALABRAS_RESERVADAS     				["printf"]
CONSTANTE_CADENA_DE_CARACTERES		\"[^\n"]*\"
CONSTANTE_CARACTER						\'.\'
CONSTANTE_ENTERA 							-?[1-9][0-9]{0,4}
CONSTANTE_REAL 							-?[0-9]{0,6}{"."}[0-9]{0,6}
COMENTARIO_DE_UNA_LINEA 				\/\/.*
COMENTARIO_MULTILINEAS 					\/\*([^*]|(\*+[^*/]))*\*+\/


OPERADORES_Y_CARACTERES_DE_PUNTUACION					["+"]|["-"]|["*"]|["/"]|["."]|[","]|[";"]|["<"]|[">"]|["("]|[")"]|"\#"|">="|"<="|"\{"|"\}"
PALABRAS_RESERVADAS_TIPOS_DE_DATO     					"void"|"char"|"int"|"float"|"double"
PALABRAS_RESERVADAS_DIRECTIVAS_PREPROCESAMIENTO		"include"|"define"|"ifndef"|"ifdef"|"endif"
PALABRAS_RESERVADAS_ESTRUCTURA_DE_CONTROL				"goto"|"if"|"else"|"for"|"do"|"while"|"switch"|"case"|"break"|"continue"|"default"|"return"
PALABRAS_RESERVADAS_MODIFICADOR_ALMACENAMIENTO		"auto"|"register"|"extern"|"static"
PALABRAS_RESERVADAS_MODIFICADOR_TIPO_DE_DATO			"const"|"volatile"
PALABRAS_RESERVADAS_MODIFICADOR_VARIABLE_NUMERICA	"long"|"short"|"signed"|"unsigned"
PALABRAS_RESERVADAS_TIPOS_DE_DATO_COMPUESTOS			"enum"|"struct"|"union"
PALABRAS_RESERVADAS_MANIPULACION_DE_MEMORIA			"malloc"|"calloc"|"realloc"|"free"
PALABRAS_RESERVADAS_ENTRADA_SALIDA_DE_DATOS			"printf"|"fprintf"|"scanf"|"fscanf"|"getchar"|"fgets"
PALABRAS_RESERVADAS_PUNTO_ENTRADA_PROGRAMA			"main"


/**************** FIN DEFINICIONES ******************/

/**************** INICIO REGLAS ******************/
%%

{OPERADORES_Y_CARACTERES_DE_PUNTUACION}					{printf("OPERADORES_Y_CARACTERES_DE_PUNTUACION: %s\n", yytext);} 
{PALABRAS_RESERVADAS_TIPOS_DE_DATO}							{printf("PALABRAS_RESERVADAS_TIPOS_DE_DATO: %s\n", yytext);} 
{PALABRAS_RESERVADAS_DIRECTIVAS_PREPROCESAMIENTO}		{printf("PALABRAS_RESERVADAS_DIRECTIVAS_PREPROCESAMIENTO: %s\n", yytext);} 
{PALABRAS_RESERVADAS_ESTRUCTURA_DE_CONTROL}				{printf("PALABRAS_RESERVADAS_ESTRUCTURA_DE_CONTROL: %s\n", yytext);}
{PALABRAS_RESERVADAS_MODIFICADOR_ALMACENAMIENTO}		{printf("PALABRAS_RESERVADAS_MODIFICADOR_ALMACENAMIENTO: %s\n", yytext);}
{PALABRAS_RESERVADAS_MODIFICADOR_TIPO_DE_DATO}			{printf("PALABRAS_RESERVADAS_MODIFICADOR_TIPO_DE_DATO: %s\n", yytext);}
{PALABRAS_RESERVADAS_MODIFICADOR_VARIABLE_NUMERICA}	{printf("PALABRAS_RESERVADAS_MODIFICADOR_VARIABLE_NUMERICA: %s\n", yytext);}
{PALABRAS_RESERVADAS_TIPOS_DE_DATO_COMPUESTOS}			{printf("PALABRAS_RESERVADAS_TIPOS_DE_DATO_COMPUESTOS: %s\n", yytext);}
{PALABRAS_RESERVADAS_MANIPULACION_DE_MEMORIA}			{printf("PALABRAS_RESERVADAS_MANIPULACION_DE_MEMORIA: %s\n", yytext);}
{PALABRAS_RESERVADAS_ENTRADA_SALIDA_DE_DATOS}			{printf("PALABRAS_RESERVADAS_ENTRADA_SALIDA_DE_DATOS: %s\n", yytext);}
{PALABRAS_RESERVADAS_PUNTO_ENTRADA_PROGRAMA}				{printf("PALABRAS_RESERVADAS_PUNTO_ENTRADA_PROGRAMA: %s\n", yytext);}	
{VACIO}																;
{TABULACION}														;
{CARACTER_ESPACIO} 												;
{CONSTANTE_CARACTER} 											{printf("CONSTANTE_CARACTER: %s\n", yytext);}
{IDENTIFICADOR} 													{printf("IDENTIFICADOR: %s\n", yytext);} 
{COMENTARIO_DE_UNA_LINEA} 										{printf("COMENTARIO_DE_UNA_LINEA: %s\n", yytext);} 
{COMENTARIO_MULTILINEAS}										{printf("COMENTARIO_MULTILINEAS: %s\n", yytext);} 
{CONSTANTE_CADENA_DE_CARACTERES} 							{printf("CONSTANTE_CADENA_DE_CARACTERES: %s\n", yytext);}
{CONSTANTE_OCTAL}													{printf("CONSTANTE_OCTAL: %s\n", yytext);}
. 																		{printf("Ninguna regla para: %s\n", yytext);}


%%
/**************** FIN REGLAS ******************/

/**************** INICIO CODIGO USUARIO ******************/
int main(void) 
{
   
    /* Acciones previas a la invocación den analizador léxico */

    yyin = fopen("entrada.c", "r");
	

	/* Invocación del analizador léxico */

	yylex();
	
	//puts ("PALABRAS RESERVADAS:");
	//pf_imprimir = imprimir_palabra_reservada;
	//imprimir(lista_palabras_reservadas,pf_imprimir);
    /* Acciónes posteriores a la ejecución del analizador léxico, 
    sirven por ejemplo, para hacer un informen de resumen.1 */

	//eliminar(lista_palabras_reservadas);
	
	fclose(yyin);

    return 0;
}
/**************** FIN CODIGO USUARIO ******************/

