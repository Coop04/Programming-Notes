import java.util.Scanner;
public class _26_nestedloop {
    public static void main(String[] args) {
        // for(int j=0;j<3;j++) {
        //     for(int i=0;i<10;i++) {
        //     System.out.print(i+" ");
        //     }
        //     System.out.println();
        // }

        // -----------------------------------------

        // MATRIX
        Scanner scanner = new Scanner(System.in);

        int rows;
        int columns;
        char symbol;

        System.out.print("Enter no. of rows: ");
        rows = scanner.nextInt();
        System.out.print("Enter no. of clumns: ");
        columns = scanner.nextInt();
        System.out.print("Enter the symbol to use: ");
        symbol = scanner.next().charAt(0);

        for(int i=0;i<rows;i++) {
            for(int j=0;j<columns;j++) {
                System.out.print(symbol + " ");
            }
            System.out.println();
        }
    }
}
