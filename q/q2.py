def uniqueSum(lst):
    l = []
    new = []
    for i in range(len(lst)):
        if lst[i] not in l:
            l.append(lst[i])
        new.append(sum(l))
    return new

l1 = [2,2,3,3,2,4]
l2 = [-1,-1,-2,-1]
print(uniqueSum(l2))