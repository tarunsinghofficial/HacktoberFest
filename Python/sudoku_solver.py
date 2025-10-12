# sudoku_solver.py
# Hacktoberfest 2025 Contribution
# Interactive Sudoku Solver using Backtracking
# Sudoku Solver with Random Board Generation 


import random

print("Sudoku solver started...")  # Confirm the program is running

def can_place(board, row, col, number):
    for i in range(9):
        if board[row][i] == number or board[i][col] == number:
            return False

    start_row = 3 * (row // 3)
    start_col = 3 * (col // 3)
    for i in range(3):
        for j in range(3):
            if board[start_row + i][start_col + j] == number:
                return False

    return True

def solve_sudoku(board):
    for row in range(9):
        for col in range(9):
            if board[row][col] == 0:
                for num in range(1, 10):
                    if can_place(board, row, col, num):
                        board[row][col] = num
                        if solve_sudoku(board):
                            return True
                        board[row][col] = 0
                return False
    return True

def print_board(board):
    for r in board:
        print(" ".join(str(num) for num in r))

def generate_random_board(empty_cells=40):
    """
    Generate a random Sudoku board with a given number of empty cells.
    """
    board = [[0]*9 for _ in range(9)]
    
    # Fill the diagonal 3x3 blocks first
    for k in range(0, 9, 3):
        fill_block(board, k, k)
    
    # Solve the partially filled board to get a valid full solution
    solve_sudoku(board)
    
    # Remove numbers to create empty cells
    count = empty_cells
    while count > 0:
        row = random.randint(0, 8)
        col = random.randint(0, 8)
        if board[row][col] != 0:
            board[row][col] = 0
            count -= 1
    return board

def fill_block(board, row, col):
    """
    Fill a 3x3 block with random numbers 1-9 without repetition
    """
    numbers = list(range(1, 10))
    random.shuffle(numbers)
    for i in range(3):
        for j in range(3):
            board[row + i][col + j] = numbers.pop()

if __name__ == "__main__":
    sudoku_board = generate_random_board(empty_cells=40)  # 40 cells empty
    print("Random Sudoku board generated (0 = empty cells):")
    print_board(sudoku_board)

    if solve_sudoku(sudoku_board):
        print("\nSudoku solved successfully:")
        print_board(sudoku_board)
    else:
        print("No solution exists for the generated board.")
