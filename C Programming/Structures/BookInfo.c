#include<stdio.h>
struct book
{
    char name[10];
    int price;
}b[10];
void main()
{
    int n,i;
    printf("Enter the no. of books");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter name\n");
        scanf("%s",b[i].name);
        printf("Enter price\n");
        scanf("%d",&b[i].price);
    }
    printf("The details are\n");
    for(i=0;i<n;i++)
    {
        printf("Name  :%s\t",b[i].name);
        printf("Price :%d\t\n",b[i].price);
    }
}