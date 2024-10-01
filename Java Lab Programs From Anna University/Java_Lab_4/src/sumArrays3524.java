import java.time.LocalDate;
import java.time.LocalTime;
import java.util.Scanner;

public class sumArrays3524 {
    static void arraySum(int[][] a, int[][] s, int rows, int cols) {
        // Calculate the sum of corresponding elements in two arrays
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                a[i][j] += s[i][j];
            }
        }
        System.out.println("Sum of two arrays is:");
        // Display the sum of arrays
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print(a[i][j] + " ");
            }
            System.out.println();
        }
    }

    static void colSumMax(int[][] x, int[][] y, int rows, int cols) {
        // Calculate the sum of arrays and sort based on column sum
        arraySum(x, y, rows, cols);
        int[] colsum = new int[cols];
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < rows; j++) {
                colsum[i] += x[j][i];
            }
        }
        int[] csindex = new int[cols];
        for (int j = 0; j < cols; j++) {
            csindex[j] = j;
        }
        for (int i = 0; i < cols - 1; i++) {
            for (int j = 0; j < cols - i - 1; j++) {
                if (colsum[j] > colsum[j + 1]) {
                    int temp = colsum[j];
                    colsum[j] = colsum[j + 1];
                    colsum[j + 1] = temp;

                    int temp1 = csindex[j];
                    csindex[j] = csindex[j + 1];
                    csindex[j + 1] = temp1;
                }
            }
        }
        System.out.println("The array after sorting based on column sum is:");
        // Display the sorted array
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print(x[i][csindex[j]] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        System.out.println("2021503524 - Mugundh J B");
        System.out.println("Date: " + LocalDate.now() + " Time: " + LocalTime.now());
        Scanner t = new Scanner(System.in);
        System.out.print("Enter the no. of rows: ");
        int r = t.nextInt();
        System.out.print("Enter the no. of columns: ");
        int c = t.nextInt();
        int[][] a1 = new int[r][c];
        int[][] a2 = new int[r][c];

        System.out.println("Enter the values of matrix 1:");
        // Input values for matrix 1
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                a1[i][j] = t.nextInt();
            }
        }

        System.out.println("Enter the values of matrix 2:");
        // Input values for matrix 2
        for (int k = 0; k < r; k++) {
            for (int l = 0; l < c; l++) {
                a2[k][l] = t.nextInt();
            }
        }

        colSumMax(a1, a2, r, c);
    }
}
