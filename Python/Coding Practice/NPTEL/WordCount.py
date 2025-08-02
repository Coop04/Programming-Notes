para=input("Enter a string")
n=int(input("Enter a no."))
j=i=0
temp=0
words=para.split()
for i in words:
    for j in words:
        if i==j:
            temp=temp+1
    if temp==n:
        break
    temp=0
if temp==n:
  print(1,end="")
else:
  print(0,end="")