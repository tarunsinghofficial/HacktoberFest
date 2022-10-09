public class NQueens {

    public static void nQueens(char[][] board, int row) {
        if(row == board.length){
            printBoard(board);
            return;
        }
        for (int i = 0; i < board.length; i++) {
            if(isSafe(board,row,i)){
                board[row][i] = 'Q'; // Placing Queen
                nQueens(board, row+1); // Call for next Queen
                board[row][i] = 'x'; // Backtracking if Condition not satisfying.... Queens attack each other
            }
        }
    }

    public static boolean isSafe(char[][] board,int row, int col) {
        //For Up Rows

        for (int i = row-1; i >= 0; i--) {
            if(board[i][col] == 'Q'){
                return false;
            }
        }

        // for Left up diagonal

        for (int i = row-1, j=col-1 ; j >= 0 && i >=0; j--,i--) {
            if(board[i][j]=='Q'){
                return false;
            }
        }

        // for right Up diagonal

        for (int j = col+1, i = row-1; j<board.length && i >= 0; j++,i--) {
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }

    public static void printBoard(char[][] board) {
        System.out.println("----------BOARD----------");
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board.length; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String args[]) {
        int n = 1;

        char board[][] = new char[n][n];

        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board.length; j++) {
                board[i][j] ='x';
            }
        }
        nQueens(board, 0);
    }
}
