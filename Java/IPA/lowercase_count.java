import java.util.Scanner;
public class lowercase_count {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter String: ");
        String s = sc.nextLine();
        int count = 0;
        for(int i=0;i<s.length();i++) {
            if(s.charAt(i)>='a' && s.charAt(i)<='z') { // to check if lower case
                count = count+1;
            }
        }
        System.out.println(count);
    }
}
