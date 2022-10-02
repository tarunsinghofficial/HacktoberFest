package arrays.Sorting;

import java.util.Scanner;

public class SelectionSort {

    public int[] selectionSort(int[] array){
        int min;
        for(int i = 0; i < array.length - 1; i++){
            min = i;
            for(int j =  i + 1; j < array.length; j++){
                if(array[j] < array[min]){
                    min = j;
                }
            }
            if(min != i){
                int temp = array[i];
                array[i] = array[min];
                array[min] = temp;
            }
        }

        return array;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        SelectionSort sort = new SelectionSort();
        int size = sc.nextInt();
        int[] array = new int[size];

        for(int i = 0; i < array.length; i++){
            array[i] = sc.nextInt();
        }

        array = sort.selectionSort(array);

        for(int i : array){
            System.out.print( i + " ");
        }
    }
}
