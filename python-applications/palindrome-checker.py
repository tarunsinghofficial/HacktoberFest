def palindrome():
    print("_____________________________________________")
    print("Welcome,")
    n = input("Enter a number or string you want to check for Palindrome ------>")
    if n == n[::-1]:
        print("Its a palindrome !!!!!")
    else:
        print("Its not a palindrome ............")
    print("_____________________________________________")


palindrome()
