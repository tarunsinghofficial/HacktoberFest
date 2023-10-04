#Some parts have been commented out due to a bug in pip installation of playsound. If you have playsound installed , please remove the comments
import random,string
#from playsound import playsound
board={
        1:' ',2:' ',3:' ',
        4:' ',5:' ',6:' ',
        7:' ',8:' ',9:' '
        }
def printboard(brd):
    print(brd[1] +'|'+brd[2]+'|'+brd[3])
    print('-+-+-')
    print(brd[4] +'|'+brd[5]+'|'+brd[6])
    print('-+-+-')
    print(brd[7] +'|'+brd[8]+'|'+brd[9])
def checkwinner(board):
    if board[1]==board[2]==board[3] !=' ':
        return 1
    elif board[4]==board[5]==board[6]!=' ':
        return 1
    elif board[7]==board[8]==board[9]!=' ':
        return 1
    elif board[1]==board[5]==board[9]!=' ':
        return 1
    elif board[7]==board[5]==board[3]!=' ':
        return 1
    elif board[3]==board[6]==board[9]!=' ':
        return 1
    elif board[1]==board[4]==board[7]!=' ':
        return 1
    elif board[2]==board[5]==board[8]!=' ':
        return 1
def checkdraw(b):
   if b[1]!=' '  and b[2]!=' ' and b[3]!=' ' and b[4]!=' ' and b[5]!=' ' and b[6]!=' ' and b[7]!=' ' and b[8]!=' ' and b[9]!=' ':
       return 2
print('''
The general layout of the board is given below:-
1|2|3
-+-+-
4|5|6
-+-+-
7|8|9
,Where the values of boxes will be used in the program.
I.E. You need to enter 1 to put your sign in 1st box, 5 in 5th box as per above figure. Enjoy!
*To use sound, install the playsound module first. Guide can be found in the readme file.
''')
#This part is commented out because the playsound module is not being able to be installed due to an internal error with pip.
#If you have playsound module installed , please remove the multiline comments to use sound
'''
Sound=str(input("Do you want to play sound(Needs Playsound Module to be installed) . Use Y/N : "))
if Sound.upper()=='Y' or Sound.upper()=='YES':
    Sound=True
elif Sound.upper()=='N' or Sound.upper()=='NO':
    sound=False
else:
    print("Wrong Value entered for sound. Program will be terminated")
    quit()
'''
v=input("Choose your sign :- X or O . If you choose X , you go first and Vice versa for O : ")
v=v.upper()
if v=='X':
    w='O'
    c=1
elif v=='O':
    w='X'
    c=0
else:
    print("Incorrect value of sign given . Program will be terminated")
    '''
    if Sound==True:
        playsound('program_error.mp3')
    '''
    quit()

y=0
check=0
try:
    while y!=1 and check!=2:
        while c<=10:
            if c%2!=0:
                x=int(input("Where do you want to place your sign : "))     
                if x in range(10):
                    if board[x]==' ' :
                        board[x]=v
                        print("Your turn:-",end='\n')
                        printboard(board)
                        y=checkwinner(board)
                        check=checkdraw(board)
                        if y==1:
                            print("You have won!")
                            '''
                            if Sound==True:
                                playsound('Win.wav')
                            '''
                            quit()
                        elif check==2 and y!=1:
                            print(" It is a draw")
                            '''
                            if Sound==True:
                                playsound('boing.mp3')
                            '''
                            quit()
                    else:
                        print("Place is occupied")
                        '''
                        if Sound==True:
                            playsound('program_error.mp3')
                        '''
                        continue
                else:
                    print("Enter value of x in between 1-9")
                    continue
                    
                c+=1
            else:
                x=random.randint(1,9)
                if board[x]==' ':
                    board[x]=w
                    print("computer's turn:-",end='\n')
                    printboard(board)
                    c+=1          
                else:
                    continue
                               
                y=checkwinner(board)
                check=checkdraw(board)
                if y==1:
                    print("The computer has beaten you")
                    '''
                    if Sound==True:
                        playsound('Loss.wav')
                    '''
                    quit()
                
                elif check==2 and y!=1:
                    print("It is a draw")
                    '''
                    if Sound==True:
                        playsound('boing.mp3')
                    '''    
                    quit()
                
except ValueError:
    print("You have entered a non-integral value of x. Program is terminated")
    '''
    if Sound==True:
        playsound('program_error.mp3')
    '''
