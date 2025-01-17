#include<stdio.h>
void main()
{
    int n,a[5][5],i,j,transposed[5][5];
    printf("Enter the order\n");
    scanf("%d",&n);
    printf("The elements are\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
        scanf("%d",&a[i][j]);
        }
    }
    printf("The matrix is\n");
    for(i=0;i<n;i++)
    {
    for(j=0;j<n;j++)
    printf("%d ",a[i][j]);
    printf("\n");
    }
    printf("The transpose of the matrix is\n");
    for(i=0;i<n;i++)
    {
    for(j=0;j<n;j++)
    transposed[i][j]=a[j][i];
    }
    for(i=0;i<n;i++)
    {
    for(j=0;j<n;j++)
    printf("%d\t",transposed[i][j]);
    printf("\n");
    }
}