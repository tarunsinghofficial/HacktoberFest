import java.util.Scanner;

public class MatrixMultiplication{
    public static void main(String[]args) {

        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();


        int a[][] = new int[n][n], b[][] = new int[n][n];

        a=matrix(a,n);
        b=matrix(b,n);

        int result[][]=multiply(a,b,n);

        print(result,n);

    }

    public static int[][] matrix(int a[][],int n) {
        int r[][]=new int[n][n];
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = sc.nextInt();
            }
        }
        return a;
    }

    public static int[][] multiply(int a[][],int b[][],int n){
        int result[][]=new int[n][n];

        for(int i=0;i<n;i++){ // row of result
            for(int j=0;j<n;j++){ // column of result

                for(int x=0;x<n;x++){ // column
                        result[i][j]+=a[i][x]*b[x][j];
                }
            }
        }

        return result;
    }

    public static void print(int res[][],int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                System.out.print(res[i][j]+" ");
            }
            System.out.println();
        }
    }
}
