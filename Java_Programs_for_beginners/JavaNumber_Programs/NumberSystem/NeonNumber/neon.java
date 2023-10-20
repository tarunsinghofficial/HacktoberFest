import java.util.*;
public class neon {
public static void main (String args []){
    Scanner in = new Scanner(System.in);
    System.out.println("Enter the number");
    int n = in.nextInt();
    int p,s=0,d;
    p=n*n;
    while(p!=0){
        d=p%10;
        s=s+d;
        p=p/10;
    }
    if(s==n)
    System.out.println("It is a neon number");
    else
    System.out.println("It is not a Neon number");
}    
}
 