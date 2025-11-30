import java.util.*;
class Age {
    void vote(int age) throws IllegalAccessException {
        try {
            if (age < 18) {
                throw new IllegalAccessException("You must be 18 years of age.");
            } else {
                System.out.println("You can vote!");
            }
        } catch (Exception e) {
            System.out.println("Exception occurred: " + e);
        } finally {
            System.out.println("Finally, age verification is done.");
        }
    }
}
public class AgeException {
    public static void main(String args[]) throws IllegalAccessException {
        Scanner sc = new Scanner(System.in);
        int age;
        System.out.println("Enter age:");
        age = sc.nextInt();
        Age av = new Age();
        av.vote(age);
        //System.out.println("Verification is done.");
    }
}
