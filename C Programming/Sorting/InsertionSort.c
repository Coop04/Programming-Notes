#include <stdio.h>

void print(int a[10], int n) {
    int j;
    printf("Sorted list is: \n");
    for (j = 0; j < n; j++)
        printf("%d\t", a[j]);
    printf("\n");
}

void insert(int a[10], int n) {
    int i,j, k, temp;
    for (i = 1; i < n; i++) {
        temp = a[i];
        j = i - 1;  //j is behind
        while (j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];
            j--;//to compare the elements behind.
        }
        a[j + 1] = temp;
    }
    print(a, n);
}

int main() {
    int a[10], n, i;
    printf("Enter the size of the array\n");
    scanf("%d", &n);
    printf("Enter data to be inserted\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    insert(a, n);
    return 0;
}
