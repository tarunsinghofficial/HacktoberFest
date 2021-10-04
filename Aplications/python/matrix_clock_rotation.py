#  Rotate a Matrix by 90 degrees clockwise
import numpy as np
a = int(input("Enter Index of matrix:-"))
b = []
print("Enter the Matrix Element Rowwise:-")
for i in range(a):
    c = []
    for j in range(a):
        c.append(int(input(f"Enter the {i+1}row {j+1}column Entry:-")))
    b.append(c)


def print_matrix(z):    # This function print the values of list in the list in form of Matrix
    for i in range(len(z)):
        for j in range(len(z)):
            print(z[i][j], end=" ")
        print()


print("Original Matrix is:-")
print_matrix(b)
degrees = {"90": 1, "180": 2, "270": 3}
c = np.rot90(b, 4-degrees["90"])
print("Matrix After Rotation(Clockwise):-")
print_matrix(c)
