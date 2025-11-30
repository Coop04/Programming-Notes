import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class _32_arraylist {
    public static void main(String[] args) {
        // ArrayList = A resizeable array that stores objects (autoboxing)
        //             Arrays are fixed in size, but ArrayLists can change

        ArrayList<Integer> list = new ArrayList<>();
        // ArrayList<Double> dlist = new ArrayList<>();
        ArrayList<String> fruits = new ArrayList<>();

        // to add an element
        list.add(3);
        list.add(1);
        list.add(2);

        fruits.add("apple");
        fruits.add("orange");
        fruits.add("cherry");
        fruits.add("kiwi");
        fruits.add("guava");
        fruits.add("avacado");

        // to remove an element
        fruits.remove(1);

        // to set a value
        fruits.set(1,"coconut"); // replaces the value at 2nd index

        // access / get an element
        System.out.println(fruits.get(1));

        // size of an ArrayList
        System.out.println(fruits.size());

        // printing a list
        System.out.println(list);

        // to sort ArrayList (we use collections framework)
        Collections.sort(fruits); // you need to import this class
        System.out.println(fruits);

        // printing using enhanced for loop
        for(String i : fruits) {
            System.out.print(i+ " ");
        }

        System.out.println();
        
        System.out.println(fruits);

        // Scanning to an arraylist
        Scanner scanner = new Scanner(System.in);
        ArrayList<String> foods = new ArrayList<>();

        System.out.print("Enter the no. of food you would like: ");
        int numOfFood = scanner.nextInt();
        scanner.nextLine(); // cleaning input buffer;

        for(int i = 1; i<=numOfFood; i++) {
            System.out.print("Enter food no. "+i+": ");
            String food = scanner.nextLine();
            foods.add(food);
        }
        System.out.println(foods);

        scanner.close();
    }
}
