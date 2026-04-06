def rotConcat(s,k):
    s = list(s)
    i = 0
    j = 0
    lst = []
    st = ""
    ss = ""
    if len(s)<k:
        stri = ""
        for i in s:
            stri +=i
        return stri
    while j<len(s):
        # print(i,j)
        if j<len(s) and j-i != k:
            lst.append(s[j])
            if j==len(s)-1: 
                ss = "".join(lst)
                st +=ss
                return st
            j+=1
            # print(lst)
        else:
            if lst:
                x = lst.pop(k-1)
                # print(x)
                lst.insert(0,x)
                # print(lst)
                ss = "".join(lst)

                lst[:] = []
                # print(s)
                i = j
                st = st + ss
                # print(st)
                ss = ""
    return st

s0 = "13241532"
s1 = "abcdefghi"
s2 = "xyzaabbcc"
s3 = "hello"
s4 = "a"
print(rotConcat(s2,2))