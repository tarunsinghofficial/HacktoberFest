package NumberSystem.OddEven;

import java.util.Scanner;

public class OddEven {
    public static void main (String args[])
    {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the Number you want to check");
        int n = in.nextInt();
        if(n%2 ==0)
        {
            System.out.println("Entered number is even");
        }
        else
        {
            System.out.println("Entered number is odd");
        }
    }
}
