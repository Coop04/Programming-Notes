import java.util.Scanner;
public class _5_madlibs {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String adjective1; // adjective describes something (eg: fast, slow, cheap, expensive)
        String noun1; // noun is a person, place or a thing
        String adjective2;
        String verb1; // verb is an action (eg: sleeping, running)
        String adjective3;

        System.out.print("Enter an adjective (description):");
        adjective1 = scanner.nextLine();
        System.out.print("Enter an noun (animal or person):");
        noun1 = scanner.nextLine();
        System.out.print("Enter another adjective:");
        adjective2 = scanner.nextLine();
        System.out.print("Enter a verb (ending with -ing):");
        verb1 = scanner.nextLine();
        System.out.print("Enter another adjective:");
        adjective3 = scanner.nextLine();


        System.out.println("\nToday I went to a " + adjective1 + " zoo.");
        System.out.println("In an exhibit i saw a "+ noun1 + ".");
        System.out.println(noun1 + " was " + adjective2 + " and " + verb1 + "!");
        System.out.println("I was "+ adjective3 + "!");

        scanner.close();
    }
}
