import java.util.Scanner;

public class _3_input {
    public static void main(String[] args) {
        // Scanner: object that helps to get user input in java
        
        Scanner scanner = new Scanner(System.in); // scanner is the object name

        System.out.print("Enter your name: ");
        
        // nextLine() method reads characters including spaces
        // use print() if you want input in the same line or use println() if you want input in next line
        String name = scanner.nextLine(); // input Aswanth Satheesan
        System.out.println("HELLO "+name); // prints Aswanth Satheesan

        // next() method reads character without any spaces (only the part before the first space is read)
        // System.out.println("Enter your full name");
        // String fullname = scanner.next(); // input Aswanth Satheesan
        // System.out.println(fullname); // prints Aswanth
        // using next() above nextInt() will cause some error 
        // (next() leaves a newline \n in the input buffer. “This is not a number!” → boom, exception.)
        // to slove this use
        // scanner.nextLine();  (dont assign it to anything)

        // ------------------------------------------------------------------------------------------------
        
        // SCANNING INTEGERS
        System.out.print("Enter your age: "); 
        int age = scanner.nextInt(); // nextInt() to scan integers (if double values are typed in cause error)
        System.out.println("You are " +age+ " years old.");

        // ------------------------------------------------------------------------------------------------

        // SCANNING DOUBLES
        System.out.print("What is your GPA:");
        double gpa = scanner.nextDouble();
        System.out.println("GPA: "+gpa);

        // -------------------------------------------------------------------------------------------------

        // SCANNING BOOLEANS
        System.out.print("Are you a student? (true/false): ");
        boolean isStudent = scanner.nextBoolean();
        System.out.println("Student: "+isStudent);
        
        // -------------------------------------------------------------------------------------------------

        // COMMON ISSUE
        System.out.print("Enter price: ");
        int price = scanner.nextInt(); 
        // when using Scanner methods like next(), nextInt(), nextDouble() etc. when we type the input and press enter(\n)
        // it will not automatically consume the \n like nextLine(). so the buffer will not be empty while reading something next.
        // and that might cause error of reading unwanted characters.
        
        scanner.nextLine(); // to slove this issue use nextLine() method without assigning it to anything. It will consume the \n

        System.out.print("Enter your favourite color: ");
        String color = scanner.nextLine();

        System.out.println("Your choices are: " +price+ " & " +color);

        // -----------------------------------------------------------------------------------------
        scanner.close(); // good practice
    }
}
