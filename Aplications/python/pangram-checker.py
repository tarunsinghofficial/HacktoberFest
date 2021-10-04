def Pangram():
    print()
    from string import ascii_lowercase as asc_lower
    print("_______________________________________")
    print()
    def check(s):
        return set(asc_lower) - set(s.lower())== set([])
    st = input("Enter the string you want to check for Pangram --->")
    if (check(st) == True):
        print()
        print("The string is a pangram !!!!.")
    else:
        print()
        print("The string isn't a Pangram.")

    print()
    print("_______________________________________")
    print()

    print()
    input("Press enter to continue :")
    
   Pangram()
