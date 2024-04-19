###one plus 8 pro
import turtle
t=turtle.Turtle()
t.hideturtle()
s=turtle.Screen()
s.bgcolor('LemonChiffon')
turtle.title('ONEPLUS')
t.penup()
t.right(90)
t.fd(150)
t.left(90)
t.pendown()
def screen(length,breadth,rad):
    for i in range(2):
        t.fd(breadth)
        t.circle(rad,90)
        t.fd(length)
        t.circle(rad,90)
t.begin_fill()
screen(450,220,20)
t.end_fill()
t.color('white')
t.circle(20,-90)
t.bk(7)

t.circle(20,90)
t.color('black')


t.fillcolor('#ffffff')
t.pensize(3)
t.begin_fill()
screen(437,220,20)
t.end_fill()
t.begin_fill()

t.penup()
t.left(90)
t.forward(455)
t.pendown()
t.dot(11)
turtle.exitonclick()

########
