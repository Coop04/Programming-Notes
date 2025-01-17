# strings
first_name="Aswanth"
last_name="Satheesan"
full_name=first_name+" "+last_name
print(first_name)
print("Hello "+first_name)
print(type(first_name)) #gives the type of variable
print(full_name)

num = 10
print(f'Ben {num}') # this method is called formatting check 28th pgm


# integer
age=21
new_age=age+1
# age+=1 and print age
print(age)
print(new_age)
print(type(age))
# print("Hello I'm" + age) #won't work
print("Hello I'm "+str(age)) #works (type casting)


# float
pi=3.14
print(pi)
print(type(pi))
# print("Hello I'm" + pi) #won't work
print("Value of pi is "+str(pi)) #works (type casting)


# boolean
human=True
print(human)
print(type(human))
print("Are you a human: "+ str(human))