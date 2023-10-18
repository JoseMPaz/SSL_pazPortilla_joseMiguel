%{
#include "parser.tab.h"
int yyerror (char const *s);

%}

constante_decimal											[1-9][0-9]*
identificador												[a-zA-Z_][a-zA-Z0-9_]*
asignacion_compuesta										"*="|"/="|"%="|"+="|"-="|"<<="|">>="|"\&="|"^="|"\|="
cadena_de_caracteres										\"[^\n"]*\"
constante_caracter										\'.\'
constante_real												[0-9]{0,6}"."[0-9]{0,6}
constante_octal											0[0-7]* 
constante_hexadecimal									0[xX][0-9A-Fa-f]+
constante_de_enumeracion								[A-Z_][A-Z0-9_]*

%option noyywrap

%%
","															{ return ','; }
"case"														{ return CASE; }
"default"													{ return DEFAULT; }
";"															{ return ';'; }
"("															{ return '('; }
")"															{ return ')'; }
"{"															{ return '{'; }
"}"															{ return '}'; }
"?"															{ return '?'; }
":"															{ return ':'; }
"\|\|"														{ return OPERADOR_LOGICO_OR; }
"\&\&"														{ return OPERADOR_LOGICO_AND; }
"\|"															{ return '|'; }
"^"															{ return '^'; }
"\&"															{ return '&'; }
"=="															{ return OPERADOR_DE_IGUALDAD ; }
"!="															{ return OPERADOR_DE_DESIGUALDAD; }
"<"															{ return '<'; }
">"															{ return '>'; }
"<="															{ return MENOR_O_IGUAL; }
">="															{ return MAYOR_O_IGUAL; }
"<<"															{ return OPERADOR_DESPLAZAMIENTO_DE_BITS_A_IZQUIERDA; }
">>"															{ return OPERADOR_DESPLAZAMIENTO_DE_BITS_A_DERECHA; }
"+"															{ return '+'; }
"-"															{ return '-'; }
"*"															{ return '*'; }
"/"															{ return '/'; }
"%"															{ return '%'; }
"++"															{ return INCREMENTO; }
"--"															{ return DECREMENTO; }
"sizeof"														{ return SIZEOF; }
"~"															{ return '~'; }
"!"															{ return '!'; } 
"\["															{ return '['; }
"\]"															{ return ']'; }
"."															{ return '.'; }
"..."															{ return ELIPSIS; }
"->"															{ return OPERADOR_FLECHA; }	
"="															{ return '='; }
"void"														{return VOID;}
"char"														{return CHAR;}
"short"														{return SHORT;}
"int"															{return INT;}
"long"														{return LONG;}
"float"														{return FLOAT;}
"double"														{return DOUBLE;}
"signed"														{return SIGNED;}
"unsigned"													{return UNSIGNED;}
"volatile"													{return VOLATILE;}
"const"														{return CONST;}	
"auto"														{return AUTO;}
"register"													{return REGISTER;}
"static"														{return STATIC;}
"extern"														{return EXTERN;}
"typedef"													{return TYPEDEF;}
"struct"														{return STRUCT;}
"union"														{return UNION;}
"enum"														{return ENUM;}
"if"															{return IF;}
"else"														{return ELSE;}
"switch"														{return SWITCH;}
"for"															{return FOR;}
"while"														{return WHILE;}
"do"															{return DO;}
"goto"														{return GOTO;}
"continue"													{return CONTINUE;}
"break"														{return BREAK;}
"return"														{return RETURN;}
"*="															{return OPERADOR_ASIGNACION_MULTIPLICACION;}
"/="															{return OPERADOR_ASIGNACION_DIVISION;}
"%="															{return OPERADOR_ASIGNACION_RESTO;}
"+="															{return OPERADOR_ASIGNACION_SUMA;}
"-="															{return OPERADOR_ASIGNACION_RESTA;}
"<<="															{return OPERADOR_ASIGNACION_DESPLAZAMIENTO_DE_BITS_A_IZQUIERDA;}
">>="															{return OPERADOR_ASIGNACION_DESPLAZAMIENTO_DE_BITS_A_DERECHA;}
"&="															{return OPERADOR_ASIGNACION_AND_BIT_A_BIT;}
"^="															{return OPERADOR_ASIGNACION_XOR_BIT_A_BIT;}
"\|="															{return OPERADOR_ASIGNACION_OR_BIT_A_BIT;}
{cadena_de_caracteres}				 					{yylval.sval = strdup(yytext); return CADENA_DE_CARACTERES; }
{constante_decimal}										{ yylval.ival = (int) strtol (yytext, NULL, 10); return CONSTANTE_DECIMAL; }
{constante_octal}											{ yylval.ival = (int) strtol(yytext, NULL, 8); return CONSTANTE_OCTAL; }
{constante_hexadecimal}									{ yylval.ival = (int) strtol(yytext, NULL, 16); return CONSTANTE_HEXADECIMAL; }
{constante_caracter}										{yylval.sval = strdup(yytext); return CONSTANTE_CARACTER; }
{constante_real}											{ yylval.dval = strtod (yytext,NULL); return CONSTANTE_REAL; }
{constante_de_enumeracion}								{ yylval.sval = strdup(yytext); return CONSTANTE_DE_ENUMERACION; }
{identificador}											{ yylval.sval = strdup(yytext); return IDENTIFICADOR; }

[ \t\n]														{ ; } // Ignora espacios en blanco y tabuladores
.																{ yyerror("Carácter no válido"); }

%%

int yyerror (char const *s)
{
	puts(s);
	return 1;
}
