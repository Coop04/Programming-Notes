%{
#include <stdio.h>    
%}

%option noyywrap

%%
[1-9][0-9]{9} {printf("Valid");}
.+ {printf("Invalid");} // . matches any character except a newline
                        // if . is given instead of .+ it will print 'Invalid' for every character entered, ie, if abc was given it prints Invalid 3 times 
                        // .+ matches one or more characters other than '\n'
"exit\n" {exit(0);}
%%

int main() {
    printf("Enter phone number: ");
    yylex();
    return 0;
}