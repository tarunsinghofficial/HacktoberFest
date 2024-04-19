##BMW  logo
import turtle
t=turtle.Turtle()
m=turtle.Turtle()
t.hideturtle()
m.hideturtle()

s=turtle.Screen()
s.bgcolor("#393b44")
t.begin_fill()
t.circle(100)
t.end_fill()
m.color("white")
m.penup()
m.left(90)
m.forward(35)
m.right(90)
m.pendown()
###1
for i in range(2):
    m.color("royal blue")
    m.begin_fill()
    m.circle(65,90)

    for i in range(2):
        m.left(90)
        m.forward(65)

    m.end_fill()
###2
    m.left(90)
    m.circle(65,90)
    m.color("gainsboro")
    m.begin_fill()
    m.circle(65,90)
    for i in range(2):
        m.left(90)
        m.forward(65)


    m.end_fill()
    m.left(90)
    m.circle(65,90)




turtle.exitonclick()

