#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct expr {
    char op[2], op1[5], op2[5], res[2]; // they are not stored as char arrays (and not just char) because there can be variables like 't1', 'temp', etc.
    int flag;
} arr[10];

void input();
void change(int p, char res[]);
void output();
void constant();

int n;

void main() {
    input();
    constant();
    output();
}

void input() {
    int i;
    printf("Enter the no. of expressions: ");
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        printf("Enter the expression\n");
        scanf("%s",arr[i].op);
        scanf("%s",arr[i].op1);
        scanf("%s",arr[i].op2);
        scanf("%s",arr[i].res);
        arr[i].flag=0; // not constant folded
    }
}

void constant() {
    int i, op1, op2, res;
    char op, resu[5];

    for(i=0;i<n;i++) {
        if((isdigit(arr[i].op1[0]) && isdigit(arr[i].op2[0])) ||
           (strcmp(arr[i].op,"=")==0 && isdigit(arr[i].op1[0]))) {
                op1 = atoi(arr[i].op1);
                op2 = atoi(arr[i].op2);
                op = arr[i].op[0];

                switch(op) {
                    case '+': res = op1 + op2; break;
                    case '-': res = op1 - op2; break;
                    case '*': res = op1 * op2; break;
                    case '/': res = op1 / op2; break;
                    case '=': res = op1; break;
                }
                sprintf(resu, "%d", res);  
                // sprintf stores the value (res) to a string (res1). %d is the type of input
                // done because the in change() we use str operations like strcmp() and strcpy()

                arr[i].flag = 1; // marked as constant folded
                change(i, resu);
        }
    }
}

void change(int p, char res[]) { // to replace constant folded variables in the next expressions with the constant values
    int i;

    for(i=p+1;i<n;i++) {
        if(strcmp(arr[i].op1,arr[p].res)==0) 
            strcpy(arr[i].op1,res);
        else if(strcmp(arr[i].op2,arr[p].res)==0) 
            strcpy(arr[i].op2,res);
    }
}

void output() {
    int i = 0;
    printf("Optimized code..\n");
    for(i=0;i<n;i++) {
        if(arr[i].flag==0) { // prints those expressions which cannot be constant folded
            printf("\n%s %s %s %s",arr[i].op,arr[i].op1,arr[i].op2,arr[i].res);
        }
    }
}

// Enter max no of exp:3
// Enter input:
// + 2 3 t1
// * t1 x t2
// + t2 5 t3

// optimised code is

// * 5 x t2
// + t2 5 t3
