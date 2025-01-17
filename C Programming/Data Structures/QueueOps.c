#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int queue[MAX];
int front=-1,rear=-1;
void enqueue() {
    if(rear==MAX-1)
    printf("Queue Overflow");
    else {
        int item;
        printf("Enter the item to be added\n");
        scanf("%d",&item);
        if(rear==-1) 
            front=0;
        rear++;
        queue[rear]=item;
    }
}
void dequeue() {
    if(front==-1)
    printf("Queue Underflow");
    else {
        printf("The deleted item is %d\n",queue[front]);
        front++;
    }
}
void display() {
    int i;
    printf("The queue elements are\n");
    for(i=front;i<=rear;i++) {
        printf("%d\n",queue[i]);
    }
}
void main() {
    int choice;
    while(1) {
        printf("Enter your choice\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit  : ");
        scanf("%d",&choice);
        switch(choice) {
            case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
                    break;
            default: printf("Invalid Choice");
        }
    }
}