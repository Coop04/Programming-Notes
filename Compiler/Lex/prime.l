%{
#include<stdlib.h>
int f,k,i;
%}

%%
[0-9]+ {
k=atoi(yytext);
if(k>=0){
f=0;
for(i=2;i<k;i++)
if(k%i==0)
{
f=1;
break;
}
if(f==0)
printf("%d is prime\n",k);
else
printf("%d is not prime\n",k);
}
else
printf("invalid\n");
}
%%

int main(){
yylex();
return 0;
}
