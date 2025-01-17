from car import Car

car1=Car("Chevy","Corvette","2021","Blue")
car2=Car("Ford","Mustang","2022","Black")

print(car1.make)
print(car1.model)
print(car1.year)
print(car1.color)

print(car2.model)

car2.drive()
car1.stop() 

# Car.wheels=2 # this changes the value of the wheel class variable ie, affects all instances
 
print(car1.wheels)

car2.wheels=2 # we  can change the value of class variable
print(car2.wheels)

print(Car.wheels) # another way to access a class variable