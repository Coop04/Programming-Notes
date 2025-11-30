%{
#include"y.tab.h"
%}
%%
[A-Za-z_][_A-Za-z0-9]* {return id;}
\n {return 0;}
. {return yytext[0];}
%%
