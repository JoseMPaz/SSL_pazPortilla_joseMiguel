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
nodo_enteros_t * hexadecimales = NULL;
nodo_enteros_t * decimales = NULL;
real_t real;
nodo_real_t * reales = NULL;
int numero_de_linea = 1;
nodo_enteros_t * caracteres = NULL;
nodo_cadena_entero_t * operadores_y_caracteres_de_puntuacion = NULL;
nodo_cadena_entero_t * comentarios = NULL;
nodo_cadena_entero_t * no_reconocidas = NULL;
bool_t hay_un_caracter_no_reconocido = FALSE;


%}
CARACTER_ESPACIO		[" "]
LETRA						[a-zA-Z]
DIGITO_HEXADECIMAL 	[0-9A-Fa-f]
DIGITO_DECIMAL	  		[0-9]
DIGITO_OCTAL			[0-7]
GUION_BAJO				"_"
BASURA					[ \t]+
VACIO						""

CONSTANTE_DECIMAL 						-?[1-9]{DIGITO_DECIMAL}* 
CONSTANTE_OCTAL							0{DIGITO_OCTAL}* 
CONSTANTE_HEXADECIMAL					0[xX]{DIGITO_HEXADECIMAL}+
CONSTANTE_CADENA_DE_CARACTERES		\"[^\n"]*\"
CONSTANTE_CARACTER						\'.\'
CONSTANTE_REAL 							-?[0-9]{0,6}"."[0-9]{0,6}
IDENTIFICADOR								({LETRA}|{GUION_BAJO})({LETRA}|{DIGITO_DECIMAL}|GUION_BAJO)*
OPERADOR_O_CARACTER_DE_PUNTUACION 	"<"|">"|";"|"."
CONSTANTE_LITERAL_CADENA				\"[^\n"]*\"	
FUNCION_PRINCIPAL							["main"]
PALABRAS_RESERVADAS     				["printf"]
COMENTARIO_DE_UNA_LINEA 				\/\/.*
COMENTARIO_MULTILINEAS 					\/\*([^*]|(\*+[^*/]))*\*+\/

OPERADORES_Y_CARACTERES_DE_PUNTUACION	"!="|["="]|["+"]|["-"]|["*"]|["/"]|["."]|[","]|[";"]|["<"]|[">"]|["("]|[")"]|">="|"<="|"\{"|"\}"|"\]"|"\["
PALABRAS_RESERVADAS_TIPOS_DE_DATO     					"int"|"char"|"float"|"double"|"void"
PALABRAS_RESERVADAS_DIRECTIVAS_PREPROCESAMIENTO		\#(include|define|ifndef|ifdef)(.*)|\#endif
PALABRAS_RESERVADAS_ESTRUCTURA_DE_CONTROL				"goto"|"if"|"else"|"for"|"do"|"while"|"switch"|"case"|"break"|"continue"|"default"|"return"
PALABRAS_RESERVADAS_MODIFICADOR_ALMACENAMIENTO		"auto"|"register"|"extern"|"static"
PALABRAS_RESERVADAS_MODIFICADOR_TIPO_DE_DATO			"const"|"volatile"
PALABRAS_RESERVADAS_MODIFICADOR_VARIABLE_NUMERICA	"long"|"short"|"signed"|"unsigned"
PALABRAS_RESERVADAS_TIPOS_DE_DATO_COMPUESTOS			"enum"|"struct"|"union"|"typedef"
PALABRAS_RESERVADAS_PUNTO_ENTRADA_PROGRAMA			"main"


/**************** FIN DEFINICIONES ******************/

/**************** INICIO REGLAS ******************/
%%
{OPERADORES_Y_CARACTERES_DE_PUNTUACION}					{hay_un_caracter_no_reconocido = FALSE;
																		accion = agregar_uno_a_entero;
																		strcpy (cadena_entero.cadena,yytext);
																		cadena_entero.entero=1;
																		agregar_cadena_entero_sin_repeticion (&operadores_y_caracteres_de_puntuacion, 	
																															cadena_entero, accion);} 
{PALABRAS_RESERVADAS_DIRECTIVAS_PREPROCESAMIENTO}		{hay_un_caracter_no_reconocido = FALSE;
																		strcpy (cadena_entero.cadena,yytext); 	
																		cadena_entero.entero=(int)DIRECTIVA_DE_PREPROCESAMIENTO;											  
																		agregar_cadena_entero_al_final_con_repeticion(&palabras_reservadas, cadena_entero);}  
{PALABRAS_RESERVADAS_PUNTO_ENTRADA_PROGRAMA}				{hay_un_caracter_no_reconocido = FALSE;
																		strcpy (cadena_entero.cadena,yytext); 	
																		cadena_entero.entero=(int)PUNTO_DE_ENTRADA_AL_PROGRAMA;
																		agregar_cadena_entero_al_final_con_repeticion(&palabras_reservadas, cadena_entero);}
{PALABRAS_RESERVADAS_ESTRUCTURA_DE_CONTROL}				{hay_un_caracter_no_reconocido = FALSE;
																		strcpy (cadena_entero.cadena,yytext); 
																		cadena_entero.entero=(int)ESTRUCTURA_DE_CONTROL;
																		agregar_cadena_entero_al_final_con_repeticion(&palabras_reservadas, cadena_entero);} 
{PALABRAS_RESERVADAS_MODIFICADOR_ALMACENAMIENTO}		{hay_un_caracter_no_reconocido = FALSE;
																		strcpy (cadena_entero.cadena,yytext); 	
																		cadena_entero.entero=(int)MODIFICADOR_DE_ALMACENAMIENTO;
																		agregar_cadena_entero_al_final_con_repeticion(&palabras_reservadas, cadena_entero);}
{PALABRAS_RESERVADAS_MODIFICADOR_TIPO_DE_DATO}			{hay_un_caracter_no_reconocido = FALSE;
																		strcpy (cadena_entero.cadena,yytext); 	
																		cadena_entero.entero=(int)MODIFICADOR_DE_TIPO_DE_DATO;
																		agregar_cadena_entero_al_final_con_repeticion(&palabras_reservadas, cadena_entero);}
{PALABRAS_RESERVADAS_MODIFICADOR_VARIABLE_NUMERICA}	{hay_un_caracter_no_reconocido = FALSE;
																		strcpy (cadena_entero.cadena,yytext); 	
																		cadena_entero.entero=(int)MODIFICADOR_VARIABLE_NUMERICA;
																		agregar_cadena_entero_al_final_con_repeticion(&palabras_reservadas, cadena_entero);}
{PALABRAS_RESERVADAS_TIPOS_DE_DATO_COMPUESTOS}			{hay_un_caracter_no_reconocido = FALSE;
																		strcpy (cadena_entero.cadena,yytext); 	
																		cadena_entero.entero=(int)TIPOS_DE_DATOS_COMPUESTOS;
																		agregar_cadena_entero_al_final_con_repeticion(&palabras_reservadas, cadena_entero);}
{PALABRAS_RESERVADAS_TIPOS_DE_DATO}							{hay_un_caracter_no_reconocido = FALSE;
																		strcpy (cadena_entero.cadena,yytext);cadena_entero.entero=(int)TIPO_DE_DATO;
																		agregar_cadena_entero_al_final_con_repeticion(&palabras_reservadas, cadena_entero);} 
{IDENTIFICADOR} 													{hay_un_caracter_no_reconocido = FALSE;
																		criterio = criterio_alfabetico; 
																		accion = agregar_uno_a_entero;
																		strcpy (cadena_entero.cadena,yytext);
																		cadena_entero.entero=1;
																		agregar_cadena_entero_ordenado_sin_repeticion (&identificadores, cadena_entero, 
																																		accion, criterio);} 
{COMENTARIO_DE_UNA_LINEA} 										{hay_un_caracter_no_reconocido = FALSE;
																		strcpy (cadena_entero.cadena,yytext); 	
																		cadena_entero.entero=(int)UNA_LINEA;	
																		agregar_cadena_entero_al_final_con_repeticion(&comentarios, cadena_entero);} 
{COMENTARIO_MULTILINEAS}										{hay_un_caracter_no_reconocido = FALSE;
																		strcpy (cadena_entero.cadena,yytext); 	
																		cadena_entero.entero=(int)MULTIPLE_LINEAS;	
																		agregar_cadena_entero_al_final_con_repeticion(&comentarios, cadena_entero);}  
{CONSTANTE_CADENA_DE_CARACTERES} 							{hay_un_caracter_no_reconocido = FALSE;
																		criterio = criterio_longitud; 
																		accion = desechar;
																		strcpy (cadena_entero.cadena,yytext); 
																		cadena_entero.entero = yyleng - 2;
																		agregar_cadena_entero_ordenado_sin_repeticion (&literales_cadena, cadena_entero, 
																																		accion, criterio);}
{CONSTANTE_OCTAL}													{hay_un_caracter_no_reconocido = FALSE;
																		agregar_enteros_al_final_con_repeticion (&octales,
																															convertir_cadena_octal_a_entero(yytext));}
{CONSTANTE_DECIMAL}												{hay_un_caracter_no_reconocido = FALSE;
																		agregar_enteros_al_final_con_repeticion(&decimales, 	
																															convertir_cadena_entera_a_entero(yytext));}
{CONSTANTE_HEXADECIMAL}											{hay_un_caracter_no_reconocido = FALSE;
																		agregar_enteros_al_final_con_repeticion(&hexadecimales, 	
																															convertir_cadena_hexadecimal_a_entero(yytext));}
{CONSTANTE_REAL}													{hay_un_caracter_no_reconocido = FALSE;
																		real.parte_entera=obtener_parte_entera(yytext);
																		real.mantisa = obtener_mantisa(yytext);
																		agregar_reales_al_final_con_repeticion (&reales, real);}	
{CONSTANTE_CARACTER} 											{hay_un_caracter_no_reconocido = FALSE;
																		agregar_enteros_al_final_con_repeticion (&caracteres, yytext[1]);}
{VACIO}																{hay_un_caracter_no_reconocido = FALSE;}
{BASURA}																{hay_un_caracter_no_reconocido = FALSE;};
\n																		{numero_de_linea++;}
.																		{strcpy (cadena_entero.cadena,yytext);
																		cadena_entero.entero = yylineno;
																		agregar_cadena_entero_al_final_con_repeticion_y_bandera (&no_reconocidas, cadena_entero,
																																		&hay_un_caracter_no_reconocido);																		 																									
																		hay_un_caracter_no_reconocido = TRUE;}

%%
/**************** FIN REGLAS ******************/

/**************** INICIO CODIGO USUARIO ******************/
int main(void) 
{
   
    /* Apertura de lectura de un archivo entrada.c */
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
	
	imprimir_enteros(hexadecimales,"CONSTANTES HEXADECIMALES");
	eliminar_lista_enteros(hexadecimales);
	
	imprimir_enteros(decimales,"CONSTANTES DECIMALES");
	eliminar_lista_enteros(decimales);
	
	imprimir_reales (reales);
	eliminar_lista_reales (reales);
	
	imprimir_caracteres (caracteres);
	eliminar_lista_enteros(caracteres);
	
	imprimir_cadena_entero(operadores_y_caracteres_de_puntuacion, 
								"Operador o Caracter de Puntuacion: ", "Cantidad de repeticiones: ",
								"OPERADORES O CARACTERES DE PUNTUACION");
	eliminar_lista_cadena_entero(operadores_y_caracteres_de_puntuacion);
	
	imprimir_comentarios (comentarios);
	eliminar_lista_cadena_entero(comentarios);
	
	imprimir_cadena_entero(no_reconocidas, "Palabra o caracter no reconocido: ", "Numero de linea: ","PALABRAS O CARACTERES NO RECONOCIDOS");
	eliminar_lista_cadena_entero(no_reconocidas);
	
	fclose(yyin);

    return 0;
}
/**************** FIN CODIGO USUARIO ******************/

