#Turtle race game

import turtle
# creating objects
t0=turtle.Turtle()
t1=turtle.Turtle()
t2=turtle.Turtle()
t3=turtle.Turtle()
t4=turtle.Turtle()

#finish line object
t=turtle.Turtle()

# shape
t0.shape("turtle")
t0.color("red")

t1.shape("turtle")
t1.color("green")

t2.shape("turtle")
t2.color("#145374")

t3.shape("turtle")
t3.color("#ed6663")

t4.shape("turtle")
t4.color("#41444b")
objects=[t0,t1,t2,t3,t4]
def setpos():
    
    for i in range(5):
        objects[i].penup()
        objects[i].left(90)
        objects[i].fd(40*i)
        objects[i].right(90)
        objects[i].pendown()

#positon set
setpos()

# finish line set
t.pensize(6)
t.penup()
t.right(90)
t.fd(50)
t.lt(90)
t.fd(400)
t.pendown()
t.left(90)
t.fd(250)
t.hideturtle()

import random

#winner
#initial position
pos=[0,0,0,0,0]
dis=400
flag=True

#start race
while(flag):
    for i in pos:
        if i>=390:
            
            flag=False
    else:
        for i in range(5):
                       
            dis_travelled=random.randrange(25)
            objects[i].penup()
            objects[i].fd(dis_travelled)
            objects[i].pendown()
            pos[i]+=dis_travelled
            
        


turtle.exitonclick()









