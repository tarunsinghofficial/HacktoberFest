import turtle
s=turtle.Screen()
s.bgcolor("black")

t=turtle.Turtle()
t1=turtle.Turtle()
t2=turtle.Turtle()
t3=turtle.Turtle()
t.hideturtle()
t1.hideturtle()
t2.hideturtle()
t3.hideturtle()
t.speed(100)
t1.speed(100)
t2.speed(100)
t3.speed(100)
t.color("white")
t1.color("white")
t2.color("white")
t3.color("white")

t.pensize(10);
def cpu(x):
    for i in range(4):
        t.fd(x)
        t.circle(10,90)
def buses(y):
    y.begin_fill()
    for i in range(2):
        y.fd(20)
        y.circle(5,180)
    y.end_fill()
    
def connect(q):
    for i in range(5):
        buses(q)
        q.right(90)
        q.penup()
        q.fd(20)
        q.pendown()
        q.left(90)
cpu(100)

t.left(90)
t.penup()
t.fd(15)
t.right(90)
t.fd(15)
t.pendown()
t.pensize(1)
t.begin_fill()
cpu(70)
t.end_fill()

####
##top
t.left(90)
t.penup()
t.fd(120)
t.pendown()
connect(t)

###########
##left

t1.left(90)
t1.penup()
t1.fd(15)
t1.right(90)
t1.fd(15)
t1.fd(70)
t1.circle(10,90)
t1.left(90)
t1.pendown()
t1.penup()
t1.fd(120)
t1.pendown()
connect(t1)
###############

t2.left(90)
t2.penup()
t2.fd(15)
t2.right(90)
t2.fd(15)
t2.fd(70)
t2.circle(10,90)
t2.fd(70)
t2.circle(10,90)
t2.left(90)
t2.pendown()
t2.penup()
t2.fd(120)
t2.pendown()
connect(t2)

#####

t3.left(90)
t3.penup()
t3.fd(15)
t3.right(90)
t3.fd(15)
t3.fd(70)
t3.circle(10,90)
t3.fd(70)
t3.circle(10,90)
t3.fd(70)
t3.circle(10,90)
t3.left(90)
t3.pendown()
t3.penup()
t3.fd(120)
t3.pendown()
connect(t3)
