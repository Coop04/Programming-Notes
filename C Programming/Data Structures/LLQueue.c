#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node*link;
}NODE;
NODE*front=NULL,*rear=NULL;
void enqueue(int item){
    NODE *newnode=(NODE*)malloc(sizeof(NODE));
    newnode->link=NULL;
    newnode->data=item;
    if(front==NULL){
        front=rear=newnode;return;
    }
    rear->link=newnode;
    rear=newnode;
}
void dequeue(){
    if(front==NULL){
        printf("empty\n");return;
    }
    if(front->link==NULL){
        free(front);
        front=rear=NULL;return;
    }
    NODE*temp=front;
    front=front->link;
    free(temp);
}
void disp(){
    if(front==NULL){
        printf("\nEMPTY\n");return;
    }
    printf("------Q------\n");
        NODE*temp=front;
    do{
        printf("%d  ",temp->data);
        temp=temp->link;
        
    }while(temp!=NULL);
}
void main(){
    int ch,item;
    printf("\n1.enQ\n2.deQ\n3.disp\n4exit\n");
    while(1){
        printf("\nEnter choice:  ");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("\nEnter item:  ");
                  scanf("%d",&item);
                  enqueue(item);
                  break;
          case 2:dequeue();break;
          case 3:disp();break;
          case 4:exit(0);
          default:printf("\nINVALID\n");
          break;
        }
    }
}