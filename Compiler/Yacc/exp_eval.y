%{ 
#include<stdio.h> 
#include<stdlib.h> 
int f=0; 
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
if(f==0) 
printf("valid \n"); 
} 
int yyerror(){ 
printf("invalid\n"); 
f=1; 
exit(0); 
}