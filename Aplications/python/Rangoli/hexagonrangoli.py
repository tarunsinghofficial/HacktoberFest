from turtle import *
from random import randint

bgcolor('black')

red=[210,0,0,255,255,255]
green=[0,128,0,128,255,255]
blue=[0,128,128,0,0,255]

#m=int(input("Enter the size "))
#s=int(input("Enter the speed "))

x=j=10
speed(200)#put s instead of 200 for custom speed
pensize(5)#put m for custom size

while x < (410):
 colormode(255)
 pencolor((red[x % 6]),(green[x % 6]),(blue[x % 6]))
 fd(30+x)
 rt(60.5)   
 x = x+1
 

