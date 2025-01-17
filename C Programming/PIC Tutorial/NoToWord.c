#include<stdio.h>
void main() {
    int a,rem,w[9],i=0,k,flag=0;
    printf("Enter a number");
    scanf("%d",&a);
    while(a!=0) {
        rem=a%10;
        flag++;
        w[i]=rem;
        i++;
        a=a/10;
    }
    for(i=0;i<flag;i++)
    printf("%d\n",w[i]);
    
    for(i=flag-1;i>=0;i--) {
        k=w[i];
        switch(k) {
        case 1:printf("One ");break;
        case 2:printf("Two ");break;
        case 3:printf("Three ");break;
        case 4:printf("Four ");break;
        case 5:printf("Five ");break;
        case 6:printf("Six ");break;
        case 7:printf("Seven ");break;
        case 8:printf("Eight ");break;
        case 9:printf("Nine ");break;
        }
    }
}