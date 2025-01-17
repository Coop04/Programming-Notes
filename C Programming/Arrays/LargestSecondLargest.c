#include<stdio.h>//Bubble Sort
void main()
{
int n,a[10],i,j,temp;
printf("Enter the size of the array\n");
scanf("%d",&n);
printf("The numbers are\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);

for(i=0;i<n-1;i++)
{
    for(j=0;j<n-i-1;j++)
    {
        if(a[j]>a[j+1])
        {
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
    }
}
printf("The largest number is %d\n",a[n-1]);
printf("The second largest number is %d",a[n-2]);
}