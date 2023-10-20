import java.util.*;

public class larger {
    public static void main (String args[])
    {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the two number you want to compare");
        int a = in.nextInt();
        int b = in.nextInt();
        if(a>b)
        {
            System.out.println("Largest number :"+a);
        }
        else{
            System.out.println("Largest number :"+b);
        }
    }
}
