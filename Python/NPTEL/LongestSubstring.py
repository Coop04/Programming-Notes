#Given a string s, find the length of the longest substring
#without repeating characters.
a=[]
a=input("Enter a string: ")
l=len(a)
p=0
for i in range(l):
    if(a[i]!=a[i+1]):
        p+=1
    else:
        break
print(p+1)