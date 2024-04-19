/*

Remember:
row(i) = ⬇️
Col(j) = ➡️

 */
package arrays.TwoDimension;

import java.util.Scanner;

public class CreatingAndPrinting2DArray {
    Scanner sc = new Scanner(System.in);

//    Method to read the Array.
    public int[][] readArray(int[][] array, int row, int col){
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                array[i][j] = sc.nextInt();
            }
        }
        return array;
    }

//    Method to Print the 2D array
    public void printArray(int[][] array){
        for(int i = 0 ; i < array.length; i++){
            for(int j = 0; j < array[i].length; j++){
                System.out.print(array[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        CreatingAndPrinting2DArray search = new CreatingAndPrinting2DArray();
        System.out.println("Enter Row And Column respectively :");
        int row = search.sc.nextInt();
        int col = search.sc.nextInt();
        int[][] array = new int[row][col];
        System.out.println("Enter Matrix : ");
        array = search.readArray(array, row, col);
        System.out.println("Given Matrix is : ");
        search.printArray(array);

    }
}
