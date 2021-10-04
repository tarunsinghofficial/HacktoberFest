def PALINDROME():
        print("_____________________________________________")
        print()
        print("Welcome,")
        print()
        n = int(input("Enter a number you want to check for Palindrome ------>"))
        temp = n
        rev=0
        while n>0:
                dig=n%10
                rev=rev*10+dig
                n //= 10
        if temp == rev:
            print()
            print("Its a palindrome !!!!!")
        else:
            print()
            print("Its not a palindrome ............")
        print("_____________________________________________")

        print()
        input("Press enter to continue :")
        
PALINDROME()
