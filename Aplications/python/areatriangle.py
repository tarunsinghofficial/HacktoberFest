# Python Program to find the area of triangle
a = float(input("Enter first side:"))
b = float(input("Enter second side:"))
c = float(input("Enter third side:"))
s = (a + b + c) / 2
area = (s*(s-a)*(s-b)*(s-c)) ** 0.5
print("Area of triangle is :",area)
