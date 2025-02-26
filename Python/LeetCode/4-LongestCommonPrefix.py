class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        k=0
        l = []
        num = len(strs)
        for index,i in enumerate(strs):
            flag = 1
            for j in strs[index+1::]:
                if(i[k]==j[k]):
                    flag+=1
                else:
                    break
                if(flag == num):
                    l.append(i[k])
            if(flag != num):
                break
            k+=1
        return l