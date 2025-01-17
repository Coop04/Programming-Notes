#include<stdio.h>
void main()
{
    int fact(int a);
    int a,c;
    printf("Enter a number\n");
    scanf("%d",&a);
    c=fact(a);
    printf("Factorial is %d\n",c);
}
int fact(int a)
{
    if(a<=1)
    return 1;
    else
    return a*fact(a-1);
}