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



##exponent program using power function by math class in util package.
public class exponential2{
    public static void main(String[] args) {
        Scanner input =new Scanner(System.in);
        int num;
        int power;
        int ans=0;
        System.out.println("Enter Number:");
        num=input.nextInt();
       System.out.println("Enter exponenet:");
        power=input.nextInt();
        ans=Math.pow(num,power);
        
        System.out.println(ans);
    }

