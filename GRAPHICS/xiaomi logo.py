#xiaomi logo
import turtle
t=turtle.Turtle()
s=turtle.Screen()
t.hideturtle()
turtle.title("MI")
s.bgcolor("black")
t.backward(200)
t.right(90)
t.forward(70)
t.left(90)

def rect(length,breadth):
    for i in range(2):
        
        t.forward(length)
        t.right(90)
        t.forward(breadth)
        t.right(90)


     

        
def squirle(length,radius,angle):
    for i in range(4):
        t.forward(length)
        t.circle(radius,angle)



t.begin_fill()
t.color("Orange Red")
squirle(300,30,90)
t.end_fill()
t.forward(15)
t.left(90)

t.forward(50)
t.color("white")
t.begin_fill()
t.forward(240)
t.right(90)
t.forward(180)
t.circle(-30,90)
t.forward(210)
t.right(90)
t.forward(30)
t.right(90)
t.forward(180)
t.circle(30,90)
t.forward(120)
t.left(90)
t.forward(210)
t.left(90)
t.backward(30)
t.penup()
t.forward(81)
t.pendown()
t.left(90)
rect(180,40)
t.right(90)
t.penup()
t.forward(170)
t.pendown()
t.left(90)
rect(240,40)
t.end_fill()

turtle.exitonclick()
