import turtle as t

t.pensize(2)

def curve():
    for i in range(200):
        t.right(0.8)
        t.forward(1)

def curve2():
    for i in range(100):
        t.right(0.8)
        t.forward(1)

def curve3():
    for i in range(100):
        t.left(1)
        t.forward(1)

t.penup()
t.goto(0,50)
t.pendown()
t.begin_fill()
t.fillcolor("#306998")
t.backward(80)
t.left(90)
t.forward(35)
curve()
t.right(19.5)
t.forward(80)
curve2()
t.right(10)
t.forward(50)
curve3()
t.right(100)
t.forward(50)
curve()
t.right(19.5)
t.forward(181)
t.left(90)
t.forward(20)
t.end_fill()
t.penup()
t.goto(-20,100)
t.pendown()
t.begin_fill()
t.fillcolor("white")
t.circle(19)
t.end_fill()

def curve4():
    for i in range(200):
        t.right(0.8)
        t.backward(1)

def curve5():
    for i in range(100):
        t.right(0.8)
        t.backward(1)

def curve6():
    for i in range(100):
        t.left(1)
        t.backward(1)

t.right(90)
t.penup()
t.goto(-25,-150)
t.pendown()
t.begin_fill()
t.fillcolor("yellow")
t.backward(-80)
t.left(90)
t.backward(35)
curve4()
t.right(19.5)
t.backward(80)
curve5()
t.right(10)
t.backward(50)
curve6()
t.right(100)
t.backward(50)
curve4()
t.right(19.5)
t.backward(181)
t.left(90)
t.backward(20)
t.end_fill()
t.penup()
t.goto(38,-200)
t.pendown()
t.begin_fill()
t.fillcolor("white")
t.circle(19)
t.end_fill()
t.hideturtle()
t.done()