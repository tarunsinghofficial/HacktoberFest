
import java.util.*;

public class initialiserblock {
    /* it's a programm on static intilizer block concept in java,where the exception is thrown if one of the 
    input is negative or both*/
    static Scanner sc =new Scanner(System.in);
      static  int b = sc.nextInt();
       static int h = sc.nextInt();
       static boolean flag =true;
     static {
       try{
           if(b<=0 || h<=0){
               flag= false;
               throw new Exception("Breadth and height must be positive");
           }
       }catch(Exception e){
           System.out.println(e);
       }
         
     }
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
          if(flag){
              int area=b*h;
              System.out.println(area);
          }
    
    }
}