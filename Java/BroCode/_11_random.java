import java.util.Random;
public class _11_random {
    public static void main(String[] args) {
        Random random = new Random();

        // . is called access modifier
        
        // Random Integers
        int number1 = random.nextInt(1,7); // 1st no. is inclusive and 2nd no. is exclusive (if limits are not given it will give no.s between -2 Billion and +2 Billion)
        int number2 = random.nextInt(1,7);
        int number3 = random.nextInt(1,7);

        System.out.println(number1+ "\t" +number2+ "\t" +number3);
        // ----------------------------------------------------------
        
        // Random Doubles  
        double number4 = random.nextDouble(1,101); // if no limit is given, generates a random number between 0 & 1
        double number5 = random.nextDouble(1,101);

        System.out.println(number4+ "\t" +number5);
        // ----------------------------------------------------------

        // Random boolean
        boolean selection = random.nextBoolean();
        System.out.println("Your selection: "+selection);
    }
}
