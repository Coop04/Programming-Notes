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

# print(list(dict.keys()))
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
# words = l.split(',')
# print(words)
# print('     '.join(words))

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

# alpha = ['A','B','C','D']

# for i in range(len(alpha)+1):
#     for j in range(i):
#         print(alpha[j],end=' ')
#     print()

# -------------------------------

# num = int('ab')
# print(num)

#--------------------------------

# import os
# print(os.name)

# import sys
# print(sys.argv)
# -------------------------------
# import cmath
# a= int(input("Enter a"))
# if(a==0):
#     print("This is not a qe ")
# b= int(input("Enter b"))
# c= int(input('Enter c'))
# des = cmath.sqrt(b**2-(4*a*c))
# r1 = (-b + des) / (2*a)
# r2 = (-b - des) / (2*a)
# print(f'the roots are {r1} and {r2}')

# ------------------------------------

# a = input('Enter a no.')
# l = len(a)
# sum = 0
# for i in a:
#     sum+=int(i)**l
# if(sum==int(a)):
#     print('Amstrong')
# else:
#     print("Not")
# ----------------------------------

# u = int(input("upper limit: "))
# l = int(input('lower limit: '))
# for i in range(l,u+1):
#     if(i%2!=0):
#         print(i)

# ---------------------------------

# def fact(n):
#     if(n==0):
#         return 1
#     else:
#         return(n*fact(n-1))
    
# limit = int(input('Enter the limit'))
# x = int(input('Enter the value of x'))

# sum=0
# for i in range(0,limit):
#     sum+=(x**i)/fact(i)
# print(f'Sum of {limit} terms = {sum}')

# -----------------------------------------

# with open('file1.txt','r') as f:
#     count=0
#     for i in f:
#         line = i.strip()
#         words = line.split(' ')
#         for j in words:
#             if(len(j)==4):
#                 count+=1
#             else:
#                 continue
# print(count)

# ----------------------------------

# import math
# nums = []
# n = int(input('Enter no.of nums'))
# print('The numbers are: ')
# for i in range(n):
#     k = int(input())
#     nums.append(k)

# def mean(nums):
#     sum = 0
#     for i in nums:
#         sum+=i
#     return sum/len(nums)

# def median(nums):
#     nums.sort()
#     if(len(nums)%2==0):
#         return (nums[len(nums)//2]+nums[(len(nums)//2)-1])/2
#     else:
#         return nums[(len(nums)//2)]
    
# def mode(nums):
#     a = list(set(nums))
#     d = {}
#     for i in a:
#         d[i] = nums.count(i)
#     return max(d.values())

# print(mean(nums), median(nums), mode(nums))

# ------------------------------------------------

# def contains_sublist(main_list, sub_list):
#     n = len(sub_list)
#     for i in range(len(main_list) - n + 1):
#         if main_list[i:i+n] == sub_list:
#             return True
#     return False

# ----------------------------------------------

# import turtle

# t = turtle.Turtle()
# # t.color('black','red')
# t.pencolor('black')
# t.fillcolor('yellow')
# t.begin_fill()
# for i in range(5):
#     t.forward(100)
#     t.left(144)
# t.end_fill()

# turtle.done()

# -----------------------------

# class Rectangle:
#     def __init__(self,length,breadth):
#         self.length = length
#         self.breadth = breadth
#     def area(self):
#         return self.length*self.breadth
#     def peri(self):
#         return 2*(self.length+self.breadth)
    
# r = Rectangle(10,20)
# print(r.area(),r.peri())

# -----------------------------------------

# class Student:
#     def __init__(self,name,roll):
#         self.name=name
#         self.roll=roll
#         self.age=None
#         self.marks=None
    
#     def setAge(self,age):
#         self.age = age

#     def setMarks(self,marks):
#         self.marks = marks
    
#     def display(self):
#         if self.age is not None and self.marks is not None:
#             print(f"Name: {self.name}, Roll: {self.roll}, Age: {self.age}, Marks: {self.marks}")
#         else:
#             print("Age or Marks not set.")
    
# s = Student('Anu',11)
# # s.setAge(19)
# # s.setMarks(33)
# print(s.display())

# ----------------------------------------------------

# import numpy as np
# a= np.array([[1,2,3],[4,5,6],[7,8,9]])
# print(a)

# print(a[:2])
# print(a[:2,:1])
# print(a[1,:2]) 
# a[:2,1:]=0
# print(a) 

# ---------------------------------------

# toppers = {'regNo.':['a','b','c'],
#            'name':['anu','binu','jinu'],
#            'sem':[3,4,5],
#            'cgpa':[9,9.8,9.9]}

# import pandas as pd

# df = pd.DataFrame(toppers)
# print(df)

# print(df.shape)
# print()
# print(df.head())

# --------------------------------

# import pandas as pd
# from pylab import *

# df = pd.read_csv('toppers.csv',index_col='regNo.')
# print(df)

# plot(df['sem'],df['cgpa'],'r.--',label='sem x cgpa')
# title('Toppers')
# xlabel('sem')
# ylabel('cgpa')
# legend()
# grid()
# show()

# ------------------------------------------------

# def fact(n):
#     if(n==0):
#         return 1
#     else:
#         return(n*fact(n-1))
    
# limit = int(input('Enter the limit'))
# x = int(input('Enter the value of x'))

# sum=0
# for i in range(0,limit):
#     if(i%2==0):
#         sum+=(x**i)/fact(i)
#     else:
#         sum-=(x**i)/fact(i)
# print(f'Sum of {limit} terms = {sum}')
# ---------------------------------------------

# def power(x,y):
#     p=1
#     for i in range(0,y):
#         p *= x 
#     return p

# print(power(3,3))

# -----------------------------------

# l = [-1,-3,4,5,-6,2,0,-4]

# pos = lambda x: True if x>0 else False
# # print(pos(1))
# l1 = list(filter(pos,l))
# print(l)
# print(l1)

# --------------------------------

# import turtle 

# t = turtle.Turtle()
# t.color('black','yellow')
# t.begin_fill()
# t.circle(100)
# t.end_fill()

# turtle.done()

# ---------------------------------

# class Complex:
#     def __init__(self,real,imag):
#         self.real = real
#         self.imag = imag
    
#     def __add__(self,other):
#         return (self.real+other.real,self.imag+other.imag)
    
#     def __mul__(self,other):
#          return (self.real*other.real,self.imag*other.imag)
    
# c = Complex(1,2)
# p = Complex(3,4)
# print(c+p)
# print(c*p)

# -------------------------------------------

# from math import gcd

# class Rational:
#     def __init__(self, numerator, denominator):
#         if denominator == 0:
#             raise ValueError("Denominator cannot be zero.")
#         self.numerator = numerator
#         self.denominator = denominator
#         self.reduce()  # Automatically reduce the fraction upon initialization

#     def reduce(self):
#         """Simplify the fraction."""
#         common_divisor = gcd(self.numerator, self.denominator)
#         self.numerator //= common_divisor
#         self.denominator //= common_divisor
#         return self

#     def __add__(self, other):
#         """Add two rational numbers."""
#         if not isinstance(other, Rational):
#             raise TypeError("Can only add Rational numbers.")
#         new_numerator = self.numerator * other.denominator + other.numerator * self.denominator
#         new_denominator = self.denominator * other.denominator
#         return Rational(new_numerator, new_denominator).reduce()

#     def __lt__(self, other):
#         """Compare two rational numbers (less than)."""
#         if not isinstance(other, Rational):
#             raise TypeError("Can only compare Rational numbers.")
#         return self.numerator * other.denominator < other.numerator * self.denominator

#     def __str__(self):
#         """String representation of the rational number."""
#         return f"{self.numerator}/{self.denominator}"


# # Example Usage
# r1 = Rational(3, 4)
# r2 = Rational(2, 6)

# print("Rational 1:", r1)
# print("Rational 2:", r2)

# # Simplify fractions
# print("Simplified Rational 1:", r1.reduce())
# print("Simplified Rational 2:", r2.reduce())

# # Add two rational numbers
# r3 = r1 + r2
# print("Sum of Rational 1 and Rational 2:", r3)

# # Compare two rational numbers
# print("Is Rational 1 less than Rational 2?", r1 < r2)

# =================================================

# try:
#     with open('file2.tx','w') as f:
#         f.write('Hello Good Morning')
# except FileNotFoundError as e:
#     print(e)
# except PermissionError as e:
#     print(e)
# except IOError as e:
#     print(e)
# finally:
#     print('File ops are completed')

# ---------------------------------------------

# import os 
# for items in os.listdir('.'):
#     print(items)

# -------------------------------------------

# import numpy as np
# a = np.random.randint(1,20,size=(3,3))
# print(a)
# b = np.random.randint(1,20,size=(3,3))
# print(b)

# print('sum:')
# print(a+b)
# print('product:')
# m = a@b
# print(m)
# print('transpose of product:')
# print(m.T)
# print('trace')
# print(np.trace(m))

# --------------------------------------

# def contains_sublist(main_list, sub_list):
#     n = len(sub_list)
#     for i in range(len(main_list) - n + 1):
#         if main_list[i:i+n] == sub_list:
#             return True
#     return False

# l = [1,2,3,4,5,6]
# s = [2,3]
# y = [2,4]
# print(contains_sublist(l,s))
# print(contains_sublist(l,y))

# ----------------------------------------

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

# a = readMat()
# b = readMat()
# print(a)
# import numpy as np
# a = np.array(a)
# b = np.array(b)
# print(a@b)

# --------------------------------------------
# a = "hello"
# b = "kitty"
# print(a+b)