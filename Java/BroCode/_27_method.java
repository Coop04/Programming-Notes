import java.util.Scanner;
public class _27_method {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // System.out.print("Enter your Name: ");
        // String name = scanner.nextLine();
        // System.out.print("Enter your age: ");
        // int age = scanner.nextInt();

        // happyBirthday(name,age);
        // --------------------------------------------------

        // System.out.print("Enter a number: ");
        // int num = scanner.nextInt();

        // int sq = square(num);
        // System.out.println("Squre of "+num+": "+sq);

        // -----------------------------------------------------

        System.out.println("Enter your age");
        int ag = scanner.nextInt();
        boolean adult = ageCheck(ag);
        if(adult)
            System.out.println("You can enter.");
        else 
            System.out.println("You are not permitted!");

    }

    static void happyBirthday(String name, int x) {
        System.out.println("Happy birthday to you, "+name);
        System.out.println("You are "+x+ " years old");
        System.out.println();
    }

    static int square(int n) {
        int square = (int)Math.pow(n,2); // we need to type cast the result into int since pow returns a double value or you can change the result as a double, return type of fn to double and sq in main also to double
        return square;
    }

    static boolean ageCheck(int age) {
        if(age>=18) 
            return true;
        else
            return false;
    }

}
