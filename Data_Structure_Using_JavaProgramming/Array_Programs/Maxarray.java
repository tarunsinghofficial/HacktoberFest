// Find Maximum Element of An Array In Java:

package Data_Structure_Using_JavaProgramming.Array_Programs;
import  java.util.*;

public class Maxarray {
    public static void main(String[] args)
    {
    int n, max;
    Scanner s = new Scanner(System.in);
    System.out.print("Enter the number of elements in the array:");
    n = s.nextInt();
    int a[] = new int[n];
    System.out.println("Enter the elements of array:");
    for(int i = 0; i < n; i++)
    {
    a[i] = s.nextInt();
    }
    max = a[0];
    for(int i = 0; i < n; i++)
    {
    if(max < a[i])
    {
    max = a[i];
    }
    }
    System.out.println("Maximum value in the array is:"+max);
    }
    
}
