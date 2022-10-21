import java.util.*;

public class Finallyexample {
    
    public static void main(String args[]){    
      try{    
      //below code do not throw any exception  
         int data=25/5;    
         System.out.println(data);    
      }    
      //catch won't be executed  
      catch(NullPointerException e){  
      System.out.println(e);  
      }    
      //executed regardless of exception occurred or not  
      finally {  
      System.out.println("finally block is always executed");  
      }    
          
      System.out.println("rest of phe code...");    
    }    
}
//Java finally block is always executed whether an exception is handled or not.
//Therefore, it contains all the necessary statements that need to be printed regardless of the exception occurs or not.