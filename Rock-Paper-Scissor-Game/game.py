import random  # To let the computer pick a random hand

# Valindating hand number
def validate(hand):
    if hand < 0 or hand > 2:
        return False
    return True

# Function to print the hand picked by players
def print_hand(hand, name='Guest'):
    hands = ['Rock', 'Paper', 'Scissor']
    print(name + ' picked: ' + hands[hand])

# Judge function
def judge(player, computer):

    # Control flow
    if player == computer:
        return 'It is a tie! Try Again!!'
    elif player == 0 and computer == 1:
        return 'You loose! Better luck next time!'
    elif player == 1 and computer == 2:
        return 'You loose! Better luck next time!'
    elif player == 2 and computer == 0:
        return 'You loose! Better luck next time!'
    else:
        return 'Congratulations! You have won!!'

# Begin the game
print('---Starting the Rock-Paper-Scissor Game---')
player_name = input('Please enter your name: ')

# Let the player choose the hand
print('Pick a hand: (0: Rock, 1: Paper, 2: Scissor)')
player_hand = int(input('Please enter a number between 0 and 2: '))

# If player picks anything between 0 and 2
if validate(player_hand):
    computer_hand = random.randint(0, 2)

    # Calling the print_hand function
    print_hand(player_hand, player_name)
    print_hand(computer_hand, 'Computer')

    # Assigning the result by calling the judge function
    result = judge(player_hand, computer_hand)
    print('Result: ' + result)
else:
    print('Please enter a valid number.')
