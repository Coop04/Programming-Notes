#include<stdio.h>
typedef struct poly {
    int coeff;
    int exp;
}Poly;
int readPoly(Poly p[10],int t) {
    for(int i=0;i<t;i++) {
        printf("Enter the coefficeents and exponents in the decreasing order of exp.\n");
        printf("Enter coefficient(%d) :",i+1);
        scanf("%d",&p[i].coeff);
        printf("Enter the exponent(%d) :",i+1);
        scanf("%d",&p[i].exp);
    }
}
void displayPoly(Poly p[10],int t) {
    for(int i=0;i<t-1;i++) {
        printf("%dX^%d + ",p[i].coeff,p[i].exp);
    }
    printf("%dX^%d",p[t-1].coeff,p[t-1].exp);
}
void addPoly(Poly p1[10],Poly p2[10],Poly p3[10],int t1,int t2) {
    int i=0,j=0,k=0;
    while(i<t1 && j<t2) {
        if(p1[i].exp==p2[j].exp) {
            p3[k].coeff=p1[i].coeff + p2[j].coeff;
            p3[k].exp=p1[i].exp;
            k++;i++;j++;
        }
        else if(p1[i].exp>p2[j].exp) {
            p3[k].coeff=p1[i].coeff;
            p3[k].exp=p1[i].exp;
            k++;i++;
        }
        else {
            p3[k].coeff=p2[j].coeff;
            p3[k].exp=p2[j].exp;
            k++;j++;
        }
    }
    while(i<t1) {
        p3[k].coeff=p1[i].coeff;
        p3[k].exp=p1[i].exp;
        k++;i++;
    }
    while(j<t2) {
        p3[k].coeff=p2[j].coeff;
        p3[k].exp=p2[j].exp;
        k++;j++;
    }
}
void main() {
    Poly p1[10],p2[10],p3[10];
    int t1,t2;
    printf("Enter the no. of elements of polynomial 1\n");
    scanf("%d",&t1);
    readPoly(p1,t1);
    displayPoly(p1,t1);

    printf("\nEnter the no. of elements in polynomial 2\n");
    scanf("%d",&t2);
    readPoly(p2,t2);
    displayPoly(p2,t2);

    printf("\nThe resultant polynomial is : ");
    addPoly(p1,p2,p3,t1,t2);
    displayPoly(p3,t1+t2);
}