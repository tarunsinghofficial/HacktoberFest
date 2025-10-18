import java.util.Random;

public class Assignment
{
    public static void main(String[] args)
    {
        int[][] matrixA =new int[2][2];
        int[][] matrixB =new int[2][2];
        int[][] matrixC =new int[2][2];
        
        Random randomNum = new Random();
        
        //Matrix A initialization
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                matrixA[i][j] = randomNum.nextInt(10);
            }
        }
        
        //Matrix B initialization
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                matrixB[i][j] = randomNum.nextInt(10);
            }
        }
        
        //Multiplication
        for (int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 2; j++)
            {
                matrixC[i][j] = 0;
                for(int k = 0; k < 2; k++)
                {
                    matrixC[i][j] += (matrixA[i][k] * matrixB[k][j]);
                }
            }
        }
        
        //Output
        System.out.println("\nThe Product of The 2 Random Matrices Is:");
        for ( int i = 0; i < 2; i++)
        {
            System.out.print("(\t");
            for ( int j = 0; j < 2; j++)
            {
                System.out.printf("%d \t", matrixC[i][j]);
                
            }
            System.out.print(")\n");
        }
    }
}