import java.util.Scanner;
class MatrixMul {
    public static void main(String args[]) {
        int i,j,k;
        int a[][]=new int[5][5];
        int b[][]=new int[5][5];
        int c[][]=new int[5][5];
        System.out.println("Enter the order of matrix 1");
        Scanner sc=new Scanner(System.in);
        int m=sc.nextInt();
        int n=sc.nextInt();
        System.out.println("Enter the order of matrix 2");
        int p=sc.nextInt();
        int q=sc.nextInt();
        if(n!=p)
        System.out.println("Multiplication is not possible");
        else {
            System.out.println("The elements of matrix 1 are");
            for(i=0;i<m;i++)
            for(j=0;j<n;j++)
            a[i][j]=sc.nextInt();
            System.out.println("The elements of matrix 2 are");
            for(i=0;i<p;i++)
            for(j=0;j<q;j++)
            b[i][j]=sc.nextInt();
            for(i=0;i<m;i++)
            for(j=0;j<q;j++)
            for(k=0;k<m;k++)
            c[i][j]+=a[i][k]*b[k][j];
            System.out.println("The product matrix is");
            for(i=0;i<m;i++) {
                for(j=0;j<q;j++) {
                    System.out.print(c[i][j]+"\t");
                }
                System.out.println();
            }
        }
    }
}