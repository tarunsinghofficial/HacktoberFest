## 8 Queen Problem from leet code : https://leetcode.com/problems/n-queens/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));

        solveNQueensHelper(board, 0, result);
        return result;
    }

private:
    void solveNQueensHelper(vector<string>& board, int row, vector<vector<string>>& result) {
        if (row == board.size()) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < board.size(); col++) {
            if (isSafe(board, row, col)) {
                board[row][col] = 'Q';
                solveNQueensHelper(board, row + 1, result);
                board[row][col] = '.';
            }
        }
    }

    bool isSafe(const vector<string>& board, int row, int col) {
        // Check the current column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // Check upper left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // Check upper right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }
};

int main() {
    int n = 4;
    Solution solution;
    vector<vector<string>> solutions = solution.solveNQueens(n);

    for (const vector<string>& sol : solutions) {
        for (const string& row : sol) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
