#include <stdio.h>

int partition(int a[], int low, int high) {
    int i = low, j = high, pivot = low, temp;
    while (i < j) { // checking if i and j overlapped or not
        while (a[i] <= a[pivot])// checks for bigger elements than pivot
            i++;
        while (a[j] > a[pivot])// checks for smaller elements than pivot
            j--;
        if (i < j) { // swapping a[i] and a[j]
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    // swapping a[j] and a[pivot] if i and j are overlapped
    temp = a[j];
    a[j] = a[pivot];
    a[pivot] = temp;

    return j;
}

void QuickSort(int a[], int low, int high) {
    int j;
    if (low < high) {
        j = partition(a, low, high);
        QuickSort(a, low, j - 1);
        QuickSort(a, j + 1, high);
    }
}

int main() {
    int i, a[10], n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("Enter the numbers: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int low = 0;
    int high = n - 1;
    QuickSort(a, low, high);
    printf("Sorted array is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
