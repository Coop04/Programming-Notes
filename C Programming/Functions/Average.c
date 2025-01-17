#include<stdio.h>
float avg(int a[],int n) {
    int sum=0,i;
    float av;
    for(i=0;i<n;i++)
    sum+=a[i];
    av=(float)sum/n;
    return av;
}
void main() {
    int b[10],i,k;
    float avgg;
    printf("Enter size");
    scanf("%d",&k);
    printf("The elements are\n");
    for(i=0;i<k;i++)
    scanf("%d",&b[i]);
    avgg=avg(b,k);
    printf("The average is %f",avgg);
    
}