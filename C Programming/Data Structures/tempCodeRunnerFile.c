#include<stdio.h>
#include <math.h>
#define SIZE 20
char st[SIZE];
char s[SIZE];
int top=-1;
char express[30];
char postfixx[30];
int operand(char n) {
    if(n>='0'&&n<='9') 
        return 1;
    else
        return 0;
}
int ISP(char n) {
    switch(n) {
        case '(':return 0;break;
        case '^':return 3;break;
        case '*':
        case '/':return 2;break;
        case '+':
        case '-':return 1;break;
        default :return -1;break;
    }
}
int ICP(char n) {
    switch(n) {
        case '(':return 4;break;
        case '^':return 4;break;
        case '*':
        case '/':return 2;break;
        case '+':
        case '-':return 1;break;
        default :return -1;break;
    }
}
void postfix() {
    int i=0,k=0;
    char x=express[i];
    while(x!='#') {
        if(operand(x)) {
            postfixx[k]=x;
            k++;
        }
        else if(x==')') {
            while(st[top]!='(') {
                postfixx[k]=st[top];
                top--;
                k++;
            }
            top--;
        }
        else {
            while(ISP(st[top])>=ICP(x)) {
                postfixx[k]=st[top];
                top--;
                k++;
            }
            top++;
            st[top]=x;
        }
        i++;
        x=express[i];
    }
    while(top>=0) {
        postfixx[k]=st[top];
        top--;
        k++;
    }
    postfixx[k]='#';
}
int posteval(char e[]) {
    char x;
    int i=0;
    x=e[i];
    while(x!='#') {
        if(operand(x)) {
            s[++top]=x-'0';//convert character digit to integer value.eg: '0' - '0' = 0, '1' - '0' = 1, '2' - '0' = 2
        }
        else {
            int p=s[top];
            top--;
            int q=s[top];
            top--;
            int r;
            switch(x) {
                case '+':r=q+p;break;
                case '-':r=q-p;break;
                case '*':r=q*p;break;
                case '/':r=q/p;break;
                case '^':r=pow(q,p);break;
                default :break;
            }
            s[++top]=r;
        }
        x=e[++i];
    }
    printf("\nThe result : %d\n",s[top]);
}
void main() {
    printf("Enter the expression with # as an end marker :");
    scanf("%s",express);
    printf("The infix expression is :%s",express);
    postfix();
    printf("\nThe postfix expressoin is :%s",postfixx);
    posteval(postfixx);
}