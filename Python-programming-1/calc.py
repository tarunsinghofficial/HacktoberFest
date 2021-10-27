import re
Skip to content

Search…
All gists
Back to GitHub


@AzwanNF
@0x000000AC
0x000000AC/calculator.py
Last active 3 years ago • Report abuse
0
1
Code
Revisions 2
Forks 1
<script src = "https://gist.github.com/0x000000AC/4313589.js" > </script >
calculator.py
#!/usr/bin/env python
# This is a continuation of the my playing with python on the Raspberry
#    This program will functionally be a calculator that takes two different numeric imputs and then
#    prompts the user what they want to do with them, in a super-simple fashion.   The user enters
#     two numbers, which are saved as longs'.  Then, since I imported regular expressions, you can check
#     the input text to meet one of the if, elif conditionals below it.  For user input validation, I've
#     placed the first number and second numbers in a while loop that throws an exception for invalid input.


# The main loop that keeps the py script in its entirety going

goAgain = 1
while goAgain == 1:

    # The first value entered

    validity = True
    while validity == True:
        try:
            firstNumber = long(raw_input("Type the first number: "))
            validity = False  # If the user's input is good, exit the while loop
        except ValueError:
            print("That's not a valid number, please re-enter the value ")

    # The second value entered

    validity = True
    while validity == True:
        try:
            secondNumber = long(raw_input("Type the second number: "))
            validity = False  # If the user's input is good, exit the while loop
        except ValueError:
            print("That's not a valid number, please re-enter the value ")

    # This section performs the user's mathematical operation based on their text input

    mathChoice = str(raw_input("Add, subtract, multiply, or divide? "))

    if "add" in mathChoice.lower():
        print firstNumber, "added to", secondNumber, "equals", firstNumber + secondNumber
    elif "subtract" in mathChoice.lower():
        print firstNumber, "minus", secondNumber, "equals", firstNumber - secondNumber
    elif "multiply" in mathChoice.lower():
        print firstNumber, "times", secondNumber, "equals", firstNumber * secondNumber
    elif "divide" in mathChoice.lower():
        print firstNumber, "divided by", secondNumber, "equals", firstNumber / secondNumber

    # This keeps the while loop going or exits it based on the text you see
    goAgain = int(
        raw_input("Type 1 to enter more numbers, or any other number to quit: "))

print "Goodbye!\n"


@AzwanNF
Leave a comment
Tidak ada file yang dipilih
Attach files by dragging & dropping, selecting or pasting them.
© 2021 GitHub, Inc.
Terms
Privacy
Security
Status
Docs
Contact GitHub
Pricing
API
Training
Blog
About
