import java.util.InputMismatchException;
import java.util.Scanner;
public class exceptions{
    public static void main(String[] args) {
        Scanner input =new Scanner(System.in);
        int a,b;
       try {
            System.out.println("Enter 2 Numbers to Divide:");
            System.out.print("a=");
            a = input.nextInt();
            System.out.print("b=");
            b = input.nextInt();
            divide(a, b);
       } catch (InputMismatchException iException) {
           System.err.print(iException);
       }
    }

    public static int divide(int a, int b)
    throws ArithmeticException
    {
        return a/b;
    }
}