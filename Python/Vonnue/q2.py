l = [4,5,5,5,4,2,2,7]

d = {}
for i in l:
    if i not in d:
        d[i] = 1
    else:
        d[i] += 1
lst = []
for i in d:
    if d[i]==1 or d[i]==3:
        lst.append(i)
print(d)
print(lst)