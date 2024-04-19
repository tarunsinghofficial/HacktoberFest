package arrays.Sorting;

import java.util.Arrays;
import java.util.Scanner;

public class MergeSort {

    public int[] readArray(){
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();
        int[] array = new int[size];
        for(int i = 0; i < array.length; i++){
            array[i] = sc.nextInt();
        }
        return array;
    }

    public void printArray(int[] array){
        System.out.println(Arrays.toString(array));
    }

    public void sort(int[] array, int[] temp, int low, int high){

        if(low < high) {
            int mid = low + (high - low) / 2;
            sort(array, temp, low, mid);
            sort(array, temp, mid + 1, high);
            merge(array, temp, low, mid, high);
        }
    }

    private void merge(int[] array, int[] temp, int low, int mid, int high) {

        for(int i = 0; i < array.length; i++){
            temp[i] = array[i];
        }

        int i = low;
        int j = mid + 1;
        int k = low;

        while(i <= mid && j <= high){
            if(temp[i] <= array[j]){
                array[k] = temp[i];
                i++;
            }else{
                array[k] = temp[j];
                j++;
            }
            k++;
        }

        while(i <= mid){
            array[k] = temp[i];
            i++;
            k++;
        }
    }


    public static void main(String[] args) {
        MergeSort sort = new MergeSort();
        int[] array = sort.readArray();
        System.out.println("Array Before Sorting :");
        sort.printArray(array);

        System.out.println("Array after Sorting : ");
        sort.sort(array, new int[array.length], 0, array.length - 1);
        sort.printArray(array);

    }
}
