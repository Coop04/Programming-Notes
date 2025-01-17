# include <stdio.h>

void selection_sort(int b[], int size);

void main() {
    int n, i, a[20];
    printf("Enter size of the array\n");
    scanf("%d", &n);
    printf("Enter elements into the array\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Elements before sorting\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    selection_sort(a, n);
    printf("Elements after sorting in ascending order\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void selection_sort(int b[], int size) {
    int i, j, min, temp = 0;
    for (i = 0; i < size - 1; i++) {
        min = i;
        for (j = i + 1; j < size; j++) {
            if (b[j] < b[min])
                min = j;
        }
        if (min != i) {
            temp = b[i];
            b[i] = b[min];
            b[min] = temp;
        }
    }
}
