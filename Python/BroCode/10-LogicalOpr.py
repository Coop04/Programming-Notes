# Logical operators (and,or,not)

temp=int(input("What is the temperature?:"))
if not(temp>=0 and temp<=30):
    print("It's bad out there")
elif not(temp < 0 or temp >30):
    print("It is a nice day")
    print("Go out")