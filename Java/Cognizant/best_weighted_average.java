import java.util.Arrays;
public class best_weighted_average {
    public static void main(String[] args) {
        int[] score = {80,90,70,100};
        int[] weight = {1,2,1,3};

        int[] sortedWeight = Arrays.copyOf(weight,weight.length);
        Arrays.sort(sortedWeight);

        for(int i : sortedWeight) {
            System.out.println(i);
        }
        int w1 = sortedWeight[sortedWeight.length-1];
        int w2 = sortedWeight[sortedWeight.length-2];

        int fi = indexOf(weight,w1);
        int si = indexOf(weight,w2);
        // System.out.println(fi + " " +si);

        int fmax = score[fi];
        int smax = score[si];

        double weighted_average = ((w1*fmax) + (w2*smax))/(w1+w2);
        System.out.println(weighted_average);
    }
    static int indexOf(int[] arr, int target) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == target) return i;
        }
        return -1; // not found
    }
}
