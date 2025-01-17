# return statement = Functions send Python values/objects back to the caller.
# These values/objects are known as functions return value
# The return statement is optional. If it is not used, the function will return None by default

# def multiply(num1,num2):
#     result = num1 * num2
#     return result

# same as above
def multiply(num1,num2):
    return num1 * num2

print(multiply(4,9))

x=multiply(6,8)
print(x)