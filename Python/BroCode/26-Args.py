# *args = parameter that will pack all the arguements into a tuple
# useful so that a function can accept a varying amount of arguements

# def add(num1,num2):
#     sum = num1 + num2
#     return sum

# print(add(1,2))        #cant add more arguements in fn call

def add(*arr):  # * is important the name can be anything
    sum=0
    arr=[1,4,6]
    for i in arr:
        sum +=i
    return sum

# print(add(1,2,5,7))  #this works (when no list is given)

print(add()) #this works if list is given

ar = [3,5,7,9]
def add2(*array):
    sum = 0
    for i in array:
        sum += i
    return sum

s=add2(*ar)
print(s)