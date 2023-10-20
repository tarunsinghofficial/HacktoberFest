import java.util.*;
public class gcd {
    public static void main (String args []){
        Scanner in = new Scanner (System.in);
        int a,b,i,p,gcd =0;
        System.out.println("ENTER TWO NUMBERS");
        a=in.nextInt();
        b=in.nextInt();
        p=a*b;
        for(i=1;i<p;i++){
            if(a%i==0 && b%i==0)
            gcd = i;

        }
        System.out.println("The GCD of two numbers:" +gcd);
    }
}
