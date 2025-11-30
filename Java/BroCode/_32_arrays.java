import java.util.Arrays;
public class _32_arrays {
    public static void main(String[] args) {
        // array = a collection of values of same data type

        String[] fruits = {"apple", "orange", "grape"};

        fruits[2] = "coconut";

        // to find length of array
        int length = fruits.length; // . is called the access modifier
        System.out.println("Length: "+length);

        // printing the array elements
        for(int i=0;i<fruits.length;i++) { //here length doesnot need () at end like we use for finding string length(length())
            System.out.print(fruits[i]+ " ");
        }

        System.out.println();

        // printing using enhanced for loop / for-each loop
        for(String fruit: fruits) {  // for every fruit in fruits array
            System.out.print(fruit+" ");
        }

        // sorting array (must import Arrays)
        System.out.print("\nAfter sorting: ");
        Arrays.sort(fruits);
        for(String i: fruits) {
            System.out.print(i+" ");
        }

        // array filling
        System.out.print("\nAfter filling: ");
        Arrays.fill(fruits,"pineapple"); // makes every value in the array pineapple
        for(String i: fruits) {
            System.out.print(i+" "); 
        }

        System.out.println();

        // to copy an array
        String[] fruits2 = Arrays.copyOf(fruits, fruits.length); // 2nd parameter is the range of elements to copy
        for(String i : fruits2) {
            System.out.print(i+ " ");
        }

        System.out.println();
        // if we directly copy using = it will not make a new array, it will point to the old array
        // ie if we are making change to the new one , the old one also changes
        String[] fruits3 = fruits; // so dont do this
        for(String i : fruits3) {
            System.out.print(i+ " ");
        }
        System.out.println();
        fruits3[1] = "orange";
        for(String i : fruits) {
            System.out.print(i+ " ");
        }

        // to check equalit of 2 arrays
        System.out.println("\n"+Arrays.equals(fruits, fruits3));

        // array comparison (returns 0 if equal, 
        // -ve value (according to the difference) if lexographically first, 
        // +ve value if lexographically second)
        int c = Arrays.compare(fruits, fruits2);
        System.out.println(c);

        // binary search
        int[] arr = {1,2,3,4,5,9,0};
        int i = Arrays.binarySearch(arr, 9); // 1st array name, 2nd target element
        System.out.println(i);
    }
    
}
