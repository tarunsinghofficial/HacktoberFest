import java.util.Scanner;

import javax.lang.model.util.ElementScanner14;
    public class naveenreddyforloop2 {
         public static void main(String[] args) {
        Scanner sc=new Scanner (System.in);
        System.out.println("enter the number of rows and columns");
        int n= sc.nextInt();
        int l =sc.nextInt();
        sc.close();
            for(int i=1;i<=n;i++){
                for(int j=1;j<=l;j++){
                    if(i==1||i==n || j==1|| j== l ){

                      System.out.print("*");
                }
                   else{
                     System.out.print(" ");  
                   }
                }
                  System.out.println();           
            }
        }
        
    }
