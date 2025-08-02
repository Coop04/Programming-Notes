import turtle

a = turtle.Turtle()

a.color('black','blue') # if only one value passed border color and fill color will be the same
# a.color('#3C9112')

a.begin_fill()
a.forward(100)
a.left(90)
a.forward(100)
a.left(90)
a.forward(100)
a.left(90)
a.forward(100)
a.end_fill()

a.up() # or a.penup()
a.forward(100)
a.down() # or a.pendown()

a.begin_fill()
a.forward(100)
a.left(90)
a.forward(100)
a.left(90)
a.forward(100)
a.left(90)
a.forward(100)
a.end_fill()

turtle.done()


