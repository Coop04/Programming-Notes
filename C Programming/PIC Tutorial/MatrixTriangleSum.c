#include<stdio.h>
void main()
{
    int n,a[10][10],i,j,sum;
    printf("Enter order of a square matrix\n");
    scanf("%d",&n);
    printf("The elements are\n");
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    scanf("%d",&a[i][j]);   
    printf("Lower Triangle sum is\n");
    sum=0;
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    if(i>=j)
    sum+=a[i][j];
    printf("%d\n",sum);
    printf("Upper Triangle sum is\n");
    sum=0;
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    if(i<=j)
    sum+=a[i][j];
    printf("%d\n",sum);
    
}