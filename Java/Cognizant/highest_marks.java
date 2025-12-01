import java.util.Scanner;

public class highest_marks {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int m = 0;

        System.out.print("Enter the number of semesters: ");
        int n = scanner.nextInt();
        int[] sem = new int[n];
        int[] max = new int[n];

        for(int i=0;i<n;i++) {
            System.out.print("Enter number of subjects in semester "+(i+1)+": ");
            sem[i] = scanner.nextInt();
        }
        for(int i=0;i<n;i++) {
            m=0;
            System.out.println("Marks obtained in semester "+(i+1));
            for(int j=0;j<sem[i];j++) {
                int p = scanner.nextInt();
                if(p<0) {
                    System.out.println("Invalid mark");
                    return;
                }
                if(m<p) {
                    m=p;
                }
            }
            max[i] = m;
        }
        for(int i=0;i<n;i++) {
            System.out.println("Maximum mark in "+(i+1)+" semester: "+max[i]);
        }
    }
}
