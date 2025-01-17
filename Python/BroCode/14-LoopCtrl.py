# break = used to terminate loop entirely
# continue = skips to the next iteration of the loop
# pass = does nothing, used as a placeholder when a statement is required syntactically but not written

while True:
    name=input("Enter your name: ")
    if name!="":
        break

phone_no = "123-456-7890"
for i in phone_no:
    if(i == "-"):
        continue
    print(i,end="")

print()

for i in range(1,21):
    if i == 13:
        pass
    else:
        print(i,end=" ")