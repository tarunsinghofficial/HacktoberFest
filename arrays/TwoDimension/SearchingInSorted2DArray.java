/*
Given a row and column wise (n X m) sorted matrix.
Write a program to search a key in a given matrix.
 */
package arrays.TwoDimension;

import java.util.Scanner;

public class SearchingInSorted2DArray {
    Scanner sc = new Scanner(System.in);

//    Method to search the target in given matrix
    public void searchMatrix(int[][] matrix, int n, int target){
        int i = 0;
        int j = n - 1;
        while(i < n && j >= 0){
            if(matrix[i][j] == target){
                System.out.println(target + " Found at index " + i + " " + j);
                return;
            }
            if(matrix[i][j] > target){
                j--;
            }else{
                i++;
            }
        }
        System.out.println("Not Found");
    }
    public static void main(String[] args) {
        CreatingAndPrinting2DArray operationArray = new CreatingAndPrinting2DArray();
        SearchingInSorted2DArray search = new SearchingInSorted2DArray();
        System.out.println("Value of n");
        int n = search.sc.nextInt();
        int[][] matrix = new int[n][n];
        System.out.println("Enter the matrix : ");
        matrix = operationArray.readArray(matrix, n, n);
//        System.out.println("Given Matrix is : ");
//        operationArray.printArray(matrix);
        System.out.println("Enter the Target Value : ");
        int target = search.sc.nextInt();
        search.searchMatrix(matrix, n, target);



    }
}
