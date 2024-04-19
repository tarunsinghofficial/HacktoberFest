import turtle
t=turtle.Turtle()
s=turtle.Screen()

s.bgcolor("black")
t.hideturtle()


t.color("Lime Green")
t.begin_fill()
t.circle(90)
t.end_fill()
t.left(90)

t.forward(120)
t.left(90)
t.forward(65)
t.color("black")

#######
t.left(180)
t.left(45)
######
def   wifi(x,y):
    t.circle(-x,y)
    t.circle(-10,180)
    t.circle(x-20,y)
    t.circle(-10,180)
    

t.begin_fill()
wifi(90,90)


t.end_fill()   



t.penup()
t.right(140)
t.forward(30)
t.left(90)
t.forward(30)
t.left(40)
t.pendown()
t.begin_fill()
wifi(65,70)
t.end_fill()
t.penup()
t.right(140)
t.forward(30)
t.left(90)
t.forward(30)
t.left(40)
t.begin_fill()
wifi(65-25,75-20)
t.end_fill()

