#include<stdio.h>
void swap(int *a,int *b) {
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void main() {
    int a,b;
    int *pa=&a,*pb=&b;
    printf("Enter the numbers to be swapped\n");
    scanf("%d%d",&a,&b);
    swap(pa,pb); //Here we swap the location (of the pointers) and in the def. we swap its pointer
    printf("The numbers after swapping are\n");
    printf("%d\n%d",a,b);
}