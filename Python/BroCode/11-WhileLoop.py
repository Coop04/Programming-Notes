# while 1==1:
#     print("Bug Detected")   #infinite loop

name=""
while len(name) == 0: #while not name: (this works because an empty string is falsy("", 0, None, False) and a non empty string is truthy)
    name = input("Enter your name: ")

print("Hello "+ name)