text = "Yooooo\nThis is some text\n"
text1 = "Appending some text"
# by default there will be r in place of w also when w is used read r cannot be used in the same with open()
with open("D:\\Documents\\Programming\\Python\\text.txt","w") as file: # overwrites the exixsting text
    file.write(text)
with open("D:\\Documents\\Programming\\Python\\text.txt","a") as file: # appends with the exixsting text
    file.write(text1)
with open("D:\\Documents\\Programming\\Python\\text.txt") as file:
    print(file.read())
# with open("D:\\Documents\\Programming\\Python\\text.txt","w") as file:
    # print(file.read())                       # with 'w' we cannot read the file