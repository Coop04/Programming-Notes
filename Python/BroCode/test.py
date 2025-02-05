# for i in range(1,5):
#     for j in range(1,6-i):
#         print(j,end='')
#     print()

# # --------------------------
# import math
# n = int(input('enter range: '))
# x = int(input('enter x: '))
# x = math.radians(x)

# def fact(a):
#     if (a==0):
#         return 1
#     else:
#         return a * fact(a-1)

# def sin(x,n):
#     flag = 0
#     val = 0
#     for i in range(1,(2*n)+1,2):
#         flag = flag + 1
#         if(flag%2==0):
#             val -= ((x**i)/fact(i))
#         else:
#             val += ((x**i)/fact(i))
#     return val

# print(sin(x,n))

# # -------------------------------------
# m = int(input('enter lower range: '))
# n = int(input('enter upper range: '))

# def composite(m,n):
#     comp = []
#     for i in range(m,n):
#         flag = 0
#         for j in range (2,i):
#             if(i%j==0):
#                 flag +=1
#         if(flag>0):
#             comp.append(i)
#     return comp

# # ----------------------------

# def rev(str):
#     reversed = ''
#     for i in str:
#         reversed = i + reversed
#     return reversed

# print(rev('apro'))

# # ------------------------------

# def isPrime(num):
#     flag = 0
#     for i in range(2,num):
#         if(num%i==0):
#             flag += 1
#     if(flag>0):
#         return False
#     else:
#         return True

# print(isPrime(9))

# # --------------------------

# s = 'programming'
# print(s.count('r',2,5))
# print(s.find('r',2,5))
# print(s.replace('r','z'))

# # -----------------------------

# def readMat():
#     m = int(input('enter no. of rows: '))
#     n = int(input('enter no. of cols: '))
#     mat = []
#     for i in range(m):
#         row = []
#         for j in range(n):
#             k = int(input('enter the values: '))
#             row.insert(j,k)
#         mat.insert(i,row)
#     return mat

# a1 = readMat()
# print(a1)

# # -----------------------------------------
 
# a = readMat()
# b = readMat()

# def sumMat(a,b):
#     mat = []

# # # -------------------------------

# l = [1,2,3,4]
# if(4 not in l):
#     print(True)
# else:
#     print(False)

# --------------------------------

# dict = {
#     'pal':'java',
#     'Kal':'Python',
#     'sal':'C'
# }

# del dict['pal']

# print(dict.items())

# print(dict.key('sal'))
# --------------------------

# def isPalindrome(str):
#     rev = ''
#     for i in str:
#         rev = i + rev
#     if(str == rev):
#         return True
#     else:
#         return False

# print(isPalindrome('appo'))

# -----------------------------

# cube = lambda y: y*y*y
# print(cube(2))

# print(f'This is the cube of 2: {cube(2)}')
# # -----------------------

# l = 'pop,pu'
# print(l.split(','))

# # ------------------------
# a = 5
# print(a<<1)

# ----------------------

# def power(num,x):
#     if(x==0):
#         return 1
#     else:
#         return num*power(num,x-1)

# print(power(2,3))

# ------------------------

alpha = ['A','B','C','D']

for i in range(len(alpha)+1):
    for j in range(i):
        print(alpha[j],end=' ')
    print()

# -------------------------------