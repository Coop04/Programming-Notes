%{
#include <stdio.h>    
%}

%option noyywrap

%%
"abc" {printf("ABC");}
"exit\n" {exit(0);}
%%

int main() {
    yylex();
    return 0;
}