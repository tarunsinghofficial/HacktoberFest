import turtle
import random

#######################################           Global Variables ###############################################################
#distinct_colors
colors  = ["red","green","blue","orange","purple","pink","yellow","dark green","dark red","lime","dark blue","medium violet red",
           "cyan","saddle brown","dark gray","dark orange","medium purple","magenta"]
#dark_colors
dark_colors = ["white","red","green","blue","orange","purple","pink","yellow"]

#line_length
length = 5

##################################################################################################################################


#######################################           Function Definitions ############################################################

def remote_tangent_circles(circle_turtle,color,dis_range,radius):
    """ Function to draw tangent Circles
    Parameters:
    arg1 (turtle class): Turtle Class Refernce
    arg2 (int)         : color 
    arg2 (int)         : Distance Range
    arg3 (int)         : Circle Radius 
    Returns:
    None:Returning None

    """
    circle_turtle.color(color)
    for i in range(dis_range):
        circle_turtle.circle(radius*i)
	
    circle_turtle.up()
    circle_turtle.goto(0,0)
    circle_turtle.down()
	
def remote_concentric_circles(circle_turtle,dis_range,radius):
    """ Function to draw Concentric Circles
    Parameters:
    arg1 (turtle class): Turtle Class Refernce
    arg2 (int)         : Distance Range
    arg3 (int)         : Circle Radius 
    Returns:
    None:Returning None

    """
    for i in range(dis_range):
        color = random.choice(dark_colors)
        circle_turtle.color(color)
        circle_turtle.circle(radius*i)
        circle_turtle.up()
        circle_turtle.sety((radius*i)*(-1))
        circle_turtle.down()

    circle_turtle.up()
    circle_turtle.goto(0,0)
    circle_turtle.down()


if __name__ == "__main__":

    remote_circle = turtle.Turtle()
    remote_circle_screen = turtle.Screen()
    remote_circle_screen.bgcolor('black')
    
    remote_circle.width(1)      #set the circle width
    remote_circle.speed(0)      #set speed delay to 0
    
    remote_concentric_circles(remote_circle,30,10)

    remote_circle.width(2)      #change the circle width

    for j in range(8):
        for i in range (10):
            remote_tangent_circles(remote_circle,dark_colors[j],10,(10 + j))
            remote_circle.right(360/10)

    remote_circle.width(3)
    remote_concentric_circles(remote_circle,60,3)

    remote_circle.width(2)

    #start drawing the lines
    for count in range(60):
        remote_circle.forward(length)
        remote_circle.right(135)
        remote_circle.color('black')    #change the color 
        length = length + 5

    #Reset the Original Position
    remote_circle.penup()
    remote_circle.home()
    remote_circle.pendown()

    #exit the turtle class on click()
    turtle.Screen().exitonclick()
