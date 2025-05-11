# exception = an event detected during execution that interrupt the flow of a program

try: # put the dangerous code inside try (cuz we dont know what user is going to type in)
    numerator = int(input("Enter a no. to devide: "))
    denominator = int(input("Enter a no. to divide by: "))
    result = numerator/denominator # when denominator is 0 ZeroDevisonError
    print(result)
except ZeroDivisionError as e: # to also see the error message use as e and then print e (optional)
    print("Error: Division by zero is not allowed")
    print(e)
except ValueError:
    print("Error: Invalid input. Please enter a valid number")
except Exception as e: # not a good practice to write only the Exception block (need to be specific first)
    print("An error occurred",e)
else:  # if no exception was raised else will be executed
    print(result)
finally: # always at end
    print("Finally:this will always run") # this will run even if there is an exception or not

# -----------------------------------------------------------------------------------

# We can reise exceptions using raise statement

try: 
    age = int(input("Enter the age:")) 
    if(age<18): 
        raise ValueError 
    else: 
        print("the age is valid") 
except ValueError: 
    print("The age is not valid")