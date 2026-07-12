# Given an sorted array arr[] of integers. Sort the array into a wave-like array(In Place). In other words, arrange the elements into a sequence such that arr[1] >= arr[2] <= arr[3] >= arr[4] <= arr[5] ..... and so on. If there are multiple solutions, find the lexicographically smallest one.

# Note: The given array is sorted in ascending order, and modify the given array in-place without returning a new array.

# Input: arr[] = [1, 2, 3, 4, 5]
# Output: [2, 1, 4, 3, 5]
# Explanation: Array elements after sorting it in the waveform are 2, 1, 4, 3, 5.

# Input: arr[] = [2, 4, 7, 8, 9, 10]
# Output: [4, 2, 8, 7, 10, 9]
# Explanation: Array elements after sorting it in the waveform are 4, 2, 8, 7, 10, 9.

# Input: arr[] = [1]
# Output: [1]

class Solution:
    def sortInWave(self, arr):
        # code here
        i=0
        if len(arr) <= 1:
            return arr
        else:
            while(i+1<=len(arr)-1):
                if arr[i]>arr[i+1]:
                    i+=1
                else:
                    arr[i],arr[i+1]=arr[i+1],arr[i]
                    i+=2
        # print(arr)
        return arr

s = Solution()
print(s.sortInWave([1,2,3,4,5]))