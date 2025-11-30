%{
#include <stdio.h>
%}

%%
abc { printf("ABC"); }
%%

int main() {
printf("Enter text:\n");
yylex();
return 0;
}
