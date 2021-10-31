def draw_line (width, height): 
    t.color ('red')
    t.forward(width)
    t.backward(width / 2)
    t.right(90)
    t.forward(height)
    t.right(90)
    t.forward(width / 2)
    t.backward(width)
    t.end_fill()
    
    

def curvemove():
    for i in range(200):
            t.right(1)
            t.forward(1)
            

def draw_heart (): 
    color= random.choice(colors)
    t.fillcolor(color)
    t.begin_fill()
    t.left(140)
    t.forward(111.65)
    curvemove()

    t.left(120)
    curvemove()
    
    t.forward(111.65)
    t.end_fill()
    
#DEFINITIONS
def drawSquare(sideLen):
    for i in range(4):
        t.forward(sideLen)
        t.left(90)
    return
def drawRedTriangle(length,width):
    t.color('red')
    t.fillcolor('red')
    t.begin_fill()
    t.forward(width)
    t.right(105)
    t.forward(length)
    t.right(152)
    t.forward(length-2)
    t.end_fill()
    return
def drawCurve(angle,forward,left):
    for i in range(angle):
        t.forward(forward)
        t.left(left)
    return


# Top Level

import turtle as t
import random
s=t.Screen()
s.bgcolor('black')
t.pensize (7)
#t.hideturtle()
t.speed(5)
t.delay(0)


colors  = ["red","light green","blue","orange","purple","pink","yellow"]
t.penup()
t.backward(300)
t.pendown()
draw_line (100, 190)
t.penup()
t.right(180)
#t.pendown()
#t.color('black')
t.forward(100)
#t.color('red')
t.pendown()
#t.goto(170,-280)



#curvemove()
draw_heart()
t.penup()
t.left(140)
t.forward(250)
t.left(90)
t.forward(150)
t.right(90)
t.pendown()
##t.width(1)
#bottom triangle
drawRedTriangle(200,70)

#left side of wing
t.begin_fill()
t.left(77)
t.forward(30)
drawCurve(42,1,2)
t.right(110)
drawCurve(32,2,-1)
t.right(100)
drawCurve(25,5,-1)
t.right(40)
t.forward(55)
t.end_fill()

#moving back to centre
t.left(43)
t.forward(45)

#right side of wing
t.begin_fill()
t.forward(30)
drawCurve(42,1,-2)
t.left(110)
drawCurve(32,2,1)
t.left(100)
drawCurve(25,5,1)
t.left(45)
t.forward(55)
t.end_fill()

#moving to upper semi, (pen-up)
t.penup()
t.right(180)
t.forward(55)
t.right(45)
drawCurve(25,5,-1)
t.left(75)
drawCurve(10,2,1)
t.left(90)

t.pendown()

#drawing upper semi
t.width(25)
t.penup()
drawCurve(2,6,0.95)
t.pendown()
drawCurve(55,6,0.95)
