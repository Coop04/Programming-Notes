#Multiplication table upto 10
for i in range(1,11):
    for j in range(1,11):
        print(i*j,'\t',end='') #Here end='' helps in printing the i*j with a tab continuously,instead of printing it in seperate lines.
    print('\n')

#For a particular table
def Table(a):
    #a=input("Enter the number ")
    a=int(a)
    for i in range(1,11):
        print(a,"X",i,"=",a*i)

Table(10)