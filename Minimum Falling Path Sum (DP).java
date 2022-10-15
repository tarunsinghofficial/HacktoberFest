class Solution {
    public int minFallingPathSum(int[][] matrix) {
        
        int ans = Integer.MAX_VALUE;
        for(int cc=0; cc<matrix.length; cc++) { // loop cuz first row se bhi koi bhi element le skte hain
            
            int[][] cache = new int[matrix.length][matrix.length];
            for(int[] row : cache) {
                Arrays.fill(row, -1);
            }
            
            ans = Math.min(ans, sol(matrix, 0, cc, matrix.length - 1, matrix.length - 1, cache));    //since its n*n matrix
        }
        return ans;
        // return sol(matrix, 0, 0, matrix.length - 1, matrix.length - 1);
    }
    
    public int sol(int[][] matrix, int cr, int cc, int er, int ec, int[][] cache) {
        
        if(cr > er || cc > ec || cc < 0) {
            return Integer.MAX_VALUE;
        }
        
        if(cr == er) {  //base case
            return matrix[cr][cc];
        }
        
        if(cache[cr][cc] != -1) {
            return cache[cr][cc];
        }
        
        int c1 = sol(matrix, cr + 1, cc - 1, er, ec, cache);   // left diagonal
        int c2 = sol(matrix, cr + 1, cc, er, ec, cache);   // down
        int c3 = sol(matrix, cr + 1, cc + 1, er, ec, cache);   // right diagonal
        
        return cache[cr][cc] = Math.min(c1, Math.min(c2, c3)) + matrix[cr][cc];
    }
}
