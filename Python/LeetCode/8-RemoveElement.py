class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        i = 0
        flag = 0
        k=len(nums)
        while(i<len(nums)):
            if(nums[i]==val):
                nums.pop(i)
                flag+=1
            else:
                i+=1
            print(nums)
        print(nums,k-flag)
        return k-flag
    
s = Solution()
s.removeElement([0,1,2,2,3,0,4,2],2)