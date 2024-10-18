from copy import deepcopy
from typing import List

class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        res = []  # To store all possible solutions
        nq = [['.'] * n for _ in range(n)]  # Initialize empty board
        qx, qy = [], []  # Lists to track queen positions

        # Check if a queen can be placed at board[i][j]
        def check(i, j, qx, qy, n):
            if i >= n or j >= n:
                return False
            if i in qx or j in qy:  # Row or column check
                return False
            for k in range(len(qx)):  # Diagonal check
                if i + j == qx[k] + qy[k] or i - j == qx[k] - qy[k]:
                    return False
            return True

        # Backtracking function to place queens row by row
        def nqueens(row, nq, n, qx, qy):
            if row == n:
                res.append(deepcopy(nq))  # Append the valid board configuration
                return
            for col in range(n):
                if check(row, col, qx, qy, n):
                    qx.append(row)
                    qy.append(col)
                    nq[row][col] = 'Q'  # Place queen
                    nqueens(row + 1, nq, n, qx, qy)  # Recurse to next row
                    nq[row][col] = '.'  # Backtrack
                    qx.pop()
                    qy.pop()
            return

        nqueens(0, nq, n, qx, qy)
        return res  # Return the list of board configurations with queens

# Example usage
n = 8
solution = Solution()
result = solution.solveNQueens(n)
for board in result:
    for row in board:
        print(row)
    print()
