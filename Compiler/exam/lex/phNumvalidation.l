%{
#include <stdio.h>
%}


%%
[1-9][0-9]{9} { printf("%s is valid\n", yytext); }
[0-9]+ { printf("%s is invalid\n", yytext); }
\n {}
. { printf("%s is not a valid number sequence\n", yytext); }
%%

int main() {
printf("Enter numbers to validate :\n");
yylex();
return 0;
}
