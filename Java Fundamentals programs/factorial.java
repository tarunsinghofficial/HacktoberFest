import java.util.Scanner;
public class factorial {
    public static void main(String[] args) {
        Scanner obj=new Scanner(System.in);
        System.out.println("Please the enter the number that you have factorial of :");
        long a=obj.nextInt();
        long b=a;
        long result=a;
       
        for (int i=1;i<b;i++){
            a--;
             result =a*result;
       
        }
        System.out.println("The factorial of the number is :");
        System.out.println(result);

        
    }
}
