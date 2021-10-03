### Karan Kakkar

- Photo: https:https://avatars1.githubusercontent.com/u/64869661?s=60&v=4
- Location: India
- Github: https://github.com/KaranKakkar22

***
import random print('I am thinking of a number between 1 and 20(both included)')
no=random.randint(1,20)
n=0 while n<10:
print("Take a guess.")
guess=int(input())
n+=1 if guess==no:
print("Good job! You guessed my number in ",n," guesses!")
break elif guess<no:
print("Your guess is too low.")
else:
print("Your guess is too high")
if n>=10:
print("Nope. the number i was thinking was",no)
    
