#include <stdio.h>
int main()
{
    float a,b,quotient;

    printf("Enter two numbers to find their quotient ");
    scanf("%f %f",&a,&b);

    quotient=a/b;

    printf("Quotient is %f",quotient);
    return 0;
}