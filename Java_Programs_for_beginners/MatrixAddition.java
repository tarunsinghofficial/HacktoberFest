// Program for adding two matirx


import java.util.Scanner;
public class MatrixAddition {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Welcome ! to addition program of matrix of same dimensions");
		System.out.print("Enter matrix type : ");
		int rows = sc.nextInt(), columns = sc.nextInt();
		
		int matrixA[][] = new int [rows][columns];
		int matrixB[][] = new int [rows][columns];
		
		System.out.println("Enter matrix A");
		for (int i=0; i<rows; i++) {
			for (int j=0; j<columns; j++) {
				matrixA[i][j] = sc.nextInt();
			}
		}
		System.out.println("Enter matrix B");
		for (int i=0; i<rows; i++) {
			for (int j=0; j<columns; j++) {
				matrixB[i][j] = sc.nextInt();
			}
		}
//		Calulation of matrix C
		int matrixC[][] = new int [rows][columns];
		for (int i=0; i<rows; i++) {
			for (int j=0; j<columns; j++) {
				matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
				}
			}
		
		System.out.println("Your matrix C is");
		for (int i=0; i<rows; i++) {
			for (int j=0; j<columns; j++) {
				System.out.print(matrixC[i][j]);
				System.out.print(" ");
			}System.out.println();
		}
	}
}

