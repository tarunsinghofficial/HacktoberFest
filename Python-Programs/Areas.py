x=int(input("To Find Area of Circle [Press 1]\n,To Find Area of Square [Press 2]\n,To Find Area of Rectangle [Press 3]\n"))
if x==1:
    t=int(input("Enter The Radius of circle"))
    print("The Area of Circle is--",(22/7)*(t**2))
    print("The Area of Circle(Aprox) is--",3.14*(t**2))
elif x==2:
    a=int(input("Enter The Side of Square"))
    print("The Area of Square is--",a**2)
else:
    l=int(input("Enter The Length of Rectangle"))
    b=int(input("Enter The Breath of Rectangle"))
    print("The Area of Rectangle is--",l*b) 
