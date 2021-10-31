import turtle
t=turtle.Turtle()
s=turtle.Screen()
s.bgcolor("#16213e")
def win(length,angle):
    t.forward(length)
    t.right(angle)


t.hideturtle()
t.color("deepskyblue")
t.left(6)
t.begin_fill()
t.fillcolor("deepskyblue")
win(200,96)
win(150,96)
win(200,83)
win(109,85)
t.end_fill()
t.color("#16213e")
win(100,96)
win(67,90)
win(100,180)
win(200,180)
win(100,270)
t.forward(140)

turtle.exitonclick()
