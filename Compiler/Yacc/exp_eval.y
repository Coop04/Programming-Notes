%{ 
#include<stdio.h> 
#include<stdlib.h> 

int yyerror()
int yylex()
%} 
%token num 
%left '+' '-' 
%left '*' '/' '%' 
%left '(' ')' 
%% 
arexp:exp {printf("result= %d\n",$$);return 0 ;}; 
exp:exp'+'exp {$$=$1+$3;}| 
exp'-'exp {$$=$1-$3;}| 
exp'*'exp {$$=$1*$3;}| 
exp'/'exp {$$=$1/$3;}| 
'('exp')' {$$=$2;}| 
num {$$=$1;}; 
%% 
int main(){ 
printf("Enter: \n"); 
yyparse(); 
printf("valid \n"); 
} 
int yyerror(){ 
printf("invalid\n"); 
exit(0); 
}