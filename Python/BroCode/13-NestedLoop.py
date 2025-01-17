rows=int(input("Enter Rows: "))
cols=int(input("Enter Columnss: "))
sym=input("Enter a symbol to use: ")

for i in range(rows):
    for j in range(cols):
        print(sym,end="") #end="" is to prevent cursor from going to next line
    print() #for next line or print("\n") can be used