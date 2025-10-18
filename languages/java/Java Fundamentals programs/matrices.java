import java.util.Scanner;

public class matrices{
    public static void main(String[] args) {
        Scanner input =new Scanner(System.in); //scanner object
        int m,n,x,y;

        //Input of matrice order:
        System.out.println("---Matrice Multiplication---\n");
        System.out.println("Enter Order of 1st Matrix:");
        System.out.print("m=");
        m=input.nextInt();
        System.out.println("by");
        System.out.print("n=");
        n = input.nextInt();
        System.out.println("\nEnter Order of 2nd Matrix:");
        System.out.print("m=");
        x = input.nextInt();
        System.out.println("by");
        System.out.print("n=");
        y = input.nextInt();

        //2-dimensional array declarations, that act as the matrices:
        int[][] A =new int[m][n];
        int[][] B =new int[x][y];
        int[][] C =new int[m][y];

        if (n==x){

            System.out.println("\nEnter The Values of 1st Matrix:");
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    A[i][j]=input.nextInt();
                }
            }

            System.out.println("\nEnter The Values of 2nd Matrix:");
            for(int i=0;i<x;i++){
                for(int j=0;j<y;j++){
                    B[i][j]=input.nextInt();
                }
            }

            for (int i=0;i<m;i++){
                for(int j=0;j<y;j++){
                    C[i][j]=0;
                    for(int k=0;k<x;k++){
                        C[i][j] += (A[i][k] * B[k][j]);
                    }
                }
            }

            System.out.println("\nThe Product of The 2 Matrices Is:");
            for(int i=0;i<m;i++){
                System.out.print("(\t");
                for(int j=0;j<y;j++){
                    System.out.printf("%d \t", C[i][j]);

                }
                System.out.print(")\n");
            }

        } else{
            System.out.printf("\nERROR! Matrix Order Mismatch.\nYou can't multiply a %d by %d matrix and a %d by %d matrix.\n", m,n,x,y);
        }
    }
}