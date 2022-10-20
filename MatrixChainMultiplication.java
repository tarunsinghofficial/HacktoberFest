
//                                                          PRE STRIVER VIDEO 

// import java.util.*;
// class MatrixChainMultiplication{
//     int max = 0;
//     public static void main(String args[]){
//         Scanner sc = new Scanner(System.in);
//         int n , i;
//         n = sc.nextInt();
//         int[] arr = new int[n+1];
//         for(i=0;i<=n;i++){
//             arr[i] = sc.nextInt();
//         }
//         MatrixChainMultiplication obj = new MatrixChainMultiplication();
//         System.out.println(obj.MaxMultiple(arr, 1, n-1));

//     }

//     int MaxMultiple(int[] arr, int i , int j){
//         if(Math.abs(i-j)==1){
//             return (arr[i-1]*arr[i]*arr[j]);
//         }
//         else    
//             return max + MaxMultiple(arr, i+1, j);

//     }
// }

//                                                            POST STRIVER VIDEO

import java.util.*;

class MatrixChainMultiplication {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n;
        n = sc.nextInt();
        int[] arr = new int[n + 1];
        int[][] dp = new int[n + 1][n + 1];
        for (int i = 0; i <= n; i++) {
            arr[i] = sc.nextInt();
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = -1;
            }
        }
        MatrixChainMultiplication obj = new MatrixChainMultiplication();
        int max = obj.MaxMultiple(arr, 1, n, dp);
        System.out.println(max);
    }

    int MaxMultiple(int[] arr, int i, int j, int[][] dp) {
        int k, sum;
        int max = 999999999;
        if (i == j) {
            return 0;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        else {
            for (k = i; k < j; k++) {
                sum = (arr[i - 1] * arr[k] * arr[j]) + MaxMultiple(arr, i, k, dp) + MaxMultiple(arr, k + 1, j, dp);
                max = Math.min(max, sum);
                dp[i][j] = max;
            }
            return max;
        }
    }
}