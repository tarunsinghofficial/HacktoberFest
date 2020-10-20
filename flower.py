import turtle

turtle = turtle.Turtle()

#Config of turtle
turtle.color('green')
turtle.speed(10)

for i in range(6):
	turtle.left(60)
	for i in range(12):
		turtle.forward(100)
		turtle.left(30)

turtle.color('red')

for i in range(6):
	turtle.left(60)
	for i in range(12):
		turtle.forward(75)
		turtle.left(30)
		
turtle.color('blue')

for i in range(6):
	turtle.left(60)
	for i in range(12):
		turtle.forward(50)
		turtle.left(30)
		
turtle.color('black')

for i in range(6):
	turtle.left(60)
	for i in range(12):
		turtle.forward(25)
		turtle.left(30)
