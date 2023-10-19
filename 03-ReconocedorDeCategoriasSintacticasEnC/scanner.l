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
directiva_de_preprocesamiento							\#(include|define|ifndef|ifdef)(.*)|\#endif

%option noyywrap
%option yylineno

%%
{directiva_de_preprocesamiento}						;
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
"void"														{strcpy (yylval.sval, yytext); return VOID;}
"char"														{strcpy (yylval.sval, yytext);return CHAR;}
"short"														{strcpy (yylval.sval, yytext);return SHORT;}
"int"															{strcpy (yylval.sval, yytext);return INT;}
"long"														{strcpy (yylval.sval, yytext);return LONG;}
"float"														{strcpy (yylval.sval, yytext);return FLOAT;}
"double"														{strcpy (yylval.sval, yytext);return DOUBLE;}
"signed"														{strcpy (yylval.sval, yytext);return SIGNED;}
"unsigned"													{strcpy (yylval.sval, yytext);return UNSIGNED;}
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
"if"															{strcpy (yylval.sval, yytext);return IF;}
"else"														{strcpy (yylval.sval, yytext);return ELSE;}
"switch"														{strcpy (yylval.sval, yytext);return SWITCH;}
"for"															{strcpy (yylval.sval, yytext);return FOR;}
"while"														{strcpy (yylval.sval, yytext);return WHILE;}
"do"															{strcpy (yylval.sval, yytext);return DO;}
"goto"														{strcpy (yylval.sval, yytext);return GOTO;}
"continue"													{strcpy (yylval.sval, yytext);return CONTINUE;}
"break"														{strcpy (yylval.sval, yytext);return BREAK;}
"return"														{strcpy (yylval.sval, yytext);return RETURN;}
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
{cadena_de_caracteres}				 					{strcpy (yylval.sval, yytext);return CADENA_DE_CARACTERES; }
{constante_decimal}										{ yylval.ival = (int) strtol (yytext, NULL, 10); return CONSTANTE_DECIMAL; }
{constante_octal}											{ yylval.ival = (int) strtol(yytext, NULL, 8); return CONSTANTE_OCTAL; }
{constante_hexadecimal}									{ yylval.ival = (int) strtol(yytext, NULL, 16); return CONSTANTE_HEXADECIMAL; }
{constante_caracter}										{strcpy (yylval.sval, yytext); return CONSTANTE_CARACTER; }
{constante_real}											{ yylval.dval = strtod (yytext,NULL); return CONSTANTE_REAL; }
{constante_de_enumeracion}								{ strcpy (yylval.sval, yytext); return CONSTANTE_DE_ENUMERACION; }
{identificador}											{ strcpy (yylval.sval, yytext); return IDENTIFICADOR; }

[ \t\n]														{ ; } // Ignora espacios en blanco y tabuladores
.																{ yyerror("Carácter no válido"); }

%%

int yyerror (char const *s)
{
	puts(s);
	return 1;
}
