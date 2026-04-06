def belt(l,t):
    while t>0:
        idx = []
        for i in range(len(l)):
            if l[i]=='R':
                idx.append(i)
        print(idx)
        k = 0
        for i in idx:
            if l[(i+1)%len(l)] == '.':
                l[i],l[(i+1)%len(l)] = '.','R'
                # print(l)
        t-=1
    return l

l1 = ['R','.','.','#','.','.','R','.']
l2 = ['.','R','.','.']
l3 = ['R','.','.','.']
l4 = ['R','.','R','.']
print(belt(l1,3))