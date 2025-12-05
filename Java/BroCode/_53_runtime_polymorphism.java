import java.util.Scanner;
public class _53_runtime_polymorphism {
    public static void main(String[] args) {
        // Runtime polymorphism / Dynamic polymorphism
        // When the method that gets executed is decided at runtime based on the actual type of the object

        _53_animal animal; // we dont know which method the user is going to select from (the dog's speak method or the cat's speak() method)

        System.out.print("Enter 1 for DOG and 2 for CAT: ");
        Scanner scanner  = new Scanner(System.in);
        int choice = scanner.nextInt();

        if(choice == 1) {
            animal = new _53_dog();
        }
        else {
            animal = new _53_cat();
        }

        animal.speak();
    }
}
