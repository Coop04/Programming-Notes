import java.util.Scanner;
import java.util.Arrays;
class Fn {
    void binSearch(int x[],int y,int z) {
        int l=0,r=y-1,mid;
        while(l<=r) {
            mid=(l+r)/2;
            if(x[mid]==z) {
                System.out.println("Element "+z+" is found");
                break;
            }
            else if(x[mid]<z) {
                l=mid+1;
            }
            else {
                r=mid-1;
            }
        }
        if(l>r) {
            System.out.println("Element not found");
        }
    }
}
public class BinarySearch {
    public static void main(String args[]) {
        int i;
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the size of the array : ");
        int n=sc.nextInt();
        System.out.println("The elements are");
        int a[]=new int[n];
        for(i=0;i<n;i++)
        a[i]=sc.nextInt();
        System.out.println("Enter the elements to be searched : ");
        int key=sc.nextInt();
        Fn obj=new Fn();
        Arrays.sort(a);
        obj.binSearch(a,n,key);
    }
}