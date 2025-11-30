/*
You are given an integer array A consisting of N non-negative and negative numbers.
A segment is defined as a contiguous subarray where all elements are either 
non-negative (positive or zero) or strictly negative.

Each time the array switches between non-negative and negative values, 
a new segment begins.

Your task is to find and return the total number of such segments
formed in the array.

Note: The number 0 is considered part of the non-negative segment.

Input Specification:
input1: An integer value N representing the number of elements.
input2: An integer array A.

Output Specification:
Return an integer value representing the total number of segments 
formed in array A.

Example:
A = [1, 0, -3, -4, 5, 6, -7]
Output: 4
*/


public class contiguous_neg_nonneg {
    public static void main(String[] args) {
        int[] a = {1,0,-3,-4,5,6,-7};
        int n = a.length;
        int count = 0;

        if(n<2) {
            count = 1;
            return;
        }
        for(int i=1;i<n;i++) {
            boolean prev = a[i-1]>=0;
            boolean current = a[i]>=0;
            if(prev!=current) {
                count++;
            }
        }
        count++; // edge case
    
        System.out.println(count);
    }
}