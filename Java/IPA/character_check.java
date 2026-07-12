import java.util.Scanner;
public class character_check {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter String: ");
        String s = sc.nextLine();
        System.out.println("Enter character to check: ");
        char c = sc.next().charAt(0);
        for(int i=0;i<s.length();i++) {
            if(s.charAt(i)==c) {
                System.out.println(i);
                break;
            }
        }
    }

}
