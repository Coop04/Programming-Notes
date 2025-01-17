import java.util.Scanner;
class StringReverse {
    public static void main(String args[]) {
        String str2="";
        int i;
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the string");
        String str1=sc.next();
        for(i=str1.length()-1;i>=0;i--) {
            str2+=str1.charAt(i);
        }
        System.out.println(str2);
    }
}