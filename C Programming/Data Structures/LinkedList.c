#include<stdio.h>
#include<stdlib.h>

typedef struct nodeType {
    int data;
    struct nodeType* link;
} Node;

Node *head = NULL;

// Function to count the number of nodes in the linked list
int countNode() {
    int ctr = 0;
    Node *temp;
    temp = head;
    while (temp != NULL) {
        temp = temp->link;
        ctr++;
    }
    printf("No.of nodes are : %d\n", ctr);
    return ctr;
}

// Function to insert a node at the front of the linked list
void insertFront(int k) {
    Node *newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = k;
    newNode->link = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->link = head;
        head = newNode;
    }
}

// Function to insert a node at the end of the linked list
void insertLast(int k) {
    Node *newNode, *temp;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = k;
    newNode->link = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newNode;
    }
}

// Function to insert a node at a specific position in the linked list
void insertAtPos(int k, int pos) {
    Node *newNode, *temp, *prev;
    int ctr = 0;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = k;
    newNode->link = NULL;
    int count = countNode();
    if (pos < 0 || pos > count) {
        printf("Invalid Position\n");
    } else {
        temp = head;
        while (ctr < pos - 1) {
            ctr++;
            prev = temp;
            temp = temp->link;
        }
        newNode->link = temp;
        prev->link = newNode;
    }
}

// Function to delete the first node from the linked list
int deleteFront() {
    Node *temp;
    if (head == NULL) {
        printf("List is empty\n");
        return -1;
    } else {
        temp = head;
        head = head->link;
        printf("Item deleted is : ");
        int data = temp->data;
        free(temp);
        return data;
    }
}

// Function to delete the last node from the linked list
void deleteLast() {
    Node *temp, *dlt;
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        temp = head;
        while (temp->link->link != NULL) {
            temp = temp->link;
        }
        dlt = temp->link;
        printf("Item deleted is : %d", dlt->data);
        free(dlt);
        temp->link = NULL;
    }
}

// Function to delete a node at a specific position from the linked list
void deleteAtPos(int pos) {
    Node *temp, *prev;
    int ctr = 0, count = countNode();
    if (pos < 0 || pos > count) {
        printf("Invalid Position\n");
    } else {
        temp = head;
        while (ctr < pos - 1) {
            ctr++;
            prev = temp;
            temp = temp->link;
        }
        prev->link = temp->link;
        printf("\nItem deleted is : %d", temp->data);
        free(temp);
    }
}

// Function to display the linked list
void display() {
    Node *temp;
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        temp = head;
        while (temp != NULL) {
            printf("%d\t", temp->data);
            temp = temp->link;
        }
    }
}

// Function to reverse the linked list
void reverseList() {
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;
    while (current != NULL) {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
void insertSorted(int k) {
    Node *newNode, *temp, *prev;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = k;
    newNode->link = NULL;
    if (head == NULL || head->data >= k) {
        newNode->link = head;
        head = newNode;
    } else {
        temp = head;
        while (temp != NULL && temp->data < k) {
            prev = temp;
            temp = temp->link;
        }
        newNode->link = temp;
        prev->link = newNode;
    }
}


// Main function
void main() {
    int item, choice, pos;
    while (1) {
        printf("\nEnter your choice\n1.Insert front\n2.Insert last\n3.Insert at position\n4.Delete front\n5.Delete last\n6.Delete at position\n7.Display\n8.Node Count\n9.Reverse List\n10.Exit :");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the item to be added ");
                scanf("%d", &item);
                insertFront(item);
                break;
            case 2:
                printf("Enter the item to be added ");
                scanf("%d", &item);
                insertLast(item);
                break;
            case 3:
                printf("Enter the item : ");
                scanf("%d", &item);
                printf("Enter the position : ");
                scanf("%d", &pos);
                insertAtPos(item, pos);
                break;
            case 4:
                deleteFront();
                break;
            case 5:
                deleteLast();
                break;
            case 6:
                printf("Enter the position of the element to be deleted ");
                scanf("%d", &pos);
                deleteAtPos(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                countNode();
                break;
            case 9:
                reverseList();
                break;
            case 10:
                exit(0);
        }
    }
}
