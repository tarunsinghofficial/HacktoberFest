package arrays.Sorting;

import java.util.Arrays;
import java.util.Scanner;

public class InsertionSort {

    private int[] readArray(){
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();
        int[] newArray = new int[size];
        for(int i = 0 ; i < newArray.length; i++){
            newArray[i] = sc.nextInt();
        }
        return newArray;
    }

    private void insertionSort(int[] array){
        int i = 1, j, key;
        while(i < array.length){
            key = array[i];
            j = i - 1;
            while (j >= 0 && array[j] > key){
                array[j + 1] = array[j];
                j--;
            }
            array[j  +1] = key;
            i++;
        }
    }


    public static void main(String[] args) {
        InsertionSort sort = new InsertionSort();
        int[] array = sort.readArray();

        System.out.println("Array Before Sorting ");
        System.out.println(Arrays.toString(array));

        System.out.println("Array After Sorting ");
        sort.insertionSort(array);
        System.out.println(Arrays.toString(array));
    }
}
