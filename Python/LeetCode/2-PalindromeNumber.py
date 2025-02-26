class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        x = str(x)
        y = x[::-1]
        if(x == y):
            return True
        else:
            return False
        
s = Solution()
print(s.isPalindrome(121))