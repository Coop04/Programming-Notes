#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int queue[MAX];
int front=-1;
int rear=-1;
void enqueue(int item) {
    if((front==0 && rear==MAX-1)||front==rear+1) {//Rear is behind front.
        printf("Queue Overflow\n");
    }
    else {
        if(front==-1) 
            front=0;
        rear=(rear+1)%MAX;
        queue[rear]=item;
    }
}
void dequeue() {
    if(front==-1) {
        printf("Queue Underflow\n");
    }
    printf("The deleted item is %d\n",queue[front]);
    if(front==rear) {
        front=-1;
        rear=-1;
    }
    else {
        front=(front+1)%MAX;
    }
}
void display() {
    int i;
    if(front==-1) {
        printf("Queue is empty\n");
    }
    else {
        for(i=front;i<=rear;i++)
        printf("%d\t",queue[i]);
    } 
}   
void main() {
    int item,choice;
    while(1) {
        printf("\nEnter your choice\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit :");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
            printf("Enter the item to be added :");
            scanf("%d",&item);
            enqueue(item);
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
        }
    }
}