public class _34_array_search {
    public static void main(String[] args) {
        int[] numbers = {1,9,2,8,3,5,4};
        int target = 2;
        int flag = 0;
        int index = -1; // Java requires that a variable must be initialized before use.
                        // If the loop never finds the element, index would remain unassigned → compile-time error.

        for(int i=0; i<numbers.length;i++) {
            if(target==numbers[i]) {  // in case we are searching in a string array we should use equals() instead of == (since sting is a reference datatype)
                flag=1;
                index = i;
                break;
            }
        }
        if(flag==1) {
            System.out.println("element found at index: "+index);
        }
        else {
            System.out.println("element not found><");
        }
    }
}
