/*
Given a matrix of m X n.
print the matrix in spiral form.
 */

package arrays.TwoDimension;

import java.util.Scanner;

public class printMatrixInSpiral {

    public void printSpiral(int[][] matrix){
        int row = matrix.length;
        int col = matrix[0].length;
        int i, k = 0, l = 0;
        while (k < row && l < col){
            for(i = l; i < col; i++){
                System.out.print(matrix[k][i] + " ");
            }
            k++;
            for(i = k; i < row; i++){
                System.out.print(matrix[i][col - 1] + " ");
            }
            col--;
            if(k < row){
                for(i = col - 1; i >= l; i--){
                    System.out.print(matrix[row - 1][i] + " ");
                }
                row--;
            }
            if(l < col){
                for(i = row - 1; i >= k; i--){
                    System.out.print(matrix[i][l] + " ");
                }
                l++;
            }
        }
    }


    public static void main(String[] args) {
        CreatingAndPrinting2DArray arrayOperation = new CreatingAndPrinting2DArray();
        printMatrixInSpiral spiral = new printMatrixInSpiral();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter M and N respectively");
        int m = sc.nextInt();
        int n = sc.nextInt();
        int[][] matrix = new int[m][n];
        System.out.println("Enter the Matrix : ");
        matrix = arrayOperation.readArray(matrix, m, n);
        System.out.println("Given Matrix is : ");
        arrayOperation.printArray(matrix);
        System.out.println("Matrix in Spiral Manner :");
        spiral.printSpiral(matrix);


    }
}
