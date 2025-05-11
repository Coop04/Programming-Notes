import turtle,time

a = turtle.Turtle()

a.width(3) # to set thickness of the line

# a.pencolor('red') or
a.color('red')

a.forward(100)
a.left(45) # turns 45 degrees left
a.forward(100)
a.setheading(90) # helps to go east (0), north (90), west(180), south(270)
a.forward(100)

a.hideturtle() # to hide turtle cursor

print(a.position())
print(a.heading())
print(a.isdown())

time.sleep(3) # to wait 3 seconds
# a.clear() # to erase all the turtle drawings



turtle.done()