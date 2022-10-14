const placeWordInCrossword = function (board, word) {
    const m = board.length, n = board[0].length, dirs = [[0, 1], [1, 0], [0, -1], [-1, 0]];
    const invalid = (x, y) => { // check if the given cell is invalid
        return x < 0 || y < 0 || x === m || y === n || board[x][y] === "#";
    };
    const dfs = (x, y, char, dir) => {
        if (char === word.length) {
            return invalid(x, y)
        }; // word found, current cell must be invalid
        if (invalid(x, y) || (board[x][y] !== " " && board[x][y] !== word[char])) {
            return false;
        }
        return dfs(x + dir[0], y + dir[1], char + 1, dir);
    };
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (board[i][j] === "#" || (board[i][j] !== " " && board[i][j] !== word[0])) {
                continue;
            }

            for (const dir of dirs) {
                const [x, y] = [i - dir[0], j - dir[1]];
                // previous cell must be invalid and current cell must be starting point
                if (invalid(x, y) && dfs(i, j, 0, dir)) return true;
            }
        }
    }
    return false;
};
