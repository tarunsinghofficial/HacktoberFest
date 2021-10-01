n1=int(input("1st number"))
n2=int(input("2nd number"))
opr=input("+ or - or / or *")
int ans=0

if (opr=="+"):
	ans = n1+n2

else if(opr == "-"):
	ans=n1-n2

else if(opr == "/"):
	ans = n1/n2

else:
	ans=n1*n2

print(ans)