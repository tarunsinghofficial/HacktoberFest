##apple watch
import turtle
t=turtle.Turtle()
b=turtle.Turtle()
turtle.title("APPLE WATCH")
def sq(length,radius,color,z):
    for i in range(4):
        z.fillcolor(color)
        
        z.forward(length)
        z.circle(radius,90)
       
        
b.penup()
b.right(90)
b.forward(5)
b.left(90)
b.pendown()
   
t.forward(5)
##outer
t.hideturtle()
b.hideturtle()
b.begin_fill()
sq(110,20,"light slate gray",b)
b.end_fill()
###inner
t.begin_fill()
sq(100,20,"black",t)
t.end_fill()
###dial
b.forward(110)
b.circle(20,90)
b.forward(90)
b.begin_fill()
b.circle(-3,180)
b.forward(20)
b.circle(-3,180)
b.end_fill()
###upper strip
b.forward(40)
b.circle(20,90)
b.color("black")
b.begin_fill()
b.circle(-10,50)
b.forward(5)
b.circle(-30,40)
b.forward(110)
b.circle(10,90)
b.forward(60)
b.circle(10,90)
b.forward(110)
b.circle(-30,40)
b.forward(5)
b.circle(-10,50)
b.end_fill()


######
b.color("black")
b.penup()
b.circle(14,90)
b.forward(115)
b.circle(20,90)
b.backward(3)
b.pendown()
###bottom strip
b.begin_fill()
b.circle(-10,50)
b.forward(5)
b.circle(-30,40)
b.forward(110)
b.circle(10,90)
b.forward(60)
b.circle(10,90)
b.forward(110)
b.circle(-30,40)
b.forward(5)
b.circle(-10,50)
b.end_fill()

#######
#####
t.penup()
t.color("red")
t.forward(45)
t.left(90)
t.forward(40)
t.right(90)
t.pendown()
#######
t.begin_fill()
t.left(150)
t.forward(30)
t.circle(-20,240)
t.left(180)
t.circle(-19,240)
t.forward(35)
t.end_fill()
turtle.exitonclick()
