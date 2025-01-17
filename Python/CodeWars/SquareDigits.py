# Welcome. In this kata, you are asked to square every digit of a number and concatenate them.

# For example, if we run 9119 through the function, 811181 will come out, because 92 is 81 and 12 is 1. (81-1-1-81)

# Example #2: An input of 765 will/should return 493625 because 72 is 49, 62 is 36, and 52 is 25. (49-36-25)

# Note: The function accepts an integer and returns an integer.

def square_digits(num):
    # Your code here
    list=[]
    if(num==0):
        return 0
    while (num!=0):
        rem=(num%10)
        sq = rem**2
        list.append(sq)
        num=num//10
    list.reverse()
    sum=''
    for i in list:
        sum+=str(i)
    return int(sum)

# or

def squ(num):
    val=str(num)
    a=''
    for i in val:
        a+=str(int(i)**2)
    return int(a)

print(square_digits(9119))
print(square_digits(0))
print(squ(9119))
print(squ(0))