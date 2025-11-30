import java.util.Scanner;
public class _20_calculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter 1st number: ");
        double num1 = scanner.nextDouble();
        System.out.print("Enter Operator: ");
        char op = scanner.next().charAt(0); // charAt() also helps to convert to character
        System.out.print("Enter 2nd number: ");
        double num2 = scanner.nextDouble();


        switch(op) {
            case '+' -> System.out.println("Result: "+(num1+num2)); // use () to do operation inside println() otherwise it will become string concatination
            case '-' -> System.out.println("Result: "+(num1-num2));
            case '*' -> System.out.println("Result: "+(num1*num2));
            case '^' -> System.out.println("Result: "+Math.pow(num1,num2));
            case '/' -> {
                if(num2==0) {
                    System.out.println("Division by 0 is not possible!");
                }
                else {
                    System.out.println("Result: "+(num1/num2));
                }
            }
            default -> {
                System.out.println("Invalid Operator");
            }
        }
        scanner.close();
    }
}
