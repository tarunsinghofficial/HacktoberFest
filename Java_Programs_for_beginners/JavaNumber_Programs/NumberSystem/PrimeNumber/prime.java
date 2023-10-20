import java.util.*;
public class prime {
    public static void main (String args[]){
        Scanner in = new Scanner(System.in);
        int a,n,c=0;
        System.out.println("Enter a number");
        n=in.nextInt();
        for(a=1;a<=n;a++){
            if(n%a==0)
            c++;
        }
        if(c==2)
        System.out.println("prime number");
        else
        System.out.println("Not a prime number");
    }
}
