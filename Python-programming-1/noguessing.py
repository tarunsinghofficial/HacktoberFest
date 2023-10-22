#game to guess the number
import random

while True:
    no=random.randint(0,15)
    for i in range(3):
        guess=int(input("Enter your guess: "))
        if guess==no:
            print("Guessed it correct")
            break
        else:
            if guess in (no-2,no-1,no+1,no+2):
                print("You are close!")
            else:
                print("Try again")
    print("the number was: ",no)
    c=input("Do you want to stop the game n/N: ")
    if c=='n' or c=='N':
        break
        