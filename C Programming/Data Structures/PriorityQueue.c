#include<stdio.h>
#include<limits.h>

#define MAX 100

int idx = -1;
int pqVal[MAX];
int pqPriority[MAX];

int isEmpty() {
    return idx == -1;
}

int isFull() {
    return idx == MAX - 1;
}

void enqueue(int data, int priority) {
    if (!isFull()) {
        idx++;
        pqVal[idx] = data;
        pqPriority[idx] = priority;
    }
}

int peek() {
    int maxPriority = INT_MIN;
    int indexPos = -1;
    
    for (int i = 0; i <= idx; i++) {
        if (maxPriority == pqPriority[i] && indexPos > -1 && pqVal[indexPos] < pqVal[i]) {
            maxPriority = pqPriority[i];
            indexPos = i;
        } else if (maxPriority < pqPriority[i]) {
            maxPriority = pqPriority[i];
            indexPos = i;
        }
    }
    return indexPos;
}

void dequeue() {
    if (!isEmpty()) {
        int indexPos = peek();
        for (int i = indexPos; i < idx; i++) {
            pqVal[i] = pqVal[i + 1];
            pqPriority[i] = pqPriority[i + 1];
        }
        idx--;
    }
}

void display() {
    for (int i = 0; i <= idx; i++) {
        printf("(%d, %d)\n", pqVal[i], pqPriority[i]);
    }
}

int main() {
    int x, y, ch;
    
    do {
        printf("\t==== Menu ====\n");
        printf("\t 1. Enqueue\n");
        printf("\t 2. Dequeue\n");
        printf("\t 3. Display\n");
        printf("\t 0. Exit\n");
        printf("Your Choice :- \t");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value, its priority :- \n");
                scanf("%d%d", &x, &y);
                enqueue(x, y);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 0:
                break;
            default:
                printf("Invalid Choice .....\n");
        }
    } while (ch != 0);

    return 0;
}
