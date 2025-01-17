#include <stdio.h>
void main() {
    int i,j,k,q=1,m,n,a[5][5],b[10][3];
    printf("Enter the size of the matrix\n");
    scanf("%d%d",&m,&n);
    printf("The no. of non-zero elements are ");
    scanf("%d",&k);
    printf("The elements are\n");
    for(i=0;i<m;i++)
    for(j=0;j<n;j++)
    scanf("%d",&a[i][j]);
    b[0][0]=m;
    b[0][1]=n;
    b[0][2]=k;
    for(i=0;i<m;i++)
    for(j=0;j<n;j++) {
        if(a[i][j]!=0) {
            b[q][0]=i;
            b[q][1]=j;
            b[q][2]=a[i][j];
            q++;
        }      
    }
    printf("The triplet is\n");
    for(i=0;i<k+1;i++) {
        for(j=0;j<3;j++) {
            printf("%d\t",b[i][j]);
        }
        printf("\n");
    }
}