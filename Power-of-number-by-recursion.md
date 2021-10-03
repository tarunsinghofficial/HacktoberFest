# Python code to find the power of a number using recursion

# defining the function to find the power

# function accpets base (x) and the power (y)

# and, return x to the power y

def pow(x, y):
if y == 1:
return x else:
return pow(x, y-1) * x

# main code

if __name__ == '__main__':
x = 2 #base y = 3 #power result = pow(x, y)
print(x," to the power ", y, " is: ", result)

    x = 10 #base
    y = 3  #power
    result = pow(x, y)
    print(x," to the power ", y, " is: ", result)
    
    x = 12 #base
    y = 5  #power
    result = pow(x, y)
    print(x," to the power ", y, " is: ", result)
