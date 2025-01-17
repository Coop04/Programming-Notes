#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int stack[MAX];
int top=-1;
void push(int t) {
    if(top==MAX-1) {
        printf("Stack is full\n");
    }
    else {
        top++;
        stack[top]=t;
    }
}
void pop(int t) {
    if(top==-1) {
        printf("Stack Underflow");
    }
    else {
        printf("Popped item is %d\n",stack[top]);
        top--;
    }
}
void display() {
    if( top==-1) {
        printf("Stack is empty");
    }
    else {
        int i;
        for(i=0;i<=top;i++)
        printf("%d\n",stack[i]);
    }
}
void main() {
    int item,opr;
    while(1){
        printf("Enter your choice\n1.push\n2.pop\n3.display\n4.exit\n");
    scanf("%d",&opr);
    switch(opr) {
        case 1:
        printf("Enter the value to be pushed");
        scanf("%d",&item);
        push(item);
        break;
        case 2:
        pop(item);
        break;
        case 3:
        printf("Stack is\n");
        display();
        break;
        case 4:
        printf("Finished");
        exit(0);
        break;
        default:
        printf("Invalid choice");
    }
    }
}