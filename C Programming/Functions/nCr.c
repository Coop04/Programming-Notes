#include<stdio.h>
void main()
{
    int fact(int a);
    int a,n,r,c;
    printf("Enter n and r\n");
    scanf("%d%d",&n,&r);
    c=fact(n)/(fact(r)*fact(n-r));
    printf("nCr is %d",c);
}
int fact(int a)
{
    int i,fact=1;
    for(i=1;i<=a;i++)
    fact*=i;
    return fact;
}