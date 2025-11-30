import java.util.Scanner;
public class _22_while {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String name = "";

        while(name.isEmpty()) {
            System.out.print("Enter a name: ");
            name = scanner.nextLine();
        }
        System.out.println("Hii "+name);

        // -----------------------------------------
        String response = "";
        while(!response.equals("Q")) {
            System.out.print("Enter a response (Q to quit): ");
            response = scanner.next().toUpperCase();
        }
        System.out.println("You have successfully entered Q!");

        // ---------------------------------------------

        scanner.nextLine(); // sice there is a \n from previous next()

        // DO WHILE
        String name1 = "";
        do {
            System.out.print("Enter a name: ");
            name1 = scanner.nextLine();
        } while(name1.isEmpty());
        System.out.println("Hii "+name);

        
        scanner.close();

    }
}
