%{
#include "parser.tab.h"
int yyerror (char const *s);

%}

constante_decimal											[1-9][0-9]*
identificador												[a-zA-Z_][a-zA-Z0-9_]*
asignacion_compuesta										"*="|"/="|"%="|"+="|"-="|"<<="|">>="|"\&="|"^="|"\|="

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
{identificador}											{ yylval.sval = strdup(yytext); return IDENTIFICADOR; }
{constante_decimal}										{ yylval.ival = atoi(yytext); return CONSTANTE_DECIMAL; }
[ \t\n]														{ ; } // Ignora espacios en blanco y tabuladores
.																{ yyerror("Carácter no válido"); }

%%

int yyerror (char const *s)
{
	puts(s);
	return 1;
}
