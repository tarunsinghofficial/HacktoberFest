a = int(input('Enter First number : '))
b = int(input('Enter Second number : '))
c = int(input('Enter Third number : '))
def largest(a, b, c):
    if (a > b) and (a > c):
        largest_num = a
    elif (b > a) and (b > c):
        largest_num = b
    else:
        largest_num = c
    print("The largest of the 3 numbers is : ", largest_num)
def smallest(a, b, c):
    if (a < b) and (a < c):
        smallest_num = a
    elif (b < a) and (b < c):
        smallest_num = b
    else:
        smallest_num = c
    print("The smallest of the 3 numbers is : ", smallest_num)
largest(a, b, c)
smallest(a, b, c)
