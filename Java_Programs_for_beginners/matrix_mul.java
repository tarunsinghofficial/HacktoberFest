import java.util.Scanner;

public class matrix_mul {
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the size of matrix");
        int n=sc.nextInt();
        System.out.println("Enter the elements of the first matrix");
        int a[][]=new int[n][n];
        int b[][]=new int[n][n];
        int c[][]=new int[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                a[i][j]=sc.nextInt();
            }
        }
        System.out.println("Enter the elements of the second matrix");
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                b[i][j]=sc.nextInt();
            }
        }
        System.out.println("Multiplication of both matrix=");
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                c[i][j]=a[i][0]*b[0][j]+a[i][1]*b[1][j]+a[i][2]*b[2][j];
                System.out.print(c[i][j]+" ");
            }
            System.out.println();
        }
        sc.close();
    }
}
