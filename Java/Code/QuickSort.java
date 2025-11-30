import java.util.Scanner;

public class QuickSort {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of names: ");
        int n = sc.nextInt();
        sc.nextLine(); // Consume newline character
        System.out.println("Enter the names:");
        String[] names = new String[n];
        for (int i = 0; i < n; i++) {
            names[i] = sc.nextLine();
        }
        int low = 0;
        int high = n - 1;
        quickSort(names, low, high);
        System.out.println("\nSorted names:");
        for (String name : names) {
            System.out.println(name);
        }
        sc.close();
    }

    private static int partition(String[] names, int low, int high) {
        int i = low, j = high;
        String pivot = names[low];
        while (i < j) {
            while (/*i < j &&*/ names[i].compareTo(pivot) <= 0) // checks for bigger or equal elements than pivot
                i++;
            while (names[j].compareTo(pivot) > 0) // checks for smaller elements than pivot
                j--;
            if (i < j) { // swapping names[i] and names[j]
                String temp = names[i];
                names[i] = names[j];
                names[j] = temp;
            }
        }
        // swapping names[j] and names[low] if i and j are overlapped
        String temp = names[j];
        names[j] = names[low];
        names[low] = temp;

        return j;
    }

    private static void quickSort(String[] names, int low, int high) {
        if (low < high) {
            int partitionIndex = partition(names, low, high);
            quickSort(names, low, partitionIndex - 1);
            quickSort(names, partitionIndex + 1, high);
        }
    }
}
