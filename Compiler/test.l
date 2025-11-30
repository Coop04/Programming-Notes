%{
#include"test.tab.h"
#include<stdio.h>
extern int yylval;
%}

%option noyywrap

%%
[0-9]+ {yylval = atoi(yytext);return num;}
\n {return 0;}
. {return yytext[0];}
%%