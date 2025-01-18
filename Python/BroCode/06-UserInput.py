# input is always read as string, for performing ops we need to typecast
name=input("What is your name: ")
age=int(input("How old are you: "))
age+=1 #need to cast to int or float
height=float(input("what is your height: "))

print("Hello "+name)
print(age)
print("Your height is "+str(height))
print(f"Your height is {height}")