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
    while j<=len(s):
        # print(i,j)
        # if j==len(s):
        #     ss = "".join(lst)
        #     st += ss
        if j<len(s) and j-i != k:
            lst.append(s[j])
            j+=1
            # print(lst)
        
        else:
            if k<len(s):
                x = lst.pop(k-1)
                # print(x)
                lst.insert(0,x)
                print(lst)
                ss = "".join(lst)

                lst[:] = []
                # print(s)
                i = j
                st = st + ss
                print(st)
                ss = ""
    return st

s1 = "abcdefghi"
s = "xyzaabbcc"
s = "hello"
s = "a"
print(rotConcat(s1,5))