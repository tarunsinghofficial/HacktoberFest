import java.util.*;
public class Max_element_arr{
    public static void main(String args[]){
        Scanner sc=new Scanner (System.in);
        System.out.print("Enter the size of the array: ");
        int n=sc.nextInt();
        int[] arr= new int[n];
        for(int i=0;i<n;i++){
            int a=sc.nextInt();
            arr[i]=a;
        }

        int max=arr[0];
        for (int i=0; i<n;i++ ){
            if(arr[i]>max){
                max=arr[i];
            }
        }
        System.out.println("The largest of all elements is:"+max);

    
    }
}
