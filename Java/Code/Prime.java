import java.util.Scanner;
class Prime {
    public static void main(String args[]) {
        int i,flag=0;
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the number to be checked");
        int a=sc.nextInt();
        for(i=2;i<a;i++) {
            if(a%i==0)
            flag++;
        }
        if(flag==0)
        System.out.println("Prime");
        else
        System.out.println("Not Prime");
    }
}