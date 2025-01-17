#include<stdio.h>
#include<string.h>
void main()
{
    char a[10];
    printf("Enter a word\n");
    gets(a);
    printf(strrev(a));
}