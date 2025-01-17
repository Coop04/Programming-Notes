#include<stdio.h>
void main() {
    int a[10],n,i,sum=0;
    float avg;
    printf("Enter the numbrer of elements\n");
    scanf("%d",&n);
    printf("The elements are\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    sum+=a[i];
    avg=sum/n;
    printf("Average is: %f",avg);
}
