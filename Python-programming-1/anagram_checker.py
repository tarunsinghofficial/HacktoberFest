# program to check anagram

from collections import Counter
 
def check(s1, s2):
   
    # implementing counter function
    if(Counter(s1) == Counter(s2)):
        print("The given strings are anagrams.")
    else:
        print("The given strings are not anagrams.")
 
s1 = input("Enter 1st word :")
s2 =  input("Enter 2nd word :")
check(s1, s2)
