# copyfile() = copies conents of a file
# copy() = copiefile() + permission mode + destination can be a directory
# copy2() = copy() + copy metadata (file's creation and modification time)

import shutil
shutil.copyfile("D:\\Documents\\Programming\\Python\\text.txt","D:\\Documents\\Programming\\Python\\copy.txt")