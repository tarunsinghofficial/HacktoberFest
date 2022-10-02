package arrays.Sorting;

import java.util.Arrays;
import java.util.Scanner;

public class BubbleSort {

    private int[] readArray(){
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();
        int[] newArray = new int[size];
        for(int i = 0 ; i < newArray.length; i++){
            newArray[i] = sc.nextInt();
        }
        return newArray;
    }

    private void bubbleSort(int[] array){
        for(int i = 0; i < array.length; i++){
            for(int j = 0; j < array.length - i - 1; j++){
                if(array[j] > array[j  + 1]){
                    int temp = array[j];
                    array[j] = array[j  + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }

    public static void main(String[] args) {
        BubbleSort sort = new BubbleSort();
        int[] array = sort.readArray();

        System.out.println("Array Before Sorting ");
        System.out.println(Arrays.toString(array));

        System.out.println("Array After Sorting ");
        sort.bubbleSort(array);
        System.out.println(Arrays.toString(array));
    }
}
