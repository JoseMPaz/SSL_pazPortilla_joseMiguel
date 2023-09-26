%{
#include "parser.tab.h"
%}
/*Captura los lexemas indicados por las ER's y los envia al parser, en el caso de los decimales tambien envian su valor en yylval*/
%%

[0-9]+  {yylval = atoi(yytext); return NUM;}
"+"     {return '+';}
"-"     {return '-';}
"*"     {return '*';}
"/"     {return '/';}
"^"     {return '^';}
"\n"    {return '\n';}

%%
