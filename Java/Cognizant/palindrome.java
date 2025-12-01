import java.util.Scanner;

public class palindrome {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter Number: ");
        int num = scanner.nextInt();
        String s = ""+num;
        int n = s.length();
        String p = "";

        for(int i=n-1;i>=0;i--) {
            p = p+s.charAt(i);
        }
        System.out.println(p);
        if(p.equals(s)) {
            System.out.println("Palindrome");
        }
        else {
            System.out.println("Not Plaindrome");
        }
    }
}
