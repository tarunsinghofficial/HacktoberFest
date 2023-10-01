/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Swap_the_numbers
{
public static void main (String[] args) throws java.lang.Exception
	{
	    try{
	    Scanner sc=new Scanner(System.in);
	    int t=sc.nextInt();
	    while(t-->0)
	    {
            int n,k;
            n=sc.nextInt();
            k=sc.nextInt();
            long arr[]=new long[n];
            for(int i=0;i<n;i++)
            {
                arr[i]=sc.nextLong();
            }
            if(k<=n)
            {
            for(int i=0;i<n;i++)
            {
                int j=i+k;
             if(j<n)
             {
                 if(arr[i]>arr[j])
                 {
                     
                 long temp=arr[i];
                 arr[i]=arr[j];
                 arr[j]=temp;
                 }
             }
            }
            
            for(int i=0;i<n;i++)
            {
                System.out.print(arr[i]+" ");
            }
            System.out.println();
            }
            
        }
	        
	    }catch(Exception e){
	       return; 
	    }
	}
}
