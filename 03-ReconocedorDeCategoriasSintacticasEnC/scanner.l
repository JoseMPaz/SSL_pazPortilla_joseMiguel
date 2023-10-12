%{
#include "parser.tab.h"
int yyerror (char *s);

%}
constante_decimal					[1-9][0-9]*
tipo_de_dato 						"void"|"char"|"short"|"int"|"long"|"float"|"double"|"signed"|"unsigned"
especificador_de_categoria_de_almacenamiento	"auto"|"register"|"static"|"extern"|"typedef"
identificador						[a-zA-Z_][a-zA-Z0-9_]*
asignacion	["="]|"*="|"/="|"%="|"+="|"-="|"<<="|">>="|"\&="|"^="|"\|="


%option noyywrap

%%
","										{return ',';}
{tipo_de_dato}							{ return TIPO_DE_DATO; }
{especificador_de_categoria_de_almacenamiento}		{ return ESPECIFICADOR_DE_CATEGORIA_DE_ALMACENAMIENTO; }
";"										{ return ';'; }
"("										{ return '('; }
")"										{ return ')'; }
"{"										{ return '{'; }
"}"										{ return '}'; }
"\?"										{ return '?'; }
":"										{ return ':'; }
"\|\|"									{return OPERADOR_LOGICO_O;}
"\&\&"									{return OPERADOR_LOGICO_Y;}
"\|"										{return '|';}
"^"										{return '^';}
"\&"										{return '&';}
"=="										{return OPERADOR_IGUALDAD;}
"!="										{return OPERADOR_DISTINTO;}
"<"										{return '<';}
">"										{return '>';}
"<="										{return MENOR_O_IGUAL;}
">="										{return MAYOR_O_IGUAL;}
"<<"										{return DESPLAZAMIENTO_A_IZQUIERDA;}
">>"										{return DESPLAZAMIENTO_A_DERECHA;}
"+"										{return '+';}
"-"										{return '-';}
"*"										{return '*';}
"/"										{return '/';}
"%"										{return '%';}
"++"										{return INCREMENTO;}
"--"										{return DECREMENTO;}
"sizeof"									{return SIZEOF;}
"~"										{return '~';}
"!"										{return '!';} 
"\["										{return '[';}
"\]"										{return ']';}
"."										{return '.';}
"->"										{return APUNTA;}	
{asignacion}							{ return ASIGNACION; }
{identificador}						{ yylval.sval = strdup(yytext); return IDENTIFICADOR; }
{constante_decimal}					{ yylval.ival = atoi(yytext); return CONSTANTE_DECIMAL; }
[ \t\n]									; // Ignora espacios en blanco y tabuladores
.											{ yyerror("Carácter no válido"); }

%%

int yyerror (char *s)
{
	puts(s);
	return 1;
}
