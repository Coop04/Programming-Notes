%{
#include <stdio.h>
#include <stdlib.h> // Required for exit()
int w = 0, l = 0, ch = 0;
%}

%%
exit\n              { printf("lines = %d\nwords = %d\ncharacters = %d\n", l, w, ch); exit(0); }
\n                  { l++; ch++; }
[A-Za-z]+           { w++; ch += yyleng; }        /* pure words only */
[0-9]+              { ch += yyleng; }             /* numbers – just count characters */
[A-Za-z0-9]+        { ch += yyleng; }             /* mixed alphanumeric — don't count as word */
[ \t]+              { ch += yyleng; }             /* spaces and tabs */
[^A-Za-z0-9\n \t]+  { ch += yyleng; }             /* other symbols */
%%


int main() {
printf("Enter text. Type 'exit' on a new line to finish\n");
yylex();
return 0;
}
