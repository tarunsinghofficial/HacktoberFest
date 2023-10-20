package NumberSystem.isbnNumber;
import java.util.*;
public class isbn {
    public static void main(String args[]){
        Scanner in = new Scanner (System.in);
        int n,n1,i,r,sum=0,c=0;
        System.out.println("Enter a 10 digit code");
        n= in.nextInt();
        n1=n;
        while(n1>0){
            n1=n1/10;
            c++;
        }
        if(c<10 && c>10){
            System.out.println("Illegal ISBN");
        }
        else{
            for(i=10;i>=1;i++){
                r=n%10;
                sum=sum + r*i;
                n=n/10;
            }
            if(sum%11 ==0){
                System.out.println("A valid ISBN number");
            }
            else{
                System.out.println("Not a valid ISBN number");
            }
        }
    }
}
