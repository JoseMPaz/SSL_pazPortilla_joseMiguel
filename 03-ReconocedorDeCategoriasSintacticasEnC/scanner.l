%{
#include "parser.tab.h"
int yyerror (char *s);

%}



%option noyywrap

%%
","						{return ',';}
"+"                 { return '+'; }
"-"                 { return '-'; }
"*"                 { return '*'; }
"/"                 { return '/'; }
"int"               { return INT; }
";"                 { return PUNTO_Y_COMA; }
"("                 { return ABRE_PARENTESIS; }
")"                 { return CIERRA_PARENTESIS; }
"{"                 { return ABRE_LLAVE; }
"}"                 { return CIERRA_LLAVE; }
"="                 { return ASIGNACION; }
[a-zA-Z_][a-zA-Z0-9_]*   { yylval.sval = strdup(yytext); return IDENTIFICADOR; }
[0-9]+              { yylval.ival = atoi(yytext); return NUMBER; }
[ \t\n]             ; // Ignora espacios en blanco y tabuladores
.                   { yyerror("Carácter no válido"); }

%%

int yyerror (char *s)
{
	puts(s);
	return 1;
}
