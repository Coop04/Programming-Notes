#include<stdio.h>
int median(int a[],int b[],int m,int n) {
    int temp,len,i,j;
    float m1,m2;
    len=n+m;
    for(i=m,j=0;i<len;i++,j++)
    a[i]=b[j];
    printf("The Elements are\n");
    for(i=0;i<len-1;i++)
    for(j=0;j<len-i-1;j++) {
        if(a[j]>a[j+1]) {
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
    }
    for(i=0;i<len;i++)
    printf("%d\n",a[i]);
    m1=(float)(a[len/2]+a[(len/2)-1])/2;
    m2=(float)a[(len/2)];
    if(len%2==0) {
        printf("Median is %f",m1);
    }
    else {
        printf("The median is %f",m2);
    }
} 
void main() {
    int p[20],q[10],i,x,y;
    printf("Enter size of A1 ");
    scanf("%d",&x);
    for(i=0;i<x;i++)
    scanf("%d",&p[i]);
    printf("Enter size of A2 ");
    scanf("%d",&y);
    for(i=0;i<y;i++)
    scanf("%d",&q[i]);
    median(p,q,x,y);
}