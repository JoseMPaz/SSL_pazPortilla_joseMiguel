%{
#include "parser.tab.h"//para yylval
#include <stdlib.h>//Para atoi()
%}
/*Captura los lexemas indicados por las ER's y los envia al parser, en el caso de los decimales tambien envian su valor en yylval que por
defecto es un entero*/
%%

[0-9]+  {yylval = atoi(yytext); return NUMERO;}
"+"     {return '+';}
"-"     {return '-';}
"*"     {return '*';}
"/"     {return '/';}
"^"     {return '^';}
"\n"    {return '\n';}

%%
