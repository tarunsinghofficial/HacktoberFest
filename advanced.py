num1 = float(input("Enter first number: "))
op = (input("Enter operator: "))
num2 = float(input("Enter second number:" ))

if op == "+":
    print(num1 + num2)
elif op == "_":
    print(num1 - num2)
elif op == "/":
    print(num1 / num2)
elif op == "*":
    print(num1 * num2)
else:
    print("Invalid operator")
