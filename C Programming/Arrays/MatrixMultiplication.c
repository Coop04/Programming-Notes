#include<stdio.h>
void main()
{
    int m,n,y,z,a[5][5],b[5][5],c[5][5],i,j,k;
    printf("Enter the order of M1 \n");
    scanf("%d%d",&m,&n);
    printf("Enter the order of M2 \n");
    scanf("%d%d",&y,&z);
    if(n==y)
    {
        printf("The elements of M1 are\n");
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
            scanf("%d",&a[i][j]);
            }
        }
        printf("The elements of M2 are\n");
        for(i=0;i<y;i++)
        {
            for(j=0;j<z;j++)
            {
            scanf("%d",&b[i][j]);
            }
        }
        for(i=0;i<m;i++)
            {
                for(j=0;j<z;j++)
                {
                    c[i][j]=0;
                    for(k=0;k<y;k++)
                    {
                       c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
                    }
                }
            }
        printf("The product is\n");
        for(i=0;i<m;i++)
        {
            for(j=0;j<z;j++)
            {
                printf("%d\t",c[i][j]);
            }
        printf("\n");
        }
    }
    else
    printf("Matrix multiplication is not possible");
}