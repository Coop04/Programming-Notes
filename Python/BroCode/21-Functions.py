# function = a block of code which is executed when it is called

# python supports both functions and methods
# Tip to Memorize:
# Ask Yourself: "Does this operation belong to the object?"
# (ie, if it depends on the object type or the values inside the object. for example sum(list) it depend on the variables inside so it is a function & similarly append() is a feature related to list so it is a method)
# If yes: Use variable.method().
# If no: Use function(variable).

def hello(name):
    print("Hello! " + name)
    print("Have a nice day")

hello("Aswanth")

my_name="Bro"
hello(my_name)

def hello(fname,lname):  # the first function is being overridden by this fn. since they both have same names (regardless of the no. of arguments used)
    print("Hello! " + fname + " " + lname)
    print("Have a nice day")
hello("Aswanth","Satheesan")

# hello('Aswanth') # this will not work since this fn. was overridden by the fn. above

def age(years):
    print("You are " + str(years) + " years old")
    print(f"you are {years} years of age")

age(21)