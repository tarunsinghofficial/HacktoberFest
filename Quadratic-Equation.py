# Python Program that takes input and returns the roots of a quadratic equation given that b^2 > 4ac

# Importing necessary modules
from decimal import Decimal
import math


print("Given that the quadratic equation is given as ax^2+ bx + c = 0")
print("Input the respective values of a, b and c: ")
a = Decimal(input("Input the coefficient of the second power of x, a: "))
b = Decimal(input("Input the coeficient of x, b: "))
c = Decimal(input("Input the constant, c: "))
denomonator = 2*a
inside_function= (b**2) - (4*a*c)
square_root = Decimal(inside_function).sqrt()
x_one = (-b + square_root)/denomonator
x_two = (-b - square_root)/denomonator
print("The roots of the quadratic equations are " + str(x_one) + " and " + str(x_two))Quadratic Equation.py 
