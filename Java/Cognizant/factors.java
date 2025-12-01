import java.util.Scanner;

import java.util.Scanner;
public class factors {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] factors = new int[100];
        System.out.print("Enter a number: ");
        int n = scanner.nextInt();
        n = Math.abs(n);
        int j = 0;

        if(n==0) {
            System.out.println("No Factors");
        }
        else {
            for(int i =1;i<=n;i++) {
                if(n%i==0) {
                    factors[j] = i;
                    j++;
                }
            }
        }
        for(int i : factors) {
            if(i!=0)
                System.out.print(i+" ");
        }
    }
}
