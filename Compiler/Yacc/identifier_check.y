%{ 
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
%} 
%token id 
%% 
exp: id; 
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