import java.util.Scanner;

public class factorial{

    static int fab(int n){

        if (n == 0 || n == 1)
            return 1;
        else
            return n *fab(n-1);

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Number :");
        int n = sc.nextInt();
        System.out.println("The factorial of " + n + " is :" + fab(n));
    }
}
