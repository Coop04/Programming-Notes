#include<stdio.h>
void main() {
    float avg(int a[10],int n);
    int i,a[10],n;
    float av;
    printf("Enter the size\n");
    scanf("%d",&n);
    printf("The elements are \n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    av=avg(a,n);
    printf("Average is %f",av);
}
float avg(int b[],int k) { 
    int i,sum=0;
    int *p;
    p=b;
    float avgg;
    for(i=0;i<k;i++)
    sum+=p[i]; //sum+=*(p+i);
    avgg=(float)sum/k;
    return avgg;
}
