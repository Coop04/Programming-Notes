class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        flag = 0
        i = 0 
        while(i+1<len(nums)):
            if(nums[i]==nums[i+1]):
                nums[i]='_'
                i=i+1
                flag+=1
            else:
                i+=1
        nums.sort()
        print(nums)
        return len(nums)-flag
    
q = Solution()
print(q.removeDuplicates([1,1,2]))