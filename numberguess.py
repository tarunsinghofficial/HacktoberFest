#Viresh Solanki
print("Welcome to my game")
guess=0
print("Number of guesses we provided to you is 9")
number=18
while(guess<9):
    number_guess=int(input("Enter the guessed number:"))
    guess=guess+1
    if(number_guess<number):
        print("your number is less than the actual number and kindly increase it !!!!",number_guess)
        continue
    elif(number_guess>number):
        print("your number is bigger than the actual number and kindly decrease it !!!!",number_guess)
        continue
    elif(number_guess==number):
        print("you guessed right",number_guess)
        break
    elif(guess>9):
        print("game over")
print("the guesses left you have",9-guess)
print("total guesses you took",guess)



