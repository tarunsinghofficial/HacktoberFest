package arrays.Searching;

import java.util.Scanner;

public class BinarySearch {
    Scanner sc = new Scanner(System.in);

    private int[] readArray(){
        int size = sc.nextInt();
        int[] array = new int[size];
        for(int i = 0 ; i < array.length; i++){
            array[i] = sc.nextInt();
        }
        return array;
    }

    private int binarySearch(int[] array, int target){
        int low = 0;
        int high = array.length - 1;
        while( low <= high){
            int mid = low + (high - low) / 2;
            if(target == array[mid]){
                return mid;
            }else if(target > array[mid]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        BinarySearch search = new BinarySearch();
        int[] array = search.readArray();
        int target = search.sc.nextInt();
        System.out.println(target + " is Found At index " +
                search.binarySearch(array, target));

    }
}
