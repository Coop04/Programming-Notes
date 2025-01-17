#include <stdio.h>
void update(int*a,int*b) { 
    int temp;
    temp=*a;
    *a=(*a+*b);
    *b=(temp-*b);
    if(*b<0)
    *b=-(*b);
    /*In this case, the update function modifies the
    values of *a and *b through the pointers a and b
    that were passed by reference. Since these pointers 
    point to the same memory locations as the variables a 
    and b in the main function, any changes made to
    *a and *b within the update function will affect
    the values of a and b in the main function.*/
}

int main() {
    int a=4,b=5;
    int *pa = &a, *pb = &b;
    scanf("%d%d",&a,&b);
    update(pa,pb);
    printf("%d\n%d",a,b);
    return 0;
}