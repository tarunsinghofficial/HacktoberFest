### This program allows you to perform various operations related to points
### in a 2 coordinate system.
import math


class Coordinates():
	def __init__(self, x, y):
		self.x = x
		self.y = y

	def distOrigin(self):
		return math.sqrt(self.x**2+self.y**2)

	def distFrom(self, other):
		dist = math.sqrt((self.x-other.x)**2+(self.y-other.y)**2)
		return dist

	def fitline(self, other):
		slope = (self.y-other.y)/(self.x-other.x)
		if slope != 0:
			return "y - " + str(slope) + "x = " + str(self.y-slope*self.x)
		else:
			return "y = " + str(self.y)

	def CircleWithDia(self, other):
		b, a = (self.y+other.y)/2, (self.x+other.x)/2
		rad = math.sqrt((self.x-a)**2+(self.y-b)**2)
		return "sq(y - " + str(b) + ") + sq(x - " + str(a) + ") = " + str(rad)


if __name__ == "__main__":
	print('Enter the first point in form x y')
	try:
		x, y = map(int, input().split(' ', 2))
	except:
		print('The input is invalid')
	print('Enter the 2nd point in form x y')
	try:
		m, l = map(int, input().split(' ', 2))
	except:
		print('The input is invalid')
	A = Coordinates(x, y)
	B = Coordinates(m, l)

	print(f"The distance of first point from origin is {A.distOrigin()} units.")
	print(f"The distance of 2nd Point from the origin is {B.distOrigin()} units.")
	print(f"The distance between the points is {A.distFrom(B)} units.")
	print(f"The Straight line Through the points is {A.fitline(B)} .")
	print(f"The Circle with the line segement as a diameter is {A.CircleWithDia(B)}.")

