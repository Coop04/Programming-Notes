public class _35_varargs {
    public static void main(String[] args) {
        // varargs = variable arguements
        //           allows a method to accept varying number of arguements
        //           makes methods more flexible, no need for overloaded methods
        //           java will pack the arguements into an array
        //           ...(ellipsis)

        System.out.println(add(1,2,3,4,5));
        System.out.println(avg(1,2,3,4,5));
    }
    static int add(int...numbers) { // here numbers (can give any name) is the name of the array we use here (since java packs the args into an array)
        int sum = 0;
        for(int i:numbers) {
            sum += i;
        }
        return sum;
    } 

    static double avg(int...nums) {
        double avg = 0;
        for(int i:nums) {
            avg += i;
        }
        avg /= nums.length;
        return avg;
    }
}
