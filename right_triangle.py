import matplotlib.pyplot as plt
from math import sqrt
import numpy as np 


class RightTriangle:
    def __init__(self, a, b):
        self._a = a
        self._b = b
        
        if (a < 0) or (b < 0):
            error = ValueError("Can't have negative sides for a triangle")
            raise error
        else:
             self._c = sqrt(a**2 + b**2)
             
    def plot_triangle(self):
        coordinates_x = np.array([0, self._a, self._a, 0])
        coordinates_y = np.array([0, 0, self._b, 0])
        plt.plot(coordinates_x, coordinates_y, color="red")
        plt.axis("equal") 

#Test function for ValueError                
def test_RightTriangle():
    success = False
    try:
        triangle3 = RightTriangle(1,-1)
    except ValueError:
        success = True
    assert success

#Returns no error, so code is ok
test_RightTriangle()
 
#Defining the right triangles   
triangle1 = RightTriangle(1, 1)
triangle2 = RightTriangle(3, 4)

#Printing out the hypothenus for the triangles
print (triangle1._c)
print (triangle2._c)

#Plotting the second triangle
triangle2.plot_triangle()
