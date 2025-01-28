# Odd Even Function
def OddEven(num):
    if(num % 2 == 0):
        return 'Even'
    else:
        return 'Odd'
    
print(OddEven(10))

# ----------------------------
def isPalindrome(str):
    # rev = str[::-1]
    rev = ''
    for i in str:
        rev = i + rev
    if(str == rev):
        return True
    else:
        return False
    
print(isPalindrome('amma'))

# ------------------------------

def readMat():
    r = int(input('Enter no. of rows'))
    c = int(input('Enter no. of cols'))
    mat = []
    for i in range(0,r):
        row = []
        for j in range(0,c):
            x = int(input("Enter elements"))
            row.insert(j,x)
        mat.insert(i,row)
    return mat

print(readMat())        