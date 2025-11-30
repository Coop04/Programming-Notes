%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
%}
%token number id
%left '+' '-'
%left '*' '/'
%%
exp:exp'+'exp|exp'-'exp|exp'*'exp|exp'/'exp|'('exp')'|id|number;
%%
int main(){
printf("Enter exp: \n");
yyparse();
printf("valid expression \n");
}
int yyerror(){
printf("invalid\n");
exit(0);
}
