a=int(input("Enter Your Number"))
b=0
t=a
while (a>0):
    d=a%10
    b=b*10+d
    a=a//10
if (t==b):
    print("It is a Pallindrom")
else :
    print("It is Not a Pallindrom")
