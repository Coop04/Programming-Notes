import os

path = "D:\\Documents\\Programming\\Python\\text.txt" # change \ to \\ (they are escape sequence for \ within a string)
if os.path.exists(path): # this will not tell if it is a file or not
    print("That location exists") 
    if os.path.isfile(path):
        print("That is a file") # this will tell if it is a file or not
else:
    print("That location does not exist")

path2 = "D:\\Documents\\Programming\\Python\\New folder"
if os.path.exists(path2):
    print("That location exists")
    if os.path.isfile(path2):
        print("That is a file")
    elif os.path.isdir(path2):
        print("That is a directory")
else:
    print("That location does not exist")