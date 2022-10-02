package arrays.Searching;

import java.util.Arrays;
import java.util.Scanner;

public class LinearSearch {
    Scanner sc = new Scanner(System.in);
    private int[] readArray() {

        int size = sc.nextInt();
        int[] array = new int[size];
        for(int i = 0; i < array.length; i++){
            array[i] = sc.nextInt();
        }
        return array;
    }


    private int linearSearch(int[] array, int target) {

        for(int i = 0; i < array.length; i++){
            if(array[i] == target){
                return i;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        LinearSearch search = new LinearSearch();
        int[] array = search.readArray();
        int target = search.sc.nextInt();
        System.out.println(Arrays.toString(array));

        System.out.println(target + " is Found at index "
                + search.linearSearch(array, target));
    }

}
