%{
#include "parser.tab.h"
#include "misFunciones.h"
int yyerror (char const *s);

cadena_entero_t cadena_entero;
bool_t hay_un_caracter_no_reconocido = FALSE;
nodo_cadena_entero_t * no_reconocidas = NULL;
%}

constante_decimal										[1-9][0-9]*
identificador											[a-zA-Z_][a-zA-Z0-9_]*
cadena_de_caracteres									\"[^\n"]*\"
constante_caracter										\'.\'
constante_real											[0-9]*[.][0-9]+([eE][+-]?[0-9]+)?|[0-9]+[eE][+-]?[0-9]+ 
constante_octal											0[0-7]* 
constante_hexadecimal									0[xX][0-9A-Fa-f]+
constante_de_enumeracion								[A-Z_][A-Z0-9_]*
directiva_de_preprocesamiento							\#(include|define|ifndef|ifdef)(.*)|\#endif
comentario_de_una_linea									\/\/.*
comentario_multilineas									\/\*([^*]|(\*+[^*/]))*\*+\/

%option noyywrap
%option yylineno

%%

","														{ hay_un_caracter_no_reconocido = FALSE; return ','; }
";"														{ hay_un_caracter_no_reconocido = FALSE; return ';'; }
"("														{ hay_un_caracter_no_reconocido = FALSE; return '('; }
")"														{ hay_un_caracter_no_reconocido = FALSE; return ')'; }
"{"														{ hay_un_caracter_no_reconocido = FALSE; return '{'; }
"}"														{ hay_un_caracter_no_reconocido = FALSE; return '}'; }
"?"														{ hay_un_caracter_no_reconocido = FALSE; return '?'; }
":"														{ hay_un_caracter_no_reconocido = FALSE; return ':'; }
"\|"													{ hay_un_caracter_no_reconocido = FALSE; return '|'; }
"^"														{ hay_un_caracter_no_reconocido = FALSE; return '^'; }
"\&"													{ hay_un_caracter_no_reconocido = FALSE; return '&'; }
"*"														{ hay_un_caracter_no_reconocido = FALSE; return '*'; }
"/"														{ hay_un_caracter_no_reconocido = FALSE; return '/'; }
"%"														{ hay_un_caracter_no_reconocido = FALSE; return '%'; }
"<"														{ hay_un_caracter_no_reconocido = FALSE; return '<'; }
">"														{ hay_un_caracter_no_reconocido = FALSE; return '>'; }
"~"														{ hay_un_caracter_no_reconocido = FALSE; return '~'; }
"!"														{ hay_un_caracter_no_reconocido = FALSE; return '!'; } 
"\["													{ hay_un_caracter_no_reconocido = FALSE; return '['; }
"\]"													{ hay_un_caracter_no_reconocido = FALSE; return ']'; }
"."														{ hay_un_caracter_no_reconocido = FALSE; return '.'; }
"+"														{ hay_un_caracter_no_reconocido = FALSE; return '+'; }
"="														{ hay_un_caracter_no_reconocido = FALSE; return '='; }
"-"														{ hay_un_caracter_no_reconocido = FALSE; return '-'; }

"\|\|"													{ hay_un_caracter_no_reconocido = FALSE; return OPERADOR_LOGICO_OR; }
"\&\&"													{ hay_un_caracter_no_reconocido = FALSE; return OPERADOR_LOGICO_AND; }
"++"													{ hay_un_caracter_no_reconocido = FALSE; return INCREMENTO; }
"--"													{ hay_un_caracter_no_reconocido = FALSE; return DECREMENTO; }
"=="													{ hay_un_caracter_no_reconocido = FALSE; return OPERADOR_DE_IGUALDAD ; }
"!="													{ hay_un_caracter_no_reconocido = FALSE; return OPERADOR_DE_DESIGUALDAD; }
"..."													{ hay_un_caracter_no_reconocido = FALSE; return ELIPSIS; }
"->"													{ hay_un_caracter_no_reconocido = FALSE; return OPERADOR_FLECHA; }	
"<="													{ hay_un_caracter_no_reconocido = FALSE; return MENOR_O_IGUAL; }
">="													{ hay_un_caracter_no_reconocido = FALSE; return MAYOR_O_IGUAL; }
"<<"													{ hay_un_caracter_no_reconocido = FALSE; return OPERADOR_DESPLAZAMIENTO_DE_BITS_A_IZQUIERDA; }
">>"													{ hay_un_caracter_no_reconocido = FALSE; return OPERADOR_DESPLAZAMIENTO_DE_BITS_A_DERECHA; }
"*="													{ hay_un_caracter_no_reconocido = FALSE; return OPERADOR_ASIGNACION_MULTIPLICACION;}
"/="													{ hay_un_caracter_no_reconocido = FALSE; return OPERADOR_ASIGNACION_DIVISION;}
"%="													{ hay_un_caracter_no_reconocido = FALSE; return OPERADOR_ASIGNACION_RESTO;}
"\+="													{ hay_un_caracter_no_reconocido = FALSE; return OPERADOR_ASIGNACION_SUMA;}
"-="													{ hay_un_caracter_no_reconocido = FALSE; return OPERADOR_ASIGNACION_RESTA;}
"<<="													{ hay_un_caracter_no_reconocido = FALSE; return OPERADOR_ASIGNACION_DESPLAZAMIENTO_DE_BITS_A_IZQUIERDA;}
">>="													{ hay_un_caracter_no_reconocido = FALSE; return OPERADOR_ASIGNACION_DESPLAZAMIENTO_DE_BITS_A_DERECHA;}
"&="													{ hay_un_caracter_no_reconocido = FALSE; return OPERADOR_ASIGNACION_AND_BIT_A_BIT;}
"^="													{ hay_un_caracter_no_reconocido = FALSE; return OPERADOR_ASIGNACION_XOR_BIT_A_BIT;}
"\|="													{ hay_un_caracter_no_reconocido = FALSE; return OPERADOR_ASIGNACION_OR_BIT_A_BIT;}

"sizeof"												{ hay_un_caracter_no_reconocido = FALSE; return SIZEOF; }
"case"													{ hay_un_caracter_no_reconocido = FALSE; yylval.s.linea_inicial = yylineno; return CASE; }
"default"												{ hay_un_caracter_no_reconocido = FALSE; yylval.s.linea_inicial = yylineno; return DEFAULT; }
"volatile"												{ hay_un_caracter_no_reconocido = FALSE; return VOLATILE;}
"const"													{ hay_un_caracter_no_reconocido = FALSE; return CONST;}	
"auto"													{ hay_un_caracter_no_reconocido = FALSE; return AUTO;}
"register"												{ hay_un_caracter_no_reconocido = FALSE; return REGISTER;}
"static"												{ hay_un_caracter_no_reconocido = FALSE; return STATIC;}
"extern"												{ hay_un_caracter_no_reconocido = FALSE; return EXTERN;}
"typedef"												{ hay_un_caracter_no_reconocido = FALSE; return TYPEDEF;}
"struct"												{ hay_un_caracter_no_reconocido = FALSE; strcpy (yylval.s.sval, yytext); yylval.s.linea_inicial = yylineno; return STRUCT;}
"union"													{ hay_un_caracter_no_reconocido = FALSE; strcpy (yylval.s.sval, yytext); yylval.s.linea_inicial = yylineno; return UNION;}
"enum"													{ hay_un_caracter_no_reconocido = FALSE; return ENUM;}

"void"													{ hay_un_caracter_no_reconocido = FALSE; strcpy (yylval.s.sval, yytext); return VOID;}
"char"													{ hay_un_caracter_no_reconocido = FALSE; strcpy (yylval.s.sval, yytext); return CHAR;}
"short"													{ hay_un_caracter_no_reconocido = FALSE; strcpy (yylval.s.sval, yytext); return SHORT;}
"int"													{ hay_un_caracter_no_reconocido = FALSE; strcpy (yylval.s.sval, yytext); return INT;}
"long"													{ hay_un_caracter_no_reconocido = FALSE; strcpy (yylval.s.sval, yytext); return LONG;}
"float"													{ hay_un_caracter_no_reconocido = FALSE; strcpy (yylval.s.sval, yytext); return FLOAT;}
"double"												{ hay_un_caracter_no_reconocido = FALSE; strcpy (yylval.s.sval, yytext); return DOUBLE;}
"signed"												{ hay_un_caracter_no_reconocido = FALSE; strcpy (yylval.s.sval, yytext); return SIGNED;}
"unsigned"												{ hay_un_caracter_no_reconocido = FALSE; strcpy (yylval.s.sval, yytext); return UNSIGNED;}

"if"													{ hay_un_caracter_no_reconocido = FALSE; yylval.s.linea_inicial = yylineno; return IF;}
"else"													{ hay_un_caracter_no_reconocido = FALSE; return ELSE;}
"switch"												{ hay_un_caracter_no_reconocido = FALSE; yylval.s.linea_inicial = yylineno; return SWITCH;}
"for"													{ hay_un_caracter_no_reconocido = FALSE; yylval.s.linea_inicial = yylineno; return FOR;}
"while"													{ hay_un_caracter_no_reconocido = FALSE; yylval.s.linea_inicial = yylineno; return WHILE;}
"do"													{ hay_un_caracter_no_reconocido = FALSE; yylval.s.linea_inicial = yylineno; return DO;}
"goto"													{ hay_un_caracter_no_reconocido = FALSE; return GOTO;}
"continue"												{ hay_un_caracter_no_reconocido = FALSE; return CONTINUE;}
"break"													{ hay_un_caracter_no_reconocido = FALSE; return BREAK;}
"return"												{ hay_un_caracter_no_reconocido = FALSE; yylval.s.linea_inicial = yylineno; return RETURN;}
{constante_de_enumeracion}								{ hay_un_caracter_no_reconocido = FALSE;
															strcpy (yylval.s.sval, yytext); return CONSTANTE_DE_ENUMERACION; }
{comentario_de_una_linea}								;
{comentario_multilineas}								;
{directiva_de_preprocesamiento}							;
{identificador}											{ hay_un_caracter_no_reconocido = FALSE; strcpy (yylval.s.id, yytext); return IDENTIFICADOR; }
{cadena_de_caracteres}				 					{ hay_un_caracter_no_reconocido = FALSE; 
															strcpy (yylval.s.sval, yytext);return CADENA_DE_CARACTERES; }
{constante_decimal}										{ hay_un_caracter_no_reconocido = FALSE; 
															yylval.s.ival = (int) strtol (yytext, NULL, 10); return CONSTANTE_DECIMAL; }
{constante_octal}										{ hay_un_caracter_no_reconocido = FALSE;
															yylval.s.ival = (int) strtol(yytext, NULL, 8); return CONSTANTE_OCTAL; }
{constante_hexadecimal}									{ hay_un_caracter_no_reconocido = FALSE;
															yylval.s.ival = (int) strtol(yytext, NULL, 16); return CONSTANTE_HEXADECIMAL; }
{constante_caracter}									{ hay_un_caracter_no_reconocido = FALSE; strcpy (yylval.s.sval, yytext); return CONSTANTE_CARACTER; }
{constante_real}										{ hay_un_caracter_no_reconocido = FALSE; 
															yylval.s.dval = strtod (yytext,NULL); return CONSTANTE_REAL; }
[ \t\n]													{ hay_un_caracter_no_reconocido = FALSE; }
.														{ strcpy (cadena_entero.cadena, yytext);
															cadena_entero.entero = yylineno;
															agregar_cadena_entero_al_final_con_repeticion_y_bandera (&no_reconocidas, cadena_entero, &hay_un_caracter_no_reconocido);
															hay_un_caracter_no_reconocido = TRUE; }

%%

int yyerror (char const *s)
{
	puts(s);
	return 1;
}
