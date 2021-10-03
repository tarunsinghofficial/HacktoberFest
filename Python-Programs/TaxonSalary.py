s=int(input("Enter Your Salary"))
if s<=20000:
    t=s/100*5
    print("Your Tax is--",t,"Your Total is--",s-t)
elif s>20000 and s<=30000:
    t=s/100*7
    print("Your Tax is--",t,"Your Total is--",s-t)
elif s>30000 and s<=50000:
    t=s/100*8
    print("Your Tax is--",t,"Your Total is--",s-t)
elif s>50000 and s<=60000:
    t=s/100*9
    print("Your Tax is--",t,"Your Total is--",s-t)
else:
    t=s/100*9.5
    print("Your Tax is--",t,"Your Total is--",s-t)
    
