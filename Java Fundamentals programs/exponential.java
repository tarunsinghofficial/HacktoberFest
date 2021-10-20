import java.util.Scanner;

public class exponential{
    public static void main(String[] args) {
        Scanner input =new Scanner(System.in);
        int num;
        System.out.println("Enter Number:");
        num=input.nextInt();
        System.out.println(expo(num));
    }

    static float expo(int n) {
        if (n<=1){
            return 1;
        } else{
            return ((1/fact(n)) + (1/fact(n-1)));
        }
    }

    static int fact(int x){
        if (x<=1){
            return 1;
        } else{
            return x * fact(x-1);
        }
    }
    
}