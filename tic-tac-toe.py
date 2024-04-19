
from random import choice #To select who will play first between player and computer
from time   import sleep  #

print("********GIVE STAR ONLY IF YOU LIKE********")
print()
#welcome display
def Welcome():
    print('   ****Welcome to tic-tac-toe game****')
    #dont take sleep more than 2 seconds then user will get bored
    sleep(1)
    print()
    print('Computer will decide who will play first')
    print()
    #for Hint Feature In Computer AI i have passed Player letter instead of computer letter
    print('If you need Hint in the middle of game \npress any of this [Hint,hint,H,h]')
    sleep(1)
    print()
    print('''      ******* Format of Game ******
          |    |         1 | 2 | 3
       - - - - - -      - - - - - - 
          |    |         4 | 5 | 6
       - - - - - -      - - - - - - 
          |    |         7 | 8 | 9
                                           ''')


#Fuction to draw Board
#you can modify this sleep method if you dont need it
def DrawBoard(board,NeedSleep=True):
    #I thought for hint u dont need sleep method so i given default value for Needsleep 
    if NeedSleep:
        sleep(1)
    print()
    print('             '+board[1]+'  |  '+board[2]+'  |  '+board[3])
    print('             - - - - - - - ')
    print('             '+board[4]+'  |  '+board[5]+'  |  '+board[6])
    print('             - - - - - - - ')
    print('             '+board[7]+'  |  '+board[8]+'  |  '+board[9])
    print()

#asking the player to choose thier Letter  (X or O)
def InputPlayerLetter():
    letter=''
    #Ask untill user enters x or o
    while not(letter == 'X' or letter == 'O'):
        print('Do you want to be X or O')
        letter = input().upper()
     
    #returning list bcz of later use
    if letter == 'X':
      return ['X','O']
    if letter == 'O':
      return ['O','X']

#Deciding who should play first randomly
#in usual tic-tac-toe games player first,but it selects randomly between computer and player
def WhoFirst():
    opponents = ['computer','player']
    if choice(opponents) == 'computer':
        return 'computer'
    else :
        return 'player'
        
#this function asks player to play again
def PlayAgain():
    print()
    print('Do you want to Play Again (y or n)')
    playagain = input().lower().startswith('y')
    return playagain

#function for making move
def MakeMove(board,letter,move):
    board[move] = letter

#check if any one win,returns True if wins
#In tic-tac-toe there are 8 possibilities of winning
#horizontal => 3 | vertical => 3 | diagonal => 2
def IsWinner(board,letter):
    return ( (board[7] == letter and board[8] == letter and board[9] == letter ) or
             (board[4] == letter and board[5] == letter and board[6] == letter ) or
             (board[1] == letter and board[2] == letter and board[3] == letter ) or
             (board[1] == letter and board[4] == letter and board[7] == letter ) or
             (board[2] == letter and board[5] == letter and board[8] == letter ) or
             (board[3] == letter and board[6] == letter and board[9] == letter ) or
             (board[1] == letter and board[5] == letter and board[9] == letter ) or
             (board[3] == letter and board[5] == letter and board[7] == letter )  )

#duplicate board is useful when we wanted to make temporary changes to the temporary copy of the board without changing the original board
def GetBoardCopy(board):
    DupeBoard = []
    for i in board:
        DupeBoard.append(i)
    return DupeBoard
    
#fuction to check is space is free
def IsSpaceFree(board,move):
    return board[move] == ' '

#Getting the player move
def GetPlayerMove(board):
    move = ''
 
    while move not in '1 2 3 4 5 6 7 8 9'.split() or not IsSpaceFree(board,int(move)):
        print()
        print('Enter your move (1 - 9)')
        move = input()
        #if player wants Hint
        if move in HintInput:
            return move
            break  
    return int(move)

#choose random move from given list
#it is used when AI  wants to choose out of many possibilities
def ChooseRandomFromList(board,MoveList):
    PossibleMoves = []
    for i in MoveList:
        if IsSpaceFree(board,i):
            PossibleMoves.append(i)
    if len(PossibleMoves) != 0:
        return choice(PossibleMoves)
    else:
        return None

#creating computers AI
#this ai works on this algorithm
#1.it checks if computer can win in next move,else
#2.it checks if player can win in next move,then it blocks it,else
#3.it chooses any available spaces from the corner[1,3,7,9],else
#4.it fills middle square if space free,else
#5.it chooses any available spaces from sides,ie,[2,4,6,8]
#if you interchange the 3 and 4 steps the AI becomes little Hard,ie,it fills middle then corner
#--------------------------------------
#Get computer move
def GetComputerMove(board,ComputerLetter):
    if ComputerLetter == 'X':
        PlayerLetter = 'O'    
    else:
       PlayerLetter = 'X'

    #1.check computer can win in next move
    for i in range(1,10):
        copy = GetBoardCopy(board)
        if IsSpaceFree(copy,i):
            MakeMove(copy,ComputerLetter,i)
            if IsWinner(copy,ComputerLetter):
                return i


    #2.check player can win in next move
    for i in range(1,10):
        copy = GetBoardCopy(board)
        if IsSpaceFree(copy,i):
            MakeMove(copy,PlayerLetter,i)
            if IsWinner(copy,PlayerLetter):
                return i

    #3.checking for corner
    move = ChooseRandomFromList(board,[1,3,7,9])
    if move != None:
        return move
        
    #4.checking for the center
    if IsSpaceFree(board,5):
        return 5
        
    #5.checking for sides
    return ChooseRandomFromList(board,[2,4,6,8])
    
#---------------------------------------   

#checking board is full or not
def IsBoardFull(board):
    for i in range(1,10):
        if IsSpaceFree(board,i):
            return False
    return True
            
#fuction to print  the final win or tie board
#made this to separate usual board and winning or tie board
def FinalBoard(board,NeedSleep=True):
    print('            |-------------|')
    DrawBoard(board,NeedSleep)
    print('            |-------------|')

                    
#LETS START THE GAME
Welcome()
while True:
    #intialising board
    TheBoard = [' '] * 10
    PlayerLetter,ComputerLetter = InputPlayerLetter()
    turn = WhoFirst()
    print(f'The {turn} will go first')
    
    #gameloop
    Playing = True
    while Playing:
        
        if turn == 'player':
            print(f"    Turn => {turn}") 
            HintInput = ['Hint','hint','H','h'] 
            #taking players input
            move = GetPlayerMove(TheBoard)
            #if player needs Hint
            while move in HintInput:                
                #following code gives hint to the user
                #it runs player letter to computer AI
                HintBox = []
                for i in TheBoard:
                    HintBox.append(i)
                hint = GetComputerMove(HintBox,PlayerLetter)
                MakeMove(HintBox,PlayerLetter,hint)
                print(f'HINT : placing at {hint} is better')
                FinalBoard(HintBox,False)
                move = GetPlayerMove(TheBoard)
              
            MakeMove(TheBoard,PlayerLetter,move)
            
            
            if IsWinner(TheBoard,PlayerLetter):
                FinalBoard(TheBoard)                
                print('❤You have WON the game❤')
                Playing = not Playing
            elif IsBoardFull(TheBoard):
                FinalBoard(TheBoard)
                print('The game is TIE\nIts good to PLAY untill you WIN❤')
                Playing = not Playing
            else :
                DrawBoard(TheBoard)
                turn = 'computer'
 
        else :
            #computer move
            print(f"    Turn => {turn}")
            move = GetComputerMove(TheBoard,ComputerLetter)
            MakeMove(TheBoard,ComputerLetter,move)
            
            
            if IsWinner(TheBoard,ComputerLetter):
                FinalBoard(TheBoard)
                print('❤Try again bro you will win❤')
                Playing = not Playing
            elif IsBoardFull(TheBoard):
                FinalBoard(TheBoard)
                print('The game is TIE\nIts good to PLAY untill you WIN❤')
                Playing = not Playing
            else :
                DrawBoard(TheBoard)
                turn = 'player'

    if not PlayAgain():
        print("********❤GIVE STAR ONLY IF YOU LIKE❤********")
        break
