alpha = ['A','B','C','D']

for i in range(len(alpha)+1):
    for j in range(i):
        print(alpha[j],end=' ')
    print()
