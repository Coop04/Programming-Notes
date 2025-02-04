# tuple = collection which is ordered and unchangeable
# used to group related data

student = ("Bro",21,"male")
teacher = 'Teach',32,'female','college' # can create a tupple without ()

print(student.count("Bro")) # only 1 Bro
print(student.index("male")) # index is 2

print (teacher.index('college')) # index is 3

for i in student:
    print(i)

if "Bro" in student:
    print("Bro is here")

print(teacher) # ('Teach', 32, 'female', 'college')