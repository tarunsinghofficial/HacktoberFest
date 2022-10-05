import java.util.*;
public class Min_element_arr {
    public static void main(String args[]){
        Scanner sc=new Scanner (System.in);
        System.out.print("Enter the size of the array: ");
        int n=sc.nextInt();
        int[] arr= new int[n];
        for(int i=0;i<n;i++){
            int a=sc.nextInt();
            arr[i]=a;
        }

        int min=arr[0];
        for (int i=0; i<n;i++ ){
            if(arr[i]<min){
                min=arr[i];
            }
        }
        System.out.println("The smallest of all elements is:"+min);

    
    }
}
