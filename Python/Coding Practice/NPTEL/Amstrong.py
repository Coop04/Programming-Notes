a=input("Enter a number")
a=int(a)
org=a
p=0
sum=0
while(a!=0):
    rem=a%10
    p=p+1
    a=a//10 #Here // operator performs integer devision
a=org
while(a!=0):
    rem=a%10
    sum+=rem**p
    a=a//10 #Here // operator performs integer devision
if(sum==org):
    print(org,"is an amstrong number")
else:
    print(org,"is not an amstrong number")
