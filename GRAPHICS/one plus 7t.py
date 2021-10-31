#one plus 7t

import turtle
o=turtle.Turtle()
s=turtle.Screen()
s.bgcolor("black")
t=turtle.Turtle()
t.hideturtle()
o.hideturtle()
o.color("white")
o.left(90)
o.backward(200)
o.begin_fill()
o.color("royal blue")
for i in range(2):
    o.forward(400)
    o.circle(20,90)
    o.forward(200)
    o.circle(20,90)
   
    
o.end_fill()
#####
t.color("white")
t.penup()

for i in  range(2):
    t.left(90)
    t.forward(180)

t.backward(60)
t.pendown()
t.color("black")
t.begin_fill()
t.circle(50)
t.end_fill()
####lenses
t.right(180)
t.circle(-50,270)


for i in range(3):
    t.penup()
    t.right(90)
    t.forward(30)
    t.left(90)
    t.pendown()
    t.begin_fill()

    t.color("light slate gray")
    t.circle(10)
    t.end_fill()
    t.end_fill()


t.penup()
t.right(90)
t.forward(10)
t.left(90)
t.pendown()
t.color("black")
t.circle(50,280)
t.left(90)
t.forward(20)
t.begin_fill()
t.color("white")
t.circle(5)
t.end_fill()

