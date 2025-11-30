%{
#include <stdio.h>  
int v=0,c=0;  
%}

%option noyywrap

%%
[aeiouAEIOU] {v++;}
[b-dB-Df-hF-Hj-nJ-Np-tP-Tv-zV-Z] {c++;}
\n {printf("Vowels: %d, Consonents: %d",v,c);exit(0);}
. {}
%%

int main() {
    printf("Enter a sentence: ");
    yylex();
    return 0;
}