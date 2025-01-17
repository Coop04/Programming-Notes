#include<stdio.h>
void main()
{
    int a[5][5],m,n,i,j,sum;
    printf("Enter order\n");
    scanf("%d%d",&m,&n);
    printf("Elements are\n");
    for(i=0;i<m;i++)
    for(j=0;j<n;j++)
    scanf("%d",&a[i][j]);
    printf("Raw sums are\n");
    for(i=0;i<m;i++)
    {
    sum=0;
    for(j=0;j<n;j++)
    sum+=a[i][j];
    printf("%d\n",sum);
    }
    printf("Column sums are\n");
    for(j=0;j<n;j++)
    {
    sum=0;
    for(i=0;i<m;i++)
    sum+=a[i][j];
    printf("%d\n",sum);
    }

}