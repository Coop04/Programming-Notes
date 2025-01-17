#include<stdio.h>
void main()
{
    int n,i,j=0,k=0,l,m,a[10],b[10],c[10];
    printf("Enter a limit");
    scanf("%d",&n);
    printf("The numbers are\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
    if(a[i]%2==0)
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
    }
    printf("The even numbers are\n");
    for(j=0;j<l;j++)//if there are 2 even numbers j is stored to l as 2.When j<l (1),so when itrating j has 2 values 0 ans 1
    printf("%d\n",b[j]);
    printf("The odd numbers are\n");
    for(k=0;k<m;k++)//if there are 3 odd numbers k is stored to m as 3.When j<m (2),so when itrating j has 3 values 0,1 and 2
    printf("%d\n",c[k]);
}