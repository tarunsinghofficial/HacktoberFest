import java.util.Scanner;

public class Euclidgcd {
    \public static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b; 
            a = temp;  
        }
        return a; 
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the first number: ");
        int a = sc.nextInt();
        System.out.print("Enter the second number: ");
        int b = sc.nextInt();
        int result = gcd(a, b);
        System.out.println("GCD of " + a + " and " + b + " is: " + result);
    }
}
