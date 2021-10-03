a=int(input("Enter First Number :"))
b=int(input("Enter Second Number :"))
print("Enter the Format in Which You Want Answer\nPress1 For",a,"÷",b,"\nPress2 For",b,"÷",a)
c=int(input(""))            
if c==1:
    print("Quotient is--",a/b,"\nRemainder is--",a%b)
elif c==2:
    print("Quotient is--",b/a,"\nRemainder is--",b%a)
else:
    print("Invalid Input")
