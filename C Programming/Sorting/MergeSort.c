#include <stdio.h>

void Merge(int a[], int low, int mid, int high) {
    int b[high - low + 1]; // Ensure b is large enough to hold all elements
    int k;
    int i = 0; // Initialize index for array b
    int x = low;
    int y = mid + 1;

    // Sorting of two sorted lists. mid+1 considered as 2nd list
    while (x <= mid && y <= high) {
        if (a[x] <= a[y]) {
            b[i++] = a[x++];
        } else {
            b[i++] = a[y++];
        }
    }

    // Copy remaining elements in list1 from x to mid.
    while (x <= mid) {
        b[i++] = a[x++];
    }
    
    // Copy remaining elements in list2 from y to high
    while (y <= high) {
        b[i++] = a[y++];
    }
    
    // Copy sorted elements from b back to a
    for (k = low, i = 0; k <= high; k++, i++) {
        a[k] = b[i];
    }
}


void MergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(a, low, mid);
        MergeSort(a, mid + 1, high);
        Merge(a, low, mid, high);
    }
}

int main() {
    int i, a[10], n;
    printf("Enter the size of array");
    scanf("%d", &n);
    printf("Enter the numbers");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int low = 0;
    int high = n - 1;
    MergeSort(a, low, high);
    printf("Sorted array is ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
