%{
#include <stdio.h>    
%}

%option noyywrap

%%
[1-9][0-9]{9} {printf("Valid");}
.+ {printf("Invalid");}
"exit\n" {exit(0);}
%%

int main() {
    printf("Enter phone number: ");
    yylex();
    return 0;
}