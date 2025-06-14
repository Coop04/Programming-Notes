# 2D lists = a list of lists

drinks = ["coffie","soda","tea"]
dinner = ["pizza","burger"]
dessert = ["cake","ice cream"]

food = [drinks,dinner,dessert]
print(food)
print(food[0]) #display zeroth list
print(food[1][1]) #from list 1 display 1st element

# ----------------------------------------

# reading a matrix

def readMat():
    m = int(input('enter no. of rows: '))
    n = int(input('enter no. of cols: '))
    mat = []
    for i in range(m):
        row = []
        for j in range(n):
            k = int(input('enter the values: '))
            row.insert(j,k)
        mat.insert(i,row)
    return mat

