#include<stdio.h>
void transp(int a[][5],int x,int y) {
    int i,j,temp,transposed[5][5];
    for(i=0;i<x;i++)
    for(j=0;j<y;j++) {
        transposed[j][i]=a[i][j];
    }
    for(i=0;i<x;i++)
    for(j=0;j<y;j++)
    a[i][j]=transposed[i][j]; 
}
void main() {
    int p,q,b[5][5],i,j;
    printf("Enter the size \n");
    scanf("%d%d",&p,&q);
    printf("The elements are\n");
    for(i=0;i<p;i++)
    for(j=0;j<q;j++)
    scanf("%d",&b[i][j]);
    transp(b,p,q);
    printf("The transpose is\n");
    for(i=0;i<q;i++) {
        for(j=0;j<p;j++)
        printf("%d\t",b[i][j]);
        printf("\n");
    }

}