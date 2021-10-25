num1 = input('Enter First Number: ')
num2 = input('Enter Second Number: ')

print("Value of num1 before swapping: ", num1)
print("Value of num2 before swapping: ", num2)

x=int(input("Enter 1 for swapping using temporary variable and 0 for without temp variable"))
if x==1:
  # swapping two numbers using temporary variable
  temp = num1
  num1 = num2
  num2 = temp
elif x==0:
  # swapping two numbers ithout using temporary variable
  num1,num2=num2,num1
else:
  print("Invalid input")
print("Value of num1 after swapping: ", num1)
print("Value of num2 after swapping: ", num2)
