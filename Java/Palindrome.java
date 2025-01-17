import java.util.Scanner;
class Palindrome {
    public static void main(String args[]) {
        int i,j,flag=0;
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the string to be checked");
        String a=sc.next();
        for(i=0,j=(a.length()-1);i<a.length();i++,j--)
        if(a.charAt(i)==a.charAt(j))
        flag++;
        if(flag==a.length())
        System.out.println("Palindrome");
        else 
        System.out.println("Not a Palindrome");
    }
}