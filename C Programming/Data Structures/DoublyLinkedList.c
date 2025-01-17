#include<stdio.h>
#include<stdlib.h>
typedef struct nodeType {
    int data;
    struct nodeType *llink;
    struct nodeType *rlink;
}Node;
Node *head=NULL;
int nodeCount() {
    Node *temp;
    int ctr=0;
    if(head==NULL) {
        printf("\nList is empty");
    }
    else {
        temp=head;
        while(temp!=NULL) {
            temp=temp->rlink;
            ctr++;
        }
        printf("No. of nodes are : %d",ctr);
        return ctr;
    }
}
void insertFront(int k) {
    Node *newnode;
    newnode=(Node*)malloc(sizeof(Node));
    newnode->data=k;
    newnode->llink=NULL;
    newnode->rlink=NULL;
    if(head==NULL) {
        head=newnode;
    }
    else {
        newnode->rlink=head;
        head->llink=newnode;
        head=newnode;
    }
}
void insertLast(int k) {
    Node *newnode,*temp;
    newnode=(Node*)malloc(sizeof(Node));
    newnode->data=k;
    newnode->llink=NULL;
    newnode->rlink=NULL;
    if(head==NULL) {
        head=newnode;
    }
    else {
        temp=head;
        while(temp->rlink!=NULL) {
            temp=temp->rlink;
        }
        temp->rlink=newnode;
        newnode->llink=temp;
    }
}
void insertAtPos(int k,int pos) {
    Node *newnode,*temp,*prev;
    int count=nodeCount(),ctr=0;
    newnode=(Node*)malloc(sizeof(Node));
    newnode->data=k;
    newnode->llink=NULL;
    newnode->rlink=NULL;
    if(pos<0||pos>count) {
        printf("Invalid Position");
    }
    else {
        temp=head;
        while(ctr<pos-1) {
            prev=temp;
            temp=temp->rlink;
            ctr++;
        }
        newnode->llink=prev;
        newnode->rlink=temp;
        prev->rlink=newnode;
        temp->llink=newnode;
    }
}
void deleteFront() {
    Node *temp;
    if(head==NULL) {
        printf("List is empty");
    }
    else {
        temp=head;
        head=head->rlink;
        head->llink=NULL;
        printf("Deleted element is %d",temp->data);
        free(temp);
    }
}
void deleteLast() {
    Node *temp,*prev;
    if(head==NULL) {
        printf("List is empty");
    }
    else {
        temp=head;
        while(temp->rlink!=NULL) {
            prev=temp;
            temp=temp->rlink;
        }
        prev->rlink=NULL;
        free(temp);
    }
}
void deleteAtPos(int pos) {
    Node *temp,*prev;
    int count=nodeCount(),ctr=0;
    if(pos<0||pos>count) {
        printf("Invalid Position");
    }
    else {
        temp=head;
        while(ctr<pos-1) {
            prev=temp;
            temp=temp->rlink;
        }
        temp->rlink->llink=prev;
        prev->rlink=temp->rlink;
        printf("Deleted element is %d",temp->data);
        free(temp);
    }
}
void reverseList() {
    Node *temp = NULL;
    Node *current = head;
    while (current != NULL) {
        temp = current->llink;
        current->llink = current->rlink;
        current->rlink = temp;
        head = current;
        current = current->llink;
    }
}
void display() {
    Node *temp;
    if(head==NULL) {
        printf("List is empty");
    }
    else {
        temp=head;
        while(temp!=NULL) {
            printf("%d\t",temp->data);
            temp=temp->rlink;
        }
    }
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
            printf("Enter the item : ");
            scanf("%d",&item);
            printf("Eenter the position : ");
            scanf("%d",&pos);
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
        }
    }
}