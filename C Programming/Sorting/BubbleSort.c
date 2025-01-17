# include <stdio.h>

void bubble_sort(int b[], int size);

void main() {
    int n, i, a[20];
    printf("Enter size of the array\n");
    scanf("%d", &n);
    printf("Enter elements into the array\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Elements before sorting\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    bubble_sort(a, n);
    printf("Elements after sorting in ascending order\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void bubble_sort(int b[], int size) {
    int i, temp = 0, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (b[j] > b[j + 1]) {
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }
}
