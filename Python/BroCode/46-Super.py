# super() = function used to give access to the methods of a parent class
            # returns a temporary object of a parent class when used

# super() is used so we don't need to rewrite the contents of the parent class's constructor inside the child class; it allows us to directly call and reuse the parent constructor.

# super() is used to access or call methods from the parent, NOT TO INHERIT THEM.

# What super() actually does is allow you to call the parent method (like __init__) without hardcoding the parent class name, which is useful especially in multiple inheritance.

# The super() function in Python is used to call a method (like a constructor) from the parent class, without needing to refer to the parent class name directly. It is especially useful when working with multiple inheritance, as it follows the method resolution order (MRO) to determine which method to call next.

class Rectangle:

    def __init__(self, length, width):
        self.length = length # instance variable
        self.width = width   # instance variable

class Square(Rectangle):

    def __init__(self, length, width):
        super().__init__(length,width)

    def area(self):
        return self.length*self.width

class Cube(Rectangle):

    def __init__(self, length, width, height):
        super().__init__(length,width)
        self.height = height

    def volume(self):
        return self.length*self.width*self.height

square = Square(3, 3)
cube = Cube(3, 3, 3)

print(square.area())
print(cube.volume())