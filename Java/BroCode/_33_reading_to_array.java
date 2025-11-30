import java.util.Scanner;
public class _33_reading_to_array {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // static allocation of array size (eg. 3 here)
        // String[] foods = new String[3]; // array declaration: used when typing in the elements later (by food[index]=element or by user input)
                                        // foods is an array object here

        System.out.print("Enter the no. of foods: ");
        int size = scanner.nextInt();

        // dynamically allocating array size. (size is taken from user input)
        String[] foods = new String[size]; // array declaration: used when typing in the elements later (by food[index]=element or by user input)
                                        // foods is an array object here

        scanner.nextLine(); // to consume the \n character in the buffer due to the nextInt() from above

        for(int i=0;i<size;i++) {
            foods[i] = scanner.nextLine();
        }

        for(String i:foods) {
            System.out.print(i+" ");
        }
    }
}
