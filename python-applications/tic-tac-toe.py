def print_board(board):
    for row in board:
        print(" | ".join(row))
        print("-" * 5)

def check_winner(board, player):
    # Check rows and columns
    for i in range(3):
        if all(board[i][j] == player for j in range(3)) or all(board[j][i] == player for j in range(3)):
            return True

    # Check diagonals
    if all(board[i][i] == player for i in range(3)) or all(board[i][2 - i] == player for i in range(3)):
        return True

    return False

def play_tic_tac_toe():
    board = [[" " for _ in range(3)] for _ in range(3)]
    players = ["X", "O"]
    turn = 0

    while True:
        print_board(board)
        player = players[turn % 2]

        row = int(input(f"Player {player}, choose a row (0, 1, 2): "))
        col = int(input(f"Player {player}, choose a column (0, 1, 2): "))

        if board[row][col] == " ":
            board[row][col] = player 

            if check_winner(board, player):
                print_board(board)
                print(f"Player {player} wins!")
                break
            elif all(board[i][j] != " " for i in range(3) for j in range(3)):
                print_board(board)
                print("It's a tie!")
                break

            turn += 1
        else:
            print("That slot is already occupied! Try again.")

if __name__ == "__main__":
    play_tic_tac_toe()
