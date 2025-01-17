#include <stdio.h>

// Function for binary search
int binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target)
            return mid;

        // If target is greater, ignore left half
        if (arr[mid] < target)
            left = mid + 1;

        // If target is smaller, ignore right half
        else
            right = mid - 1;
    }

    // If target is not present in array
    return -1;
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array in sorted order: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    int target;
    printf("Enter the target element to search for: ");
    scanf("%d", &target);
    
    int result = binarySearch(arr, n, target);
    if (result != -1)
        printf("Element %d found at index %d\n", target, result);
    else
        printf("Element %d not found in the array\n", target);
    return 0;
}
