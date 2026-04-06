def balanced(s):
    d = {}
    left = 0
    right = 0
    length = 0
    maxLen = 0
    s = list(s)
    print(s)
    for right in range(len(s)):
        if s[right] not in d:
            d[s[right]] = 1
        else:
            d[s[right]] += 1
        if 'A' in d and 'B' in d and 'C' in d:
            if (d['A'] == d['B']) and d['C']%2==0:
                length = right - left + 1
                maxLen = max(maxLen,length)
                # if d[s[left]] > 1:
                #     d[s[left]] -= 1
                # else:
                #     d.pop(s[left])
                # left+=1

        print(d,left,right,length)
        # print(length)
    return maxLen

s1 = "AABCBCBBC"
s2 = "ABCCBA"
s3 = "B"
s4 = "ABC"
print(balanced(s1))