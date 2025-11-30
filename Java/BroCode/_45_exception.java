import java.util.InputMismatchException;
import java.util.Scanner;

public class _43_exception {
    public static void main(String[] args) {

        // Exception = An event that interrupts the normal flow of a program
        //                      (Dividing by zero, file not found, mismatch input type)
        //                      Surround any dangerous code with a try{} block
        //                      try{}, catch{}, finally{}

        try (Scanner scanner = new Scanner(System.in)) { // when placing scanner inside the try block 
                                                         // java will automatically close it at the end
                                                         // when not using scanner inside the syntax is: 
                                                         // try{} catch(){} , no need to use () after try
            System.out.print("Enter a number: ");
            int number = scanner.nextInt();
            System.out.println(number);
        } 
        catch (InputMismatchException e) {
            System.out.println("That wasn't a number!");
        } 
        catch (ArithmeticException e) {
            System.out.println("YOU CAN'T DIVIDE BY ZERO!");
        } 
        catch (Exception e) {
            // SAFETY NET
            System.out.println("Something went wrong");
        } 
        finally {
            System.out.println("This always executes");
            // when using files/resources can be useful to close files which are opened in the try block
            // eg: scanner.close() // we can also close scanner etc.
        }
    }
}

