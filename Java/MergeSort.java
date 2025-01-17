import java.util.Scanner;

public class MergeSort {
    public static void merge(int[] a, int low, int mid, int high) {
        int[] b = new int[high - low + 1]; // Ensure b is large enough to hold all elements
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
        for (int k = low, j = 0; k <= high; k++, j++) {
            a[k] = b[j];
        }
    }

    public static void mergeSort(int[] a, int low, int high) {
        if (low < high) {
            int mid = (low + high) / 2;
            mergeSort(a, low, mid);
            mergeSort(a, mid + 1, high);
            merge(a, low, mid, high);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the size of array: ");
        int n = scanner.nextInt();
        int[] a = new int[n];
        System.out.println("Enter the numbers:");
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        int low = 0;
        int high = n - 1;
        mergeSort(a, low, high);
        System.out.print("Sorted array is: ");
        for (int i = 0; i < n; i++) {
            System.out.print(a[i] + " ");
        }
    }
}
