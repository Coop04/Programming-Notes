%{
#include <stdio.h>
#include <string.h>  
int word=0;  
%}

%option noyywrap

%%
[a-zA-Z0-9]+ {word++;}
"\n" {printf("Word Count: %d\n",word);}
"exit\n" {exit(0);}
[^a-zA-Z0-9\n]+ {}
%%

int main() {
    printf("Enter a sentence: ");
    yylex();
    return 0;
}