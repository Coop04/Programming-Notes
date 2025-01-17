n=int(input("Enter size of the array"))
a=[];sum=0
print("The elements are")
for i in range(n):
    elements=int(input())
    a.append(elements)
print(a)
for i in range(n):
    sum=sum+a[i]
print(sum)