#include<stdio.h>
void main()
{
    int fact(int a);
    int a,c;
    printf("Enter a number");
    scanf("%d",&a);
    c=fact(a);
    printf("Factorial is %d",c);
}
int fact(int a)
{
    int i,fact=1;
    for(i=1;i<=a;i++)
    fact*=i;
    return fact;
}