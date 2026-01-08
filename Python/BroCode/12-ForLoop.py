import time
for i in range(10):
    print(i+1)

# for i in range(50,100 +1,2):
#     print(i)

# for i in "Aswanth Satheesan":
#     print(i)

# to revese iterate a string
s = "Aswanth"
for ch in range(len(s)-1,-1,-1):
    print(s[ch],end="")

print()

for ch in s[::-1]:
    print(ch,end="")

print()

for seconds in range(10,0,-1):
    print(seconds,end=" ")
    time.sleep(1)
print("\nHappy New Year!!!")

a=[3,5]
b=0
for i in a: # for loop in python is different from for loop in c since here i does not take the value of index like in c, instead it assumes the value of item inside the list (when range is not used in for loop)
    print (i)
    # print(a[i]) # this does not work