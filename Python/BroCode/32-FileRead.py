# using with open ,this automatically closes the file too however does not catch any exceptions
with open("D:\\Documents\\Programming\\Python\\text.txt") as file:# if file is in the same directory only name will be enough
    print(file.read())

# to check if the file is closed 
print(file.closed)

print()

try: # to handle exceptions
    with open("D:\\Documents\\Programming\\Python\\text.tx") as file2: # causes an error(since wrong exception)
        print(file2.read()) 
except FileNotFoundError:
    print("File not found")
    