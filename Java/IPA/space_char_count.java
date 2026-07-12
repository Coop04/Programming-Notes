import java.util.Scanner;

public class space_char_count {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a string: ");
        String s = sc.nextLine();
        int char_count = 0;
        int space_count = 0;
        for(int i=0;i<s.length();i++) {
            char ch = s.charAt(i);
            if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')) {
                char_count++;
            }
            else if(ch==' ') {
                space_count++;
            }
        }
        System.out.println("Character count: " + char_count);
        System.out.println("Space count: " + space_count);
    }
}
