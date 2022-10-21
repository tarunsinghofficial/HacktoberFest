import java.util.*;

public class Exception {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int a=10;
        System.out.println("enter value of b");
        int b = sc.nextInt();
        try{
            System.out.println(a/b);
        }
        catch(ArithmeticException e){
            System.out.println(e.getMessage());
        }
    }
}
//The Exception Handling in Java is one of the powerful mechanism to handle the runtime errors 
//so that the normal flow of the application can be maintained.
//Suppose there are 10 statements in a Java program and an exception occurs at statement 5; the rest of the code will not be executed, i.e., 
//statements 6 to 10 will not be executed. However, when we perform exception handling, the rest of the statements will be executed.
//That is why we use exception handling in Java.


