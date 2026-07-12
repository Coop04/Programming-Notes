import java.util.Scanner;
public class ignore_duplicate_char {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a string: ");
        String s = sc.nextLine();
        String temp = "";
        for(int i = 0;i<s.length();i++) {
            // checking if the character is present in the new string
            // ie, we check if the index of that character is -1 (ie, if char not present, then add the char to new string)
            if(temp.indexOf(s.charAt(i))==-1) { 
                temp = temp + s.charAt(i);
            }
        }
        System.out.println(temp);
    }
}
