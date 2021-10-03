num=int(input("1.Add\n2.Subtract\n3.Multiply\n4.Divide\n5.Module\n"))
if num in (1,2,3,4,5):
        num1 = float(input("Enter first number: "))
        num2 = float(input("Enter second number: "))

        if num==1:
            print(num1,"+",num2,"=",(num1+num2))

        elif num==2:
            print(num1,"-",num2,"=",(num1-num2))

        elif num==3:
            print(num1,"*",num2,"=",(num1*num2))

        elif num==4:
            print(num1,"/",num2,"=",(num1/num2))
            
        elif num==5:
            print(num1,"%",num2,"=",(num1%num2))
else:
        print("Invalid Input")
