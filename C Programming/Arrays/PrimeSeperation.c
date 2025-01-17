#include<stdio.h>
void main()
{
    int n,i,d,j=0,k=0,factor=0,l=0,m=0,a[10],b[10],c[10];
    printf("Enter a limit");
    scanf("%d",&n);
    printf("The numbers are\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);

    for(i=0;i<n;i++)
    {
        for(d=1;d<=(a[i]/2);d++)
        {
            if(a[i]%d==0)
            factor++;
        }
    
    
        if(factor==1)
        {
            b[j]=a[i];
            j++;
            l=j;
        }
        else
        {
            c[k]=a[i];
            k++;
            m=k;
        }
        factor=0;
    }
    printf("Prime numbers are\n");
    for(j=0;j<l;j++)
    printf("%d ",b[j]);
    printf("\nOthers are\n");
    for(k=0;k<m;k++)
    printf("%d ",c[k]);
}
