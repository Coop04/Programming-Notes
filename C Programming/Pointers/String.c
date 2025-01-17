#include<stdio.h>
void main()
{
    char a[10],*p;
    p=a;
    printf("Enter a word\n");
    gets(a);
    printf("%s",p);
}