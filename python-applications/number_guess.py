from random import *


def start_message():
    print("************************************************************")
    print("**    You have to guess number (Hint: in between 1-100)   **")
    print("************************************************************")
    print()


def random_number():
    number = round(random() * 100)
    if (number):
        return number
    else:
        random_number()


def try_to_find_number(number, user):

    if (number == user):
        print("Well done!")
        print("You found it!")
        print("Goodbye!")
        return
    elif (number < user):
        print("Is lower than that one, lets try again!")
        user = eval(input("Lets try to find number imagined >> "))
        try_to_find_number(number, user)
    else:
        print("Is higher than that one, lets try again!!")
        user = eval(input("Lets try to find number imagined >> "))
        try_to_find_number(number, user)
    return user


def main():
    number = random_number()
    start_message()
    user = eval(input("Lets try to find number imagined >> "))
    try_to_find_number(number, user)


main()
