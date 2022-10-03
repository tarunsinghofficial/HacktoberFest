#include <iostream>
using namespace std;

bool isValid(char sudoku[9][9], int row, int col, char c)
{
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[i][col] == c)
            return false;

        if (sudoku[row][i] == c)
            return false;

        if (sudoku[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            return false;
    }

    return true;
}

bool sudokuSolver(char sudoku[9][9])
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (sudoku[row][col] == '.')
            {
                for (char c = '1'; c <= '9'; c++)
                {
                    if (isValid(sudoku, row, col, c))
                    {
                        sudoku[row][col] = c;

                        if (sudokuSolver(sudoku))
                            return true;

                        sudoku[row][col] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void printSudoku(char sudoku[9][9])
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            cout << sudoku[row][col] << " ";
            if ((col + 1) % 3 == 0 && col != 8)
                cout << "| ";
        }
        cout << endl;
        if ((row + 1) % 3 == 0 && row != 8)
            cout << "------ ------- ------" << endl;
    }
}

int main()
{
    char sudoku[9][9] = {{'.', '.', '5', '8', '.', '.', '6', '.', '.'},
                         {'6', '.', '8', '2', '.', '4', '9', '.', '7'},
                         {'.', '.', '.', '.', '5', '.', '1', '2', '.'},
                         {'.', '3', '.', '.', '.', '.', '.', '1', '9'},
                         {'.', '.', '1', '6', '.', '8', '7', '.', '.'},
                         {'2', '9', '.', '.', '.', '.', '.', '6', '.'},
                         {'.', '5', '3', '.', '8', '.', '.', '.', '.'},
                         {'7', '.', '9', '5', '.', '2', '3', '.', '4'},
                         {'.', '.', '2', '.', '.', '7', '5', '.', '.'}};

    if (sudokuSolver(sudoku))
        printSudoku(sudoku);
    else
        cout << "Invalid Sudoku - No solution....." << endl;

    return 0;
}

// char sudoku[9][9] = {{'.', '.', '5', '8', '.', '.', '6', '.', '.'},
//                          {'6', '.', '8', '2', '.', '4', '9', '.', '7'},
//                          {'.', '.', '.', '.', '5', '.', '1', '2', '.'},
//                          {'.', '3', '.', '.', '.', '.', '.', '1', '9'},
//                          {'.', '.', '1', '6', '.', '8', '7', '.', '.'},
//                          {'2', '9', '.', '.', '.', '.', '.', '6', '.'},
//                          {'.', '5', '3', '.', '8', '.', '.', '.', '.'},
//                          {'7', '.', '9', '5', '.', '2', '3', '.', '4'},
//                          {'.', '.', '2', '.', '.', '7', '5', '.', '.'}};
//
