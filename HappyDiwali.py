import turtle
import random
import time

t = turtle.Turtle()
s = turtle.Screen()

s.setup(width=1.0, height=1.0)
s.colormode(255)

turtle.Screen().bgcolor("Black")

t.pencolor('yellow')

t.speed(0)

t.hideturtle()

t.pensize(4)

def draw(radius):
    for i in range(10):
        t.circle(radius)
        radius = radius-4
        
def design():
    for i in range(10):
        draw(120)
        t.right(36)
    t.penup()

design()

def rocket():
    t.hideturtle()
    t.setpos(-510, -180)
    t.color('yellow')
    t.pendown()
    t.begin_fill()  
    for count in range(3):
        t.fd(50)
        t.lt(120)
    t.end_fill()
    t.penup()  
    t.pendown() 
    t.color('red')
    t.begin_fill()
    t.fd(50)
    t.rt(90)
    t.fd(80)
    t.rt(90)
    t.fd(50)
    t.rt(90)
    t.fd(80)
    t.end_fill()
    t.penup()
    t.setpos(-470, -350)
    t.speed(0)
    t.pendown()
    t.color('brown')
    t.begin_fill()
    t.fd(100)
    t.rt(90)
    t.fd(2)
    t.rt(90)
    t.fd(100)
    t.rt(90)
    t.fd(2)
    t.end_fill()
    t.penup()
    t.penup()
    t.setpos(-495, -283)
    t.speed(0)
    t.pensize(3)

    t.pendown()
    t.color('brown')
    t.begin_fill()
    t.fd(3)
    t.rt(90)
    t.fd(20)
    t.rt(90)
    t.fd(3)
    t.rt(90)
    t.fd(20)
    t.end_fill()
    t.penup()
    t.pendown()

    Radius = 10
    t.pensize(1)
    x_coord = (-500)
    y_coord = (-290)
    t.penup()
    t.setpos(x_coord, y_coord)
    t.pendown()
    t.pencolor('yellow')
    for i in range(5):
        t.fd(Radius)
        t.backward(2*Radius)
        t.fd(Radius)
        t.right(20)


rocket()

def crackers():
    Radius = random.randint(80, 180)
    x_coord = (400)
    y_coord = (350)
    t.penup()
    t.setpos(x_coord, y_coord)  
    t.pendown()
    t.pencolor('blue')
    for i in range(20):
        t.fd(Radius)
        t.backward(2*Radius)
        t.fd(Radius)
        t.right(10)

    Radius = random.randint(80, 180)
    x_coord = (360)
    y_coord = (250)
    t.penup()
    t.setpos(x_coord, y_coord)
    t.pendown()
    t.pencolor('red')
    for i in range(20):
        t.fd(Radius)
        t.backward(2*Radius)
        t.fd(Radius)
        t.right(10)

    Radius = random.randint(80, 180)
    x_coord = (560)
    y_coord = (130)
    t.penup()
    t.setpos(x_coord, y_coord)
    t.pendown()
    t.pencolor('pink')
    for i in range(20):
        t.fd(Radius)
        t.backward(2*Radius)
        t.fd(Radius)
        t.right(10)

    Radius = random.randint(80, 180)
    x_coord = (-360)
    y_coord = (180)
    t.penup()
    t.setpos(x_coord, y_coord)
    t.pendown()
    t.pencolor('orange')
    for i in range(20):
        t.fd(Radius)
        t.backward(2*Radius)
        t.fd(Radius)
        t.right(10)

    Radius = random.randint(80, 180)
    x_coord = (-480)
    y_coord = (120)
    t.penup()
    t.setpos(x_coord, y_coord)
    t.pendown()
    t.pencolor('purple')
    for i in range(20):
        t.fd(Radius)
        t.backward(2*Radius)
        t.fd(Radius)
        t.right(10)

    Radius = random.randint(70, 120)
    x_coord = (-530)
    y_coord = (380)
    t.penup()
    t.setpos(x_coord, y_coord)
    t.pendown()
    t.pencolor('yellow')
    for i in range(20):
        t.fd(Radius)
        t.backward(2*Radius)
        t.fd(Radius)
        t.right(10)

    Radius = random.randint(50, 100)
    x_coord = (540)
    y_coord = (350)
    t.penup()
    t.setpos(x_coord, y_coord)
    t.pendown()
    t.pencolor('orange')
    for i in range(20):
        t.fd(Radius)
        t.backward(2*Radius)
        t.fd(Radius)
        t.right(10)

    Radius = random.randint(80, 180)
    x_coord = (-530)
    y_coord = (150)
    t.penup()
    t.setpos(x_coord, y_coord)
    t.pendown()
    t.pencolor('green')
    for i in range(20):
        t.fd(Radius)
        t.backward(2*Radius)
        t.fd(Radius)
        t.right(10)


crackers()

def h():
    t.penup()
    t.setpos(-300, 200)
    t.pendown()
    t.left(90)
    t.forward(100)
    t.right(180)
    t.forward(50)
    t.left(90)
    t.forward(50)
    t.left(90)
    t.forward(50)
    t.right(180)
    t.fd(100)


def a1():
    t.penup()
    t.setpos(-200, 200)
    t.pendown()
    t.left(90)
    t.left(60)
    t.forward(100)
    t.right(120)
    t.forward(50)
    t.right(120)
    t.forward(50)
    t.right(180)
    t.fd(50)
    t.right(60)
    t.fd(50)


def p1():
    t.penup()
    t.setpos(-50, 200)
    t.pendown()
    t.left(150)
    t.fd(80)
    t.right(180)
    t.circle(25)


def p2():
    t.penup()
    t.setpos(50, 200)
    t.pendown()
    t.left(180)
    t.fd(80)
    t.right(180)
    t.circle(25)


def y():
    t.penup()
    t.setpos(150, 200)
    t.pendown()
    t.left(150)
    t.fd(110)
    t.right(180)
    t.fd(60)
    t.right(120)
    t.fd(60)
    t.right(180)
    t.fd(60)
    t.right(60)
    t.fd(50)
    t.left(120)


def d():
    t.penup()
    t.setpos(-350, -300)
    t.pendown()
    t.left(90)
    t.fd(100)
    t.right(90)
    t.circle(-50, 180, 30)
    t.right(180)


def i1():
    t.penup()
    t.setpos(-250, -300)
    t.pendown()
    t.fd(50)
    t.left(180)
    t.fd(25)
    t.right(90)
    t.fd(100)
    t.right(90)
    t.fd(25)
    t.backward(50)


def w():
    t.penup()
    t.setpos(-150, -200)
    t.pendown()
    t.right(90)
    t.fd(100)
    t.left(135)
    t.fd(50)
    t.right(90)
    t.fd(50)
    t.left(135)
    t.fd(100)
    t.right(180)
    t.fd(100)


def a2():
    t.penup()
    t.setpos(-50, -300)
    t.pendown()
    t.left(90)
    t.left(60)
    t.forward(100)
    t.right(120)
    t.forward(50)
    t.right(120)
    t.forward(50)
    t.right(180)
    t.fd(50)
    t.right(60)
    t.fd(50)


def l():
    t.penup()
    t.setpos(100, -300)
    t.pendown()
    t.left(150)
    t.fd(100)
    t.right(180)
    t.fd(100)
    t.left(90)
    t.fd(60)


def i2():
    t.penup()
    t.setpos(200, -300)
    t.pendown()
    t.fd(50)
    t.left(180)
    t.fd(25)
    t.right(90)
    t.fd(100)
    t.right(90)
    t.fd(25)
    t.backward(50)


t.setheading(0)
t.color("white")
t.pensize(10)

h()
a1()
p1()
p2()
y()
d()
i1()
w()
a2()
l()
i2()
t.hideturtle()

time.sleep(2)
t.penup()

turtle.done()
