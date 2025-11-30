import java.util.Scanner;
public class _24_for {
    public static void main(String[] args) throws InterruptedException{
        Scanner scanner = new Scanner(System.in);

        // System.out.print("Enter how many times you want to loop: ");
        // int max = scanner.nextInt();

        // for(int i=0;i<=max;i++) {
        //     System.out.println(i);
        // }

        // scanner.close();

        for(int j=10;j>0;j--) {
            System.out.println(j);
            Thread.sleep(1000); // 1000 is milliseconds to sleep
        }
        System.out.println("HAPPY NEW YEAR");
    }
}
