%option noyywrap
/**************** INICIO DEFINICIONES ******************/
%{
// Inclusion de Bibliotecas
#include <stdio.h>
#include "mis_funciones.h"
// Definicion de Variables Globales 
int acum = 0;
%}

CARACTER_ESPACIO		[" "]
LETRA						[a-zA-z]
DIGITO_HEXADECIMAL 	[0-9A-Fa-f]
DIGITO_DECIMAL	  		[0-9]
DIGITO_OCTAL			[0-7]
GUION_BAJO				"_"
INICIO_COMENTARIO 	["/*"]
FIN_COMENTARIO 	["*/"]
OPERADOR_MENOR ["<"]
OPERADOR_MAYOR [">"]


CONSTANTE_DECIMAL 						[1-9]{DIGITO_DECIMAL} 
CONSTANTE_OCTAL							0{DIGITO_OCTAL}* 
IDENTIFICADOR								({LETRA}|{GUION_BAJO})({LETRA}|{DIGITO_DECIMAL}|GUION_BAJO)*
OPERADOR_O_CARACTER_DE_PUNTUACION 	"<"|">"|";"|"."
CONSTANTE_LITERAL_CADENA				\"[^\n"]*\"	
FUNCION_PRINCIPAL							["main"]
PALABRAS_RESERVADAS     				["printf"]
CONSTANTE_CADENA_DE_CARACTERES		\"[^\n"]*\"

CONSTANTE_ENTERA -?[1-9][0-9]{0,4}
CONSTANTE_REAL -?[0-9]{0,6}{OPERADOR_PUNTO}[0-9]{0,6}
INCLUCION_DE_BIBLIOTECA "#include"
DEFINICION_DE_CONSTANTE "#define"
COMENTARIO_DE_UNA_LINEA \/\/.*
COMENTARIO_MULTILINEAS \/\*([^*]|(\*+[^*/]))*\*+\/
BIBLIOTECA {OPERADOR_MENOR}{IDENTIFICADOR}".h"{OPERADOR_MAYOR}
MACRO ["A-Z"][A-Z0-9]*
		

/**************** FIN DEFINICIONES ******************/

/**************** INICIO REGLAS ******************/
%%
{CARACTER_ESPACIO} ;
{COMENTARIO_DE_UNA_LINEA} {printf("Se encontro comentario de una linea: %s\n", yytext);} 
{COMENTARIO_MULTILINEAS} {printf("Se encontro comentario multilineas: %s\n", yytext);} 
{INCLUCION_DE_BIBLIOTECA} {printf("Se incluye una biblioteca con la instruccion: %s\n", yytext);} 
{DEFINICION_DE_CONSTANTE} {printf("Se definira una constante con la instruccion: %s\n", yytext);}
{CONSTANTE_CADENA_DE_CARACTERES} {printf("Cadena de caracteres: %s\n", yytext);}
{BIBLIOTECA} {printf("Se encontro la biblioteca: %s\n", yytext);}
{MACRO} {printf("Se encontro la macro: %s\n", yytext);}
. {printf("Ninguna regla para: %s\n", yytext);}

%%
/**************** FIN REGLAS ******************/

/**************** INICIO CODIGO USUARIO ******************/
int main() {
   
    /* Acciones previas a la invocación den analizador léxico */

    yyin = fopen("entrada.c", "r");


    /* Invocación del analizador léxico */

    yylex();
	
    /* Acciónes posteriores a la ejecución del analizador léxico, 
    sirven por ejemplo, para hacer un informen de resumen.1 */



    return 0;
}
/**************** FIN CODIGO USUARIO ******************/

