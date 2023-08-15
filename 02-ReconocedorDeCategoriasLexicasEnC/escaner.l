%option noyywrap
%option yylineno
/**************** INICIO DEFINICIONES ******************/
%{
// Inclusion de Bibliotecas
#include <stdio.h>
#include "lista_cadena_entero.h"
#include "lista_enteros.h"
#include "lista_reales.h"

// Definicion de Variables Globales 
int (*criterio)(cadena_entero_t d1, cadena_entero_t d2);
void (*accion)(nodo_cadena_entero_t * aux);
cadena_entero_t cadena_entero;
nodo_cadena_entero_t * identificadores = NULL;
nodo_cadena_entero_t * literales_cadena = NULL;
nodo_cadena_entero_t * palabras_reservadas = NULL;
nodo_enteros_t * octales = NULL;

//nodo_t * lista_palabras_reservadas = NULL;
//palabra_reservada_t * palabra_reservada;
//void (*pf_imprimir) (void * info);
int numero_de_linea = 1;


%}
CARACTER_ESPACIO		[" "]
LETRA						[a-zA-z]
DIGITO_HEXADECIMAL 	[0-9A-Fa-f]
DIGITO_DECIMAL	  		[0-9]
DIGITO_OCTAL			[0-7]
GUION_BAJO				"_"
BASURA					[ \t]+
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


OPERADORES_Y_CARACTERES_DE_PUNTUACION					["+"]|["-"]|["*"]|["/"]|["."]|[","]|[";"]|["<"]|[">"]|["("]|[")"]|">="|"<="|"\{"|"\}"
PALABRAS_RESERVADAS_TIPOS_DE_DATO     					"int"|"char"|"float"|"double"|"void"
PALABRAS_RESERVADAS_DIRECTIVAS_PREPROCESAMIENTO		\#(include|define|ifndef|ifdef)(.*)|\#endif
PALABRAS_RESERVADAS_ESTRUCTURA_DE_CONTROL				"goto"|"if"|"else"|"for"|"do"|"while"|"switch"|"case"|"break"|"continue"|"default"|"return"
PALABRAS_RESERVADAS_MODIFICADOR_ALMACENAMIENTO		"auto"|"register"|"extern"|"static"
PALABRAS_RESERVADAS_MODIFICADOR_TIPO_DE_DATO			"const"|"volatile"
PALABRAS_RESERVADAS_MODIFICADOR_VARIABLE_NUMERICA	"long"|"short"|"signed"|"unsigned"
PALABRAS_RESERVADAS_TIPOS_DE_DATO_COMPUESTOS			"enum"|"struct"|"union"
PALABRAS_RESERVADAS_PUNTO_ENTRADA_PROGRAMA			"main"


/**************** FIN DEFINICIONES ******************/

/**************** INICIO REGLAS ******************/
%%
{OPERADORES_Y_CARACTERES_DE_PUNTUACION}					{printf("OPERADORES_Y_CARACTERES_DE_PUNTUACION: %s\n", yytext);} 
{PALABRAS_RESERVADAS_DIRECTIVAS_PREPROCESAMIENTO}		{printf("PALABRAS_RESERVADAS_DIRECTIVAS_PREPROCESAMIENTO: %s\n", yytext);
																		strcpy (cadena_entero.cadena,yytext); 	
																		cadena_entero.entero=(int)DIRECTIVA_DE_PREPROCESAMIENTO;											  
																		agregar_cadena_entero_al_final_con_repeticion(&palabras_reservadas, cadena_entero);}  
{PALABRAS_RESERVADAS_PUNTO_ENTRADA_PROGRAMA}				{printf("PALABRAS_RESERVADAS_PUNTO_ENTRADA_PROGRAMA: %s\n", yytext);
																		strcpy (cadena_entero.cadena,yytext); 	
																		cadena_entero.entero=(int)PUNTO_DE_ENTRADA_AL_PROGRAMA;
																		agregar_cadena_entero_al_final_con_repeticion(&palabras_reservadas, cadena_entero);}
{PALABRAS_RESERVADAS_ESTRUCTURA_DE_CONTROL}				{printf("PALABRAS_RESERVADAS_ESTRUCTURA_DE_CONTROL: %s\n", yytext);
																		strcpy (cadena_entero.cadena,yytext); cadena_entero.entero=(int)ESTRUCTURA_DE_CONTROL;
																		agregar_cadena_entero_al_final_con_repeticion(&palabras_reservadas, cadena_entero);} 
{PALABRAS_RESERVADAS_MODIFICADOR_ALMACENAMIENTO}		{printf("PALABRAS_RESERVADAS_MODIFICADOR_ALMACENAMIENTO: %s\n", yytext);
																		strcpy (cadena_entero.cadena,yytext); 	
																		cadena_entero.entero=(int)MODIFICADOR_DE_ALMACENAMIENTO;
																		agregar_cadena_entero_al_final_con_repeticion(&palabras_reservadas, cadena_entero);}
{PALABRAS_RESERVADAS_MODIFICADOR_TIPO_DE_DATO}			{printf("PALABRAS_RESERVADAS_MODIFICADOR_TIPO_DE_DATO: %s\n", yytext);
																		strcpy (cadena_entero.cadena,yytext); 	
																		cadena_entero.entero=(int)MODIFICADOR_DE_TIPO_DE_DATO;
																		agregar_cadena_entero_al_final_con_repeticion(&palabras_reservadas, cadena_entero);}
{PALABRAS_RESERVADAS_MODIFICADOR_VARIABLE_NUMERICA}	{printf("PALABRAS_RESERVADAS_MODIFICADOR_VARIABLE_NUMERICA: %s\n", yytext);
																		strcpy (cadena_entero.cadena,yytext); 	
																		cadena_entero.entero=(int)MODIFICADOR_VARIABLE_NUMERICA;
																		agregar_cadena_entero_al_final_con_repeticion(&palabras_reservadas, cadena_entero);}
{PALABRAS_RESERVADAS_TIPOS_DE_DATO_COMPUESTOS}			{printf("PALABRAS_RESERVADAS_TIPOS_DE_DATO_COMPUESTOS: %s\n", yytext);
																		strcpy (cadena_entero.cadena,yytext); 	
																		cadena_entero.entero=(int)TIPOS_DE_DATOS_COMPUESTOS;
																		agregar_cadena_entero_al_final_con_repeticion(&palabras_reservadas, cadena_entero);}
{CONSTANTE_CARACTER} 											{printf("CONSTANTE_CARACTER: %s\n", yytext);}
{PALABRAS_RESERVADAS_TIPOS_DE_DATO}							{printf("PALABRAS_RESERVADAS_TIPOS_DE_DATO: %s\n", yytext);
																		strcpy (cadena_entero.cadena,yytext);cadena_entero.entero=(int)TIPO_DE_DATO;
																		agregar_cadena_entero_al_final_con_repeticion(&palabras_reservadas, cadena_entero);} 
{IDENTIFICADOR} 													{printf("IDENTIFICADOR: %s\t", yytext);
																		criterio = criterio_alfabetico; accion = agregar_uno_a_entero;
																		strcpy (cadena_entero.cadena,yytext);cadena_entero.entero=1;
																		agregar_cadena_entero_ordenado_sin_repeticion (&identificadores, cadena_entero, 
																		accion, criterio);} 
{COMENTARIO_DE_UNA_LINEA} 										{printf("COMENTARIO_DE_UNA_LINEA: %s\n", yytext);} 
{COMENTARIO_MULTILINEAS}										{printf("COMENTARIO_MULTILINEAS: %s\n", yytext);} 
{CONSTANTE_CADENA_DE_CARACTERES} 							{printf("CONSTANTE_CADENA_DE_CARACTERES: %s\n", yytext);
																		criterio = criterio_longitud; accion = desechar;
																		strcpy (cadena_entero.cadena,yytext); cadena_entero.entero = yyleng - 2;
																		agregar_cadena_entero_ordenado_sin_repeticion (&literales_cadena, cadena_entero, 
																		accion, criterio);}
{CONSTANTE_OCTAL}													{printf("CONSTANTE_OCTAL: %s\n", yytext);
																		agregar_enteros_al_final_con_repeticion (&octales,
																		convertir_cadena_octal_a_entero(yytext));}	
{VACIO}																;
{BASURA}																;
.																		{printf("NO_RECONOCIDA: %s\t", yytext);printf("%s%d\n","En la linea: ", yylineno);}
\n																		{numero_de_linea++;}




%%
/**************** FIN REGLAS ******************/

/**************** INICIO CODIGO USUARIO ******************/
int main(void) 
{
   
    /* Acciones previas a la invocación den analizador léxico */
    yyin = fopen("entrada.c", "r");
	

	/* Invocación del analizador léxico */
	yylex();
	
	imprimir_cadena_entero(identificadores, "Identificador: ", "Cantidad de repeticiones: ","IDENTIFICADORES");
	eliminar_lista_cadena_entero(identificadores);
	
	imprimir_cadena_entero(literales_cadena, "Literal Cadena: ", "Longitud: ","LITERALES CADENA");
	eliminar_lista_cadena_entero(literales_cadena);
	
	imprimir_palabra_reservada(palabras_reservadas);
	eliminar_lista_cadena_entero(palabras_reservadas);
	
	imprimir_enteros(octales,"CONSTANTES OCTALES");
	eliminar_lista_enteros(octales);
	
	fclose(yyin);

    return 0;
}
/**************** FIN CODIGO USUARIO ******************/

