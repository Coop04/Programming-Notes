import java.util.Scanner;
class CharFrequency {
    public static void main(String args[]) {
        int i,flag=0;
        System.out.println("Enter the string");
        Scanner sc=new Scanner(System.in);
        String str=sc.nextLine();
        System.out.println("Enter the element to be searched");
        char ch=sc.next().charAt(0);
        for(i=0;i<str.length();i++)
        if(ch==str.charAt(i))
        flag++;
        System.out.println("Occurance is : "+flag);
    }
}