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
o.backward(250)
o.begin_fill()
o.color("#f8f5f1")
for i in range(2):
    o.forward(450)
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
t.color("#151515")
t.begin_fill()
t.circle(65)
t.end_fill()
####lenses


t.color("#f4f9f9")
t.penup()
t.left(90)
t.forward(35)
t.right(90)
t.pendown()
t.begin_fill()
t.circle(30)
t.end_fill()


