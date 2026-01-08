s = "acdbuio"
def alternate(s):
    new = ""
    s = list(s)
    s.sort()
    vowels = ['a','e','i','o','u']
    v = []
    c = []
    for i in s:
        if i in vowels:
            v.append(i)
        else:
            c.append(i)
    print(v,c)
    if len(v) == len(c)+1 or len(c) == len(v)+1 or len(v)==len(c):
        if len(v) == len(c):
            if v[0]<c[0]:
                fir = v
                sec = c
            else:
                fir = c
                sec = v
        elif len(v)>len(c): 
            fir = v
            sec = c
        else: 
            fir = c
            sec = v
        i = 0
        j = 0
        while i<len(fir):
            new+=fir[i]
            i+=1
            if j<len(sec):
                new+=sec[j]
                j+=1
    else:
        return "IMPOSSIBLE"
    return new

print(alternate(s))