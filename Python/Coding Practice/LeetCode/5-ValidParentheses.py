class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = list(s)
        # dict = {'(':')', '[':']', '{':'}'}
        dict = {')':'(', ']':'[', '}':'{'}
        i=0
        while(i<len(stack)):
            j=i-1
            if(len(stack)<=1 or stack[0] in dict):
                return False
            if stack[i] in dict:
                if(j>=0 and stack[j]!=dict[stack[i]]):
                    return False
                else:
                    if(i>0):
                        del stack[i]
                        del stack[j]
                        i = max(0, i - 1) # for maintaining th index after deleting 2 elements
            else:
                i+=1
            if(stack == []):
                return True
        return False
            
g = Solution()
print(g.isValid('[(]'))