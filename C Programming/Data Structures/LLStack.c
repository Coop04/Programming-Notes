#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *link;
}stack;
stack *head=NULL;
void push(int item) { //insertion at beginning
    stack *newnode;
    newnode=(stack*)malloc(sizeof(stack));
    newnode->data=item;
    newnode->link=NULL;
    if(head==NULL) {
        head=newnode;
    }
    else {
        newnode->link=head;
        head=newnode;
    }
}
void pop() { //deletion at beginning
    stack *temp;
    if(head==NULL) {
        printf("\nStack Underflow");
    }
    else {
        temp=head;
        head=head->link;
        printf("\nDeleted element is :%d",temp->data);
        free(temp);
    }
}
void display() {
    stack *temp;
    temp=head;
    while(temp!=NULL) {
        printf("%d\t",temp->data);
        temp=temp->link;
    }
}
void main() {
    int item,choice;
    while(1) {
    printf("\nEnter your choice\n1.Push\n2.Pop\n3.Display\n4.Exit :");
    scanf("%d",&choice);
    switch(choice) {
        case 1: printf("\nEnter the item to be added :");
                scanf("%d",&item);
                push(item);
                printf("\nItem Added");
                break;
        case 2: pop();
                break;
        case 3: display();
                break;
        case 4: exit(0);
    }
    }
}