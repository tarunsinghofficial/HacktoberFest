#huawei p40
import turtle
t=turtle.Turtle()
s=turtle.Screen()
t.hideturtle()
s.bgcolor('black')
t.color('white')
turtle.title("HUAWEI P40 PRO")
t.left(90)
t.backward(200)
def phone(l,b,r):
    for i in range(2):
        t.forward(l)
        t.circle(r,90)
        t.forward(b)
        t.circle(r,90)
        
    
    
    
t.color("floralwhite")   
t.begin_fill()
phone(470,230,20)
t.end_fill()
t.color('black')
t.penup()
t.forward(450)
t.circle(20,90)
t.forward(135)
t.right(90)
t.backward(150)
t.pendown()
############camera module
t.begin_fill()
phone(135,55,20)
t.end_fill()
t.penup()
t.color('royalblue')
t.forward(140)
t.left(90)
t.forward(75)
t.pendown()
#module1
t.begin_fill()
t.fillcolor('steelblue')
t.circle(11)
t.end_fill()
##########
t.penup()
t.left(90)
t.forward(50)
t.right(90)
########## module 2
t.begin_fill()
t.fillcolor('steelblue')
t.circle(13)
t.end_fill()
##########
t.penup()
t.left(90)
t.forward(60)
t.right(90)
t.backward(14)
t.right(90)
t.backward(30)
t.pendown()
##########module 3
t.begin_fill()
t.fillcolor('steelblue')
phone(20,7,10)
t.end_fill()
############
t.penup()
t.forward(135)
t.left(90)
t.backward(35)
###module 4
t.begin_fill()
t.fillcolor('steelblue')
t.circle(9)
t.end_fill()
################
t.penup()
t.left(90)
t.forward(50)
t.right(90)
###module 
t.begin_fill()
t.fillcolor('steelblue')
t.circle(6)
t.end_fill()
############
t.penup()
t.left(90)
t.forward(70)
t.left(180)
t.pendown()
#######flash
t.color("white")
t.fillcolor("whitesmoke")
for i in range(2):
    t.begin_fill()
    t.forward(15)
    t.circle(6,180)
    t.end_fill()
turtle.exitonclick()

