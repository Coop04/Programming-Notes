import turtle,math

t = turtle.Turtle()
t.speed(10)

t.color('orange','yellow')

t.begin_fill()
for i in range(500):
    t.forward(math.sqrt(i))
    t.left(i%180)
t.end_fill()

turtle.done()