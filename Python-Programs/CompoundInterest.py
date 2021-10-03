p=float(input("Enter the principle amount:"))
t=int(input("Enter the time(years):"))
r=float(input("Enter the rate:"))
a=p*(1+r/100)**t
c=a-p
print("Compound interest is--", c)
