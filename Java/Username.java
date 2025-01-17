import java.util.Scanner;
class Username {
    public static void main(String args[]) {
        System.out.println("Enter your user name :");
        Scanner sc = new Scanner(System.in);
        String n = sc.nextLine();
        System.out.println("Your user name is : "+n);
    }
}