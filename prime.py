if number > 1:
    for itr in range(2, int(number/2)+1):
        if (number % itr) == 0:
            print(number, "is NOT a PRIME number")
            break
        else:
            print(number, "is a PRIME number") 
else:
    print(number, "is NOT a PRIME number")
