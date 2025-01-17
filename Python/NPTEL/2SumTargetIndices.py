#Given an array of integers nums and an integer target,
#return indices of the two numbers such that they add up to target.
a=[]
n=int(input("Enter the size of the array"))
for i in range(n):
    elements=int(input())
    a.append(elements)
t=int(input("Enter the target"))
for i in range(n):
    for j in range(i+1,n):
        if(a[i]+a[j]==t):
            print([i,j])
            