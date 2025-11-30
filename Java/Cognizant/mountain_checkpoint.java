// import java.util.ArrayList;
// import java.util.Arrays;
// public class mountain_checkpoint {
//     public static void main(String[] args) {
//         int n = 7;
//         int[] checkpoint = {5,1,2,3,4,3,2,1,6,7};
//         peakFinder(n, checkpoint);

//     }
//     static void peakFinder(int n, int[] a) {
//         ArrayList<Integer> list = new ArrayList<>();
//         ArrayList<Integer> mount = new ArrayList<>();
//         for(int i:a) {
//             list.add(i);
//         }
//         System.out.println(list);

//         int i = 0;
//         int iflag = 1;
//         int dflag = 0;
//         while(list.get(i)!=1) {
//             i++;
//         }
//         int low = list.get(i);
//         mount.add(low);
//         int k = i+1;
//         while(k<list.size() && list.get(k)!=list.get(low)) {
//             if((list.get(k) == list.get(i)+1) && iflag==1 && dflag == 0) {
//                 mount.add(list.get(k));
//             }
//             else if(list.get(k) == list.get(i)-1) {
//                 iflag=0;
//                 dflag=1;
//                 if(dflag==1)
//                     mount.add(list.get(k));
//             }
//             else {
//                 break;
//             }
//             i++;
//             k = i+1;
//         }
//         mount.add(list.get(k));
//         System.out.println(mount);
//         int cost = 0;
//         for(int c:mount) {
//             cost+=c;
//         }
//         System.out.println(cost);

//     }
// }

// ------------------------------------------------

import java.util.ArrayList;

public class mountain_checkpoint {
    public static void main(String[] args) {
        int[] checkpoint1 = {1, 2, 3, 4, 3, 2, 1};
        int[] checkpoint2 = {5, 1, 2, 3, 2, 1, 6, 7};

        System.out.println(peakFinder(checkpoint1.length, checkpoint1)); // 16
        System.out.println(peakFinder(checkpoint2.length, checkpoint2)); // 9
    }

    static int peakFinder(int n, int[] a) {
        ArrayList<Integer> list = new ArrayList<>();
        for (int x : a) {
            list.add(x);
        }

        int maxSum = 0;

        // try each index as a possible START of a mountain
        for (int start = 0; start < n; start++) {

            int i = start;

            // move while strictly increasing
            while (i + 1 < n && list.get(i + 1) > list.get(i)) {
                i++;
            }

            int peak = i;

            // need at least one increasing step and one decreasing step
            if (peak == start || peak == n - 1) {
                continue; // not a proper mountain
            }

            // move while strictly decreasing
            while (i + 1 < n && list.get(i + 1) < list.get(i)) {
                i++;
            }

            int end = i;

            // compute sum from start to end
            int sum = 0;
            for (int j = start; j <= end; j++) {
                sum += list.get(j);
            }

            if (sum > maxSum) {
                maxSum = sum;
            }
        }

        return maxSum;
    }
}
