a=int(input('Enter Your Number'))
b=0
while a>0:
	d=a%10
	b=b+d
	a=a//10
	print('Sum is --',b)