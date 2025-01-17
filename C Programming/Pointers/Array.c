#include<stdio.h>
void main()
{
    int a[10],n,i,*p,sum=0;
    printf("Enter no. of elements");
    scanf("%d",&n);
    p=a;
    printf("The elements are\n");
    for(i=0;i<n;i++)
    scanf("%d",(p+i));
    printf("Elements are\n");
    for(i=0;i<n;i++)
    printf("%d\n",*(p+i));
    for(i=0;i<n;i++)
    sum+=*(p+i);
    printf("Sum is %d\n",sum);
    printf("Average is %d",(sum/n));
}
