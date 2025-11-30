import java.util.Random;
import java.util.Scanner;
public class _23_number_guessing {
    public static void main(String[] args) {
        // NUMBER GUESSING GAME

        Random random = new Random();
        Scanner scanner = new Scanner(System.in);

        int num = random.nextInt(1,7);
        int guess = 0;
        int flag = 0;
        
        do {
            if(flag == 1) {
                System.out.println("Wrong Guess!!");
            }
            System.out.print("Enter your guess: ");
            guess = scanner.nextInt();
            flag = 1;
        } while(guess!=num);
        System.out.println("Guessed Right>> number was "+num);
    }
}
