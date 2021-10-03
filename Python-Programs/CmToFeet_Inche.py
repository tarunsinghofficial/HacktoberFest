l=int(input("Enter The Lenght(In Centimeters)"))
print("Enter in Which Type You Want Your Answer\nPress1 For Feet\nPress2 For Inches\nPress3 For Both")
o=int(input(""))
if o==1:
    a=l/30.48
    print("The Lenght in Feet is--",a)
elif o==2:
    a=l/2.54
    print("The Lenght in Inches is--",a)
elif o==3:
    a=l/30.48
    b=l/2.54
    print("The Lenght in Feet is--",a,"\nThe Lenght in Inches is--",b)
else:
    print("Invalid Input")
