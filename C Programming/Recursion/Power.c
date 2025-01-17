#include<stdio.h>
void main()
{
    int pow(int x,int n);
    int x,n,p;
    printf("Enter x and n\n");
    scanf("%d%d",&x,&n);
    p=pow(x,n);
    printf("X^n = %d",p);
}
int pow(int x,int n)
{  
    if(n!=0)
    return x*pow(x,n-1);
    else 
    return 1;
}