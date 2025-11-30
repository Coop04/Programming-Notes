%{
#include <stdio.h>
%}

%%
if|else|while|for|switch|break|continue|do|int|main|char|float { printf("%s is a keyword\n", yytext); }
"||"|"&&"|"!" 						  { printf("%s is a logical operator\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]* 			      { printf("%s is an identifier\n", yytext); }
[0-9]+ 							      { printf("%s is a number\n", yytext); }
[0-9]+"."[0-9]+ 					  { printf("%s is a number\n", yytext); }
"<"|">"|"<="|">="|"=="|"!=" 	      { printf("%s is a relational operator\n", yytext); }
"+"|"-"|"*"|"/"|"%" 			      { printf("%s is an arithmetic operator\n", yytext); }
"=" 							      { printf("%s is an assignment operator\n", yytext); }
"++" 							      { printf("%s is an increment operator\n", yytext); }
"--" 							      { printf("%s is a decrement operator\n", yytext); }
[;,\(\)\{\}'] 						  { printf("%s is a special symbol\n", yytext); }
[ \t\n]+ 						      { }
. 							          { printf("Unrecognized character: %s\n", yytext); }
%%
int main() {
yyin = fopen("input.txt", "r");
yylex();
return 0;
}
