import java.util.*;
public class niven {
    public static void main (String args[]){
      Scanner in = new Scanner (System.in);
      int num,sum=0,d,p;
      System.out.println("enter the number");
      num = in.nextInt();
      p=num;
      while(num !=0){
        d=num%10;
        sum=sum+d;
        num=num/10;
      }
      if(p%sum==0){
        System.out.println("Niven Number");
      }
      else{
        System.out.println("Not a niven number");
      }
    }
}
