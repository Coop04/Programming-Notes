#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coefficient;
    int exponent;
    struct Node *link;
};

typedef struct Node Node;

Node *createNode(int coefficient, int exponent) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->coefficient = coefficient;
        newNode->exponent = exponent;
        newNode->link = NULL;
    }
    return newNode;
}

void insertTerm(Node **head, int coefficient, int exponent) {
    Node *newNode = createNode(coefficient, exponent);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *current = *head;
        while (current->link != NULL) {
            current = current->link;
        }
        current->link = newNode;
    }
}

void displayPolynomial(Node *head) {
    while (head != NULL) {
        printf("%dx^%d ", head->coefficient, head->exponent);
        if (head->link != NULL) {
            printf("+ ");
        }
        head = head->link;
    }
    printf("\n");
}

Node *addPolynomials(Node *poly1, Node *poly2) {
    Node *result = NULL;
    Node *current1 = poly1;
    Node *current2 = poly2;
    while (current1 != NULL && current2 != NULL) {
        if (current1->exponent > current2->exponent) {
            insertTerm(&result, current1->coefficient, current1->exponent);
            current1 = current1->link;
        } else if (current1->exponent < current2->exponent) {
            insertTerm(&result, current2->coefficient, current2->exponent);
            current2 = current2->link;
        } else {
            int sumCoefficients = current1->coefficient + current2->coefficient;
            insertTerm(&result, sumCoefficients, current1->exponent);
            current1 = current1->link;
            current2 = current2->link;
        }
    }
    while (current1 != NULL) {
        insertTerm(&result, current1->coefficient, current1->exponent);
        current1 = current1->link;
    }
    while (current2 != NULL) {
        insertTerm(&result, current2->coefficient, current2->exponent);
        current2 = current2->link;
    }
    return result;
}

Node *multiplyPolynomials(Node *poly1, Node *poly2) {
    Node *result = NULL;
    Node *current1 = poly1;
    while (current1 != NULL) {
        Node *current2 = poly2;
        while (current2 != NULL) {
            int productCoefficient = current1->coefficient * current2->coefficient;
            int sumExponents = current1->exponent + current2->exponent;
            insertTerm(&result, productCoefficient, sumExponents);
            current2 = current2->link;
        }
        current1 = current1->link;
    }
    return result;
}

void freeList(Node *head) {
    while (head != NULL) {
        Node *temp = head;
        head = head->link;
        free(temp);
    }
}

int main() {
    Node *poly1 = NULL;
    Node *poly2 = NULL;
    int n, coefficient, exponent;
    
    printf("Enter the number of terms for Polynomial 1: ");
    scanf("%d", &n);
    printf("Enter the terms for Polynomial 1 (coefficient exponent):\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &coefficient, &exponent);
        insertTerm(&poly1, coefficient, exponent);
    }
    
    printf("Enter the number of terms for Polynomial 2: ");
    scanf("%d", &n);
    printf("Enter the terms for Polynomial 2 (coefficient exponent):\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &coefficient, &exponent);
        insertTerm(&poly2, coefficient, exponent);
    }
    
    printf("Polynomial 1: ");
    displayPolynomial(poly1);
    printf("Polynomial 2: ");
    displayPolynomial(poly2);
    
    Node *sumResult = addPolynomials(poly1, poly2);
    printf("Sum of Polynomials: ");
    displayPolynomial(sumResult);
    
    Node *productResult = multiplyPolynomials(poly1, poly2);
    printf("Product of Polynomials: ");
    displayPolynomial(productResult);
    
    freeList(poly1);
    freeList(poly2);
    freeList(sumResult);
    freeList(productResult);
    
    return 0;
}
