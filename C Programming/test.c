#include<stdio.h>
void main() {
    int n,i,j,flag=0,count=2;
    printf("Enter the limit: ");
    scanf("%d",&n);
    printf("2\n");
    for(i=2;i<=100;i++) {
        for(j=2;j<i;j++) {
           if(i%j==0) {
                flag=0;
                break;
           }
           else {
            flag++;
           }
        }
           if(flag!=0) {
                printf("%d\n",i);
                count++;
           }
        flag=0;
        if(count>n) {
            break;
        }
    }
}