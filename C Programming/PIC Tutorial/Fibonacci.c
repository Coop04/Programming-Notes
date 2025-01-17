#include<stdio.h>
void main()
{
    int a,num1=0,num2=1,i,sum;
    printf("Enter a limit");
    scanf("%d",&a);
    printf("%d\n",num1);
    printf("%d\n",num2);
    for(i=1;i<=a-2;i++)
    {
        sum=num1+num2;
        printf("%d\n",sum);
        num1=num2;
        num2=sum;
    }
}