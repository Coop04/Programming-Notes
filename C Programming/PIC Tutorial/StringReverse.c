#include<stdio.h>
void main()
{
    char a[10],b[10];
    int i,j,l=0;
    printf("Enter a word\n");
    gets(a);
    for(i=0;a[i]!='\0';i++)
    l++;
    for(i=l-1,j=0;b[j]!='\0';i--,j++)
    b[j]=a[i];
    b[j]='\0';
    printf("Reverse is\n");
    puts(b);
}