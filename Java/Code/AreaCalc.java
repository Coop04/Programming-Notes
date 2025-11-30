import java.util.Scanner;
class AreaCalc {
    public static void main(String args[]) {
        int a,b,opr;
        System.out.println("1 : Circle\n2 : Square\n3 : Triangle\nChoose your selection");
        Scanner sc=new Scanner(System.in);
        opr = sc.nextInt();
        switch(opr) {
            case 1:
                System.out.println("Enter radius");
                a=sc.nextInt();
                System.out.println("Area is : "+3.14*a*a);
                break;
            case 2:
                System.out.println("Enter length");
                a=sc.nextInt();
                System.out.println("Area is : "+a*a);
                break;
            case 3:
                System.out.println("Enter base & height");
                a=sc.nextInt();
                b=sc.nextInt();
                System.out.println("Area is : "+.5*a*b);
                break;
        }
    }
}
