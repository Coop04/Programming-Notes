//Amstrong check for no.s between 100 & 1000
#include<stdio.h>
#include<math.h>
void main()
{
    int a,rem,org,p=0,sum=0;
    printf("Enter a number");
    scanf("%d",&a);
    org=a;
    while(a!=0)
    {
        rem=a%10;
        p++;
        a=a/10;
    }
    a=org;
    while(a!=0)
    {
        rem=a%10;
        sum=sum+pow(rem,p);
        a=a/10;
    }
    
    if(org<100||org>1000)
    {printf("invalid");}
    else if(sum==org)
    {printf("Amstrong no.");}
    else
    {printf("Not amstrong no.");}
    
}