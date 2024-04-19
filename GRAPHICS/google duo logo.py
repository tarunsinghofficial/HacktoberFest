# google duo logo
import turtle
t=turtle.Turtle()
t.speed(100)
t.hideturtle()
s=turtle.Screen()
s.bgcolor("black")
def shape(length,radius,breadth):
    for i in range(2):
        t.forward(length)
        t.circle(-radius,90)
        t.forward(breadth)
        t.circle(-radius,90)


t.begin_fill()
t.color("medium blue")
t.circle(100)
t.end_fill()
t.penup()
t.color("ghost white")
t.left(90)
t.forward(55)
t.left(90)
t.backward(15)
t.pendown()
t.begin_fill()
shape(60,20,40)
t.end_fill()
t.right(180)
t.circle(20,90)
t.forward(30)
###
t.begin_fill()
t.right(50)
t.forward(40)
t.right(130)
t.forward(70)
t.right(130)
t.forward(40)
t.end_fill()
turtle.exitonclick()

