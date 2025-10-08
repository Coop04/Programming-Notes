%{
#include<stdlib.h>
#include<stdio.h>
%}

%option noyywrap

%%
"if"|"else"|"for"|"while"|"int"|"float"|"char"|"double"|"short"|"long"|"unsigned"|"signed"|"switch"|"return" {printf("Keyword");}
[_]*[A-Za-z]+[A-Za-z0-9_]* {printf(" Identifier ");}
.+ {printf("Invalid");}
"exit\n" {exit(0);}
%%

int main(){
yylex();
return 0;
}