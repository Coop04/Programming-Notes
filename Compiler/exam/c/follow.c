#include<stdio.h>
#include<string.h>
#include<ctype.h>
char p[10][10],f[10];
int n=0,nf=0;int j,k;
void fir(char c);
void fol(char c);
void fir(char c){
if(!isupper(c))
f[n++]=c;
for(int i=0;i<nf;i++){
if(p[i][0]==c){
if(p[i][2]=='$')
{if(p[j][k+1]=='\0' && p[j][0]!=c)
fol(p[j][0]);
else if(p[j][k+1]==c && p[j][k+2]!='\0')
fir(p[j][k+2]);
}
else if(islower(p[i][2]))
f[n++]=p[i][2];
else
fir(p[i][2]);
}
}
}
void fol(char c){
if(p[0][0]==c)
f[n++]='$';
for(j=0;j<nf;j++){
for( k=2;k<strlen(p[j]);k++){
if(p[j][k]==c){
if(p[j][k+1]=='\0')
fol(p[j][0]);
else
fir(p[j][k+1]);
}
}
}
}
void main(){
char c;
char ch;
printf("Enter no of productions:\n");
scanf("%d",&nf);
printf("Enter productions (epsilon=$)\n");
for(int i=0;i<nf;i++)
scanf("%s%c",p[i],&ch);
int choice=0;
printf("Enter char :\n");
scanf("%c",&c);
do{
n=0;
fol(c);
printf("follow(%c)={",c);
for(int i=0;i<n;i++)
{
if(i!=n-1)
printf("%c, ",f[i]);
else
printf("%c }",f[i]);
}
printf("do you want to continue(press 1) and enter next char\n");
scanf("%d%c",&choice,&c);
}while(choice==1);
}
