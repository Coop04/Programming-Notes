#include<stdio.h>
void main()
{
    int sum(int a,int b);
    int a,b,c;
    printf("Enter 2 numbers\n");
    scanf("%d%d",&a,&b);
    c=sum(a,b);
    printf("Sum is %d",c);
}
int sum(int a,int b)
{
    int z;
    z=a+b;
    return z;
}