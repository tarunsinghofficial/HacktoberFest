import turtle
t=turtle.Turtle()
sai=turtle.Turtle()
s=turtle.Screen()
s.bgcolor("black")
def you(length,breadth,radius,angle):
    for channel in range(2):
        t.forward(length)
        t.circle(radius,angle)
        t.forward(breadth)
        t.circle(radius,angle)
       

def triangle(length):
    t.color("red")
    t.left(90)
    t.forward(40)
    t.right(90)
    t.forward(90)
    t.left(90)
    t.color("white")
    t.forward(length)
    t.right(120)
    t.forward(length)
    t.right(119)
    t.forward(length)


t.color("red")
t.begin_fill()
you(200,100,15,90)
t.end_fill()
t.color("white")
t.begin_fill()
triangle(50)
t.right(120)
t.forward(50)
t.end_fill()
t.hideturtle()
sai.color("white")
for i in range(2):
    sai.forward(200)
    sai.circle(15,90)
    sai.forward(100)
    sai.circle(15,90)

sai.hideturtle()

