#viresh solanki
import random
objects=['snake','water','gun']
chance=10
no_chances=0
computer_point=0
human_points=0
name=input("Enter your name:-")
print("\t\t\t\tsnake,water,gun\t\t\t\t")
while no_chances<chance:
    choice=input("Snake,water,gun:-")
    comp_choice=random.choice(objects)
    if choice==comp_choice:
        print("TIE!!")
    #user selects snake
    elif choice=="snake" and comp_choice=="gun":
        print("COMPUTER WIN")
        computer_point = computer_point + 1
        print(f"guesses\n{name}={choice}\ncomputer's={comp_choice}")
        print(f"computer point={computer_point}and {name} point={human_points}")
    elif choice=="snake" and comp_choice=="water":
        print(f"{name}YOU WIN")
        human_points=human_points+1
        print(f"guesses\n{name}={choice}\ncomputer's={comp_choice}")
        print(f"computer point={computer_point}and {name} point={human_points}")
    #user selects water
    elif choice=="water" and comp_choice=="snake":
        print("COMPUTER WIN")
        computer_point=computer_point+1
        print(f"guesses\n{name}={choice}\ncomputer's={comp_choice}")
        print(f"computer point={computer_point}and {name} point={human_points}")
    elif choice=="water" and comp_choice=="gun":
        print(f"{name} YOU WIN")
        human_points=human_points+1
        print(f"guesses\n{name}={choice}\ncomputer's={comp_choice}")
        print(f"computer point={computer_point}and {name} point={human_points}")
    #user selects gun
    elif choice=="gun" and comp_choice=="water":
        print("COMPUTER WIN")
        computer_point=computer_point+1
        print(f"guesses\n{name}={choice}\ncomputer's={comp_choice}")
        print(f"computer point={computer_point}and {name} point={human_points}")
    elif choice=="gun" and comp_choice=="snake":
        print(f"{name}YOU WIN")
        human_points=human_points+1
        print(f"guesses\n{name}={choice}\ncomputer's={comp_choice}")
        print(f"computer point={computer_point}and {name} point={human_points}")
    else:
        print("wrong input")
        no_chances = no_chances + 1
        print(f"chances left{chance-no_chances} and chances left{no_chances}")
        print("game over")
if(computer_point==human_points):
    print("TIE")
elif(computer_point>human_points):
    print(f"{name} better luck next time\nSORRY COMPUTER WON")

else:
    print(f"{name} YOU WON\n CONGRATULATION")
print(f"{name} points={human_points} and computer points={computer_point}")


