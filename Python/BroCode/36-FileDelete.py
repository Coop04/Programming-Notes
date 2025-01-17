import os
import shutil
path = "D:\\Documents\\Programming\\Python\\delete.txt"
path1 = "D:\\Documents\\Programming\\Python\\New folder"

# try:
#     os.remove(path)
# except FileNotFoundError:
#     print("The file does not exist")

# to delete empty folder that does not contains any files

try:
    # os.rmdir(path1) # remove directory
    shutil.rmtree(path1) # remove directory and all its contents (dangerous)
except FileNotFoundError:
    print("The file does not exist")
except PermissionError:
    print("You do not have permission to delete the folder")
except OSError:
    print("The folder is not empty,you cannot delete this using this function")
else:
    print("Folder deleted successfully")

# to delete folders which are not empty

