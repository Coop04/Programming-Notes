%{
#include <stdio.h>
#include <stdlib.h>
int v = 0;
int c = 0;
%}
%%
[aAeEiIoOuU] { v++; }
[b-df-hj-np-tv-zB-DF-HJ-NP-TV-Z] { c++; }
\n { printf("No. of vowels = %d and no. of consonants = %d\n", v, c); exit(0); }
. {}
%%
int main() {
printf("Enter a string and press Enter: ");
yylex();
return 0;
}
