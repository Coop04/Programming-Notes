%{ 
#include"arithmetic_exp_check.tab.h" 
%} 

%option noyywrap

%% 
[0-9]+ {return number;} 
[A-Za-z][A-Za-z0-9]* {return id;} 
\n {return 0;} 
. {return yytext[0];} 
%% 