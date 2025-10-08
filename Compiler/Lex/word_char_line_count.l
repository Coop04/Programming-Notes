%{
#include <stdio.h>
#include <stdlib.h>
int w=0,c=0,l=0;
%}

%option noyywrap

%%
[a-zA-Z]+ {w++;c+=yyleng;}
"\n" {l++;}
".\n" {printf("Word: %d, Char: %d, Line: %d",w,c,l);exit(0);}
. {}
%%

int main() {
    printf("Enter a sentence: ");
    yylex();
    return 0;
}