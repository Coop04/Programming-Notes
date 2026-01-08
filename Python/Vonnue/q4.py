# multiplication without repeated addition

num1 = 3
num2 = 7
temp = 0
while num2!=1:
    if num2&1 and num2!=1:  # num2 & 1 checks if the last bit is 1, if yes then its odd
        temp += num1
    num1 = num1<<1
    num2 = num2>>1
    print(num1,num2,temp)
num1+=temp
print(num1)