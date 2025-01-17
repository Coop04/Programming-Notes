class Animal:
    def eat(self):   # combination of method name and its parameters is called its signature
        print("Eating...")

class Rabbit(Animal):
    def eat(self):
        print("Rabbit is eating...")
 
rabbit = Rabbit()
rabbit.eat()  # an object will use a method that is more closely associated with itself ie, rabbit uses the eat fn. in its class
