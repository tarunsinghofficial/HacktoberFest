#cammscanner
import turtle
t=turtle.Turtle()
m=turtle.Turtle()
m.speed(10)
t.speed(10)
s=turtle.Screen()
s.bgcolor("black")
t.color("turquoise")
t.begin_fill()
t.circle(100)
t.end_fill()
m.circle(100,50)
m.color("steel blue")
m.begin_fill()
m.circle(100,260)
m.left(50)
m.forward(153)
m.end_fill()
t.color("white")
t.penup()
t.left(90)
t.forward(160)
t.left(90)
t.forward(20)
t.pendown()
###

###
def shape(radius,angle,length):
    t.begin_fill()
    t.circle(radius,angle)
    t.left(90)
    t.forward(length)
    t.left(90)
    
    if(radius<=30):
        t.circle(-radius+15,angle)
    else:
        t.circle(-radius+25,angle)
    t.left(90)
    t.forward(length)
    t.end_fill()
    
#####

shape(55,180,25)

#####
t.left(90)
t.penup()
t.backward(60)
t.circle(20,295)
t.pendown()
shape(30,180,15)
t.left(90)
t.circle(30,180)
t.left(25)
def box(length,breadth):
    for i in range(2):
        
        t.begin_fill()
        t.forward(length)
        t.left(90)
        t.forward(breadth)
        t.end_fill()
        t.left(90)

box(45,15)
t.forward(45)

shape(-15,180,15)

t.left(90)
t.circle(-15,180)
box(10,15)
t.hideturtle()
m.hideturtle()
