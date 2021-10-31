#LCO logo
import turtle
t=turtle.Turtle()
s=turtle.Screen()
s.bgcolor("#9d65c9")
q=turtle.Turtle()
w=turtle.Turtle()
t.speed(10)
w.speed(10)
q.speed(10)
w.hideturtle()
t.hideturtle()
q.hideturtle()
#####
t.color("white")
t.begin_fill()
t.circle(100)
t.end_fill()
def square(length):
    for i in range(4):
        q.forward(length)
        q.right(90)

####
q.color("dark violet")
q.penup()
q.left(90)
q.forward(160)
q.left(90)
q.forward(60)
q.left(180)
q.pendown()
###
q.begin_fill()
square(120)
q.end_fill()
w.color("white")
w.penup()
w.left(90)
w.forward(145)
w.left(90)
w.forward(30)
w.pendown()
#######
def codeshape():
    w.begin_fill()
    w.circle(10,90)
    w.forward(25)
    w.circle(-10,90)
    w.circle(10,-90)
    w.backward(25)
    w.circle(-10,-90)

    w.backward(10)
    w.left(90)
    w.backward(5)
    w.right(90)

    #####
    w.circle(-10,90)
    w.forward(20)
    w.circle(10,90)
    w.circle(-10,-90)
    w.backward(20)
    w.circle(10,-90)
    w.right(90)
    w.forward(5)
    w.left(90)
    w.forward(10)
    w.end_fill()
  


codeshape()
w.right(180)
w.penup()
w.forward(60)
w.right(90)
w.forward(90)
w.left(90)
w.pendown()
codeshape()
w.penup()
w.backward(45)
w.left(90)
w.forward(25)
w.pendown()
########
w.begin_fill()
w.forward(40)
w.right(120)
w.forward(40)
w.right(120)
w.forward(40)
w.end_fill()


turtle.exitonclick()
