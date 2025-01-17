import java.util.Scanner;

// Custom exception class for under-age voters
class UnderAgeException extends Exception {
    public UnderAgeException(String message) {
        super(message);
    }
}

// Class representing a voter
class Voter {
    private String name;
    private int age;

    public Voter(String name, int age) {
        this.name = name;
        this.age = age;
    }

    // Method to check eligibility and vote
    public void vote() throws UnderAgeException {
        if (age < 18) {
            throw new UnderAgeException("Sorry, " + name + ", you must be 18 or older to vote.");
        } else {
            System.out.println(name + " voted successfully.");
        }
    }
}

// Main class
public class UserDefinedException {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading voter's name
        System.out.print("Enter your name: ");
        String name = scanner.nextLine();

        // Reading voter's age
        System.out.print("Enter your age: ");
        int age = scanner.nextInt();

        scanner.close();

        try {
            // Creating a voter with the entered age
            Voter voter = new Voter(name, age);
            // Trying to vote
            voter.vote();
        } catch (UnderAgeException e) {
            // Handling the custom exception
            System.out.println("Exception: " + e.getMessage());
        }
    }
}
