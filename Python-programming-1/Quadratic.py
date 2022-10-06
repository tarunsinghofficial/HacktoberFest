import math
print ("Enter Quadratic equation, ax**2+bx+c,Enter a coefficient")
a= int (input("enter a:"))
b= int (input("enter b:"))
c= int (input("enter c:"))

if a==0:
    print("Value of ", a, 'Should not be zreoooo!!!')
    print("\nAborting!!!")
else:
    delta = b*b - 4*a*c
    if delta>0:
        root1= (-b+math.sqrt(delta))/(2*a)
        root2= (-b-math.sqrt(delta))/(2*a)
        print("roots are REAL and UNEQUAL")
        print("Roots1 =", root1, ",Root2", root2)
    elif delta==0:
        root1= -b/(2*a)
        print("roots are REAL and EQUAL")
        print("Roots1 =", root1, ",Root2", root1)
    else :
        print ("Roots are COMPLEX and IMAGINARY")
