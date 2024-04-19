"""Bitwise Operations"""

import numpy as np
import cv2


# Drawing a Rectangle
rectangle = np.zeros((300, 300), dtype="uint8")
cv2.rectangle(img=rectangle, pt1=(25, 25), pt2=(275, 275),color=255, thickness=-1)
cv2.imshow("Rectangle", rectangle)

# Drawing a Circle
circle = np.zeros((300, 300), dtype="uint8")
cv2.circle(img=circle, center=(150, 150), radius=150, color=255, thickness=-1)
cv2.imshow("Circle", circle)
cv2.waitKey(0)

# Bitwise AND
"""Bitwise AND is only TRUE when both inputs have a value that is ON
In this case the cv2.bitwise_and function examinse every pixel in the 
rectangle and circle, if BOTH picles have a value greater than zero 
then the pixel is turned ON (i.e 255)"""

bitwiseAnd = cv2.bitwise_and(rectangle, circle)
cv2.imshow("AND", bitwiseAnd)
cv2.waitKey(0)


# Bitwise OR
"""Bitwise OR examies every pixel in the two inputs and if 
EITHER pixel in rectangle or cicle is greater than zero then
the ouput pixel has a value of 255 otherwise it is 0"""

bitwiseOR = cv2.bitwise_or(rectangle, circle)
cv2.imshow("OR", bitwiseOR)
cv2.waitKey(0)


# Bitwise XOR
"""Bitwise XOR identical to OR function with one exception:
both the rectangle and circle are not allowed to BOTH have 
values greater than 0 (only 0 can be 0)"""

bitwiseXOR = cv2.bitwise_xor(rectangle, circle)
cv2.imshow("XOR", bitwiseXOR)
cv2.waitKey(0)


# Bitwise NOT
"""Bitwise NOT inverts the values of the pixels,
pixles with value of 255 become 0 and pixels with a value of 0 become 255"""
bitwiseNOT = cv2.bitwise_not(rectangle, circle)
cv2.imshow("NOT", bitwiseNOT)
cv2.waitKey(0)