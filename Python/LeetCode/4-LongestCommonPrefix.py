class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        k=0
        num = len(strs)
        i = strs[0]
        temp = 0
        s=''
        while(k<(len(i))):
            flag = 1
            if not strs or "" in strs:
                return ""
            for j in strs[1::]:
                if(k<len(j)):
                    if(i[k]==j[k]):
                        flag+=1
                    else:
                        temp = 1
                        break
            if(flag == num and temp == 0):
                s+=i[k]
                k+=1
            else:
                break
        return s