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

# -----------------------------------

# class Solution(object):
#     def isPalindrome(self, x):
#         """
#         :type x: int
#         :rtype: bool
#         """
#         x = str(x)
#         l1 = []
#         l2 = []
#         for i in x:
#             l1.append(i)
#         for i in l1[::-1]:
#             l2.append(i)
#         if(l1 == l2):
#             return True
#         else:
#             return False
        
# s = Solution()
# print(s.isPalindrome(-121))