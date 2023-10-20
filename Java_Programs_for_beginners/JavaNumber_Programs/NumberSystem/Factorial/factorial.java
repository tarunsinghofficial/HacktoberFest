import java.util.*;

public class factorial {
    public static void main (String args []){
        Scanner in = new Scanner (System.in);
        System.out.println ("Enter the number");
        int n = in.nextInt();
        int fact = 1;
        for (int i = n; i >= 1; i--){
            fact = fact * i;
        }
        System.out.println("Factorial of Number :"+fact);
    }
}