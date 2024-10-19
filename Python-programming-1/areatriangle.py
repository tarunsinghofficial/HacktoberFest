# Python Program to find the area of a triangle using Heron's formula

# Function to check if three sides can form a triangle
def is_valid_triangle(a, b, c):
    return (a + b > c) and (a + c > b) and (b + c > a)

# Input for the sides of the triangle
a = float(input("Enter first side: "))
b = float(input("Enter second side: "))
c = float(input("Enter third side: "))

# Check if the sides can form a valid triangle
if is_valid_triangle(a, b, c):
    # Calculate semi-perimeter
    s = (a + b + c) / 2
    
    # Calculate area using Heron's formula
    area = (s * (s - a) * (s - b) * (s - c)) ** 0.5
    
    print("Area of triangle is:", area)
else:
    print("Invalid triangle sides. Please ensure that the sum of any two sides is greater than the third side.")

