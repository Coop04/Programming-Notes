class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        l = []
        for i in range(len(nums)):
            j = i+1
            for j in range(len(nums)):
                if i+j == target:
                    l = [i,j]
                    return l


nums = [1,2,3,4,5]


    