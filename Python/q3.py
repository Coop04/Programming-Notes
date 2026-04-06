def iter(mat,t):
    source = -1
    temp = t
    for i in range(3):
        for j in range(3):
            if mat[i][j] == 0:
                source = 0
                p = i
                q = j
                break
    if source == -1:
        return mat
    else:
        mat[p][q]=-1
    print(p,q)
    while temp>0:
        if p-1>=0:
            mat[p-1][q] -=1
            if mat[p-1][q]<0:
                mat[p-1][q] = -1
        if p+1<3:
            mat[p+1][q] -=1
            if mat[p+1][q]<0:
                mat[p+1][q] = -1
        if q-1>=0:
            mat[p][q-1] -=1
            if mat[p][q-1]<0:
                mat[p][q-1] = -1
        if q+1<3:
            mat[p][q+1] -=1
            if mat[p][q+1]<0:
                mat[p][q+1] = -1
        temp-=1
    # print(mat)
    mat = iter(mat,t)
    return mat
# ----------------------
mat1 = [[5,9,9],
       [9,0,9],
       [9,9,9]]
mat2 = [[5,9,9],
       [9,0,9],
       [9,2,9]]
mat2 = [[0,3,0],
       [4,5,6],
       [7,8,9]]
mat = iter(mat2,1)
# print(mat)
for i in range(3):
    for j in range(3):
        if mat[i][j]==-1:
            mat[i][j]=0
print(mat)

