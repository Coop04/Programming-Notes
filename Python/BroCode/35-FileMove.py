import os

source = "D:\\Documents\\Programming\\Python\\move.txt" # to move folder replace text name with folder
destination = "D:\\Documents\\Programming\\Python\\BroCode\\move.txt"

try:
    if os.path.exists(destination): # checks if the file has already been moved
        print("There is already a file there")
    else:
        os.replace(source,destination) # moving the file
        print(source + " was moved")
except FileNotFoundError:
    print(source+" was not found")