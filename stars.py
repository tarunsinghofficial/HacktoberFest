#viresh solanki
print("Pattern printing")
number=int(input("Enter your number:-"))
choice=bool(int(input("enter 1/0:-")))
if choice==True:
    for i in range(0,number+1):
        print("*"*i)
elif choice==False:
    for i in range(number,0,-1):
        print("*"*i)
else:
    print("inVALID choice")
