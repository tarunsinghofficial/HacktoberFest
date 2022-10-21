import java.util.*;

public class BinarySearch {

    public static boolean Binarysearch(int[] arr,int l,int r,int key){
        int mid = l + (r-l)/2;
        if(l<=r){
            if(key==arr[mid]){
                return true;
            }
            else if(key<arr[mid]){
                return Binarysearch(arr,l,mid-1,key);
            }
            else{
                return Binarysearch(arr,mid+1,r,key);
            }
        }
        return false;
    }

    public static void main(String args[]){
        int[] arr = {3,5,6,7,9,11,23};//static array
        int[] array  = new int[7];//dynaamic array
        ArrayList<Integer> arrL = new ArrayList<Integer>();//array list
        for(int i=0;i<arr.length;i++){
            array[i] = arr[i];
            arrL.add(arr[i]);
        }
        Collections.sort(arrL);   //sorting of array list
        Arrays.sort(arr); //sorting in static array
        Arrays.sort(array); // sorting in dynamic array
        Scanner sc = new Scanner(System.in);
        System.out.println("enter the key");
        int key = sc.nextInt();

        if(Binarysearch(arr,0,arr.length-1,key) == true){
            System.out.println("yes key is present");
        }
        else{
            System.out.println("NO key is not present");
        }
    }
}
