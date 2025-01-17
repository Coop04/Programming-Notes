#include<stdio.h>
#include<stdlib.h>
typedef struct nodeType {
    int data;
    struct nodeType*link;
}Node;
Node *tail=NULL;
int nodeCount() {
    Node *temp,*head;
    int ctr=1;
    head=tail->link;
    temp=tail->link->link;
    while(temp!=head) {
        ctr++;
        temp=temp->link;
    }
    printf("No. of nodes are : %d",ctr);
    return ctr;
}
void insertFront(int k) {
    Node *newnode;
    newnode=(Node*)malloc(sizeof(Node));
    newnode->data=k;
    newnode->link=NULL;
    if(tail==NULL) {
        tail=newnode;
        tail->link=newnode;
    }
    else {
        newnode->link=tail->link;
        tail->link=newnode;
    }
}
void insertLast(int k) {
    Node *newnode;
    newnode=(Node*)malloc(sizeof(Node));
    newnode->data=k;
    newnode->link=NULL;
    if(tail==NULL) {
        tail=newnode;
        tail->link=newnode;
    }
    else {
        newnode->link=tail->link;
        tail->link=newnode;
        tail=newnode;
    }
}
void insertAtPos(int k,int pos) {
    Node *newnode,*temp,*prev;
    int count,ctr=0;
    newnode=(Node*)malloc(sizeof(Node));
    newnode->data=k;
    newnode->link=NULL;
    count=nodeCount();
    if(pos<0||pos>count) {
        printf("Invalid Position\n");
    }
    else {
        temp=tail->link;
        while(ctr<pos-1) {
            prev=temp;
            temp=temp->link;
            ctr++;
        }
        prev->link=newnode;
        newnode->link=temp;
    }
}
void deleteFront() {
    Node *temp;
    if(tail==NULL) {
        printf("List is empty");
    }
    else if(tail->link==tail) {
        temp=tail;
        free(temp);
        tail=NULL;
    }
    else {
        temp=tail->link;
        tail->link=temp->link;
        printf("The deleted element is %d",temp->data);
        free(temp);
    }
}
void deleteLast() {
    Node *temp,*dlt;
    if(tail==NULL) {
        printf("List is empty");
    }
    else if(tail->link==tail) {
        temp=tail;
        free(temp);
        tail=NULL;
    }
    else {
        temp=tail->link;
        while(temp->link!=tail) {
            temp=temp->link;
        }
        dlt=tail;
        temp->link=tail->link;
        tail=temp;
        printf("The deleted element is %d",dlt->data);
        free(dlt);
    }
}
void deleteAtPos(int pos) {
    Node *temp,*prev;
    int count,ctr=0;
    count=nodeCount();
    if(pos<0||pos>count) {
        printf("Invalid Position");
    }
    else {
        temp=tail->link;
        while(ctr<pos-1) {
            prev=temp;
            temp=temp->link;
            ctr++;
        }
        prev->link=temp->link;
        printf("\nThe deleted element is %d",temp->data);
        free(temp);
    }
}
void display() {
    Node *temp;
    temp=tail->link;
    while(temp!=tail) {
        printf("%d\t",temp->data);
        temp=temp->link;
    }
    printf("%d",temp->data);
}
void main() {
    int item,choice,pos;
    while(1) {
        printf("\nEnter your choice\n1.Insert front\n2.Insert last\n3.Insert at position\n4.Delete front\n5.Delete last\n6.Delete at position\n7.Display\n8.Node Count\n9.Exit :");
        scanf("%d",&choice);
        switch(choice) {
            case 1: 
            printf("Enter the item to be added ");
            scanf("%d",&item);
            insertFront(item);
            break;
            case 2:
            printf("Enter the item to be added ");
            scanf("%d",&item);
            insertLast(item);
            break;
            case 3:
            printf("Enter the item and position to be added ");
            scanf("%d%d",&item,&pos);
            insertAtPos(item,pos);
            break;
            case 4:
            deleteFront();
            break;
            case 5:
            deleteLast();
            break;
            case 6:
            printf("Enter the position of the element to be deleted ");
            scanf("%d",&pos);
            deleteAtPos(pos);
            break;
            case 7:
            display();
            break;
            case 8:
            nodeCount();
            break;
            case 9:
            exit(0);
            default :printf("Invslid choice");
            break;
        }
    }
}