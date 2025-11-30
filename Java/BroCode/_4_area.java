import java.util.Scanner;

public class _4_area {
    public static void main(String[] args) {
        // calculate area of a rectangle

        double width = 0;
        double height = 0;
        double area = 0;

        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter Widht and Height: ");
        width = scanner.nextDouble();
        height = scanner.nextDouble();

        area = width * height;

        System.out.println("Area: "+area);

        scanner.close();
    }
}
