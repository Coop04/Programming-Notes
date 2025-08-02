import turtle

t = turtle.Turtle()
t.speed(10)

t.color('orange','yellow')

t.begin_fill()
for i in range(50):
    t.forward(200)
    t.left(170)
t.end_fill()

turtle.done()