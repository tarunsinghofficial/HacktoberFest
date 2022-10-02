/*
Java Program to revers the Given array of size n.
 */

package arrays.OneDimension;

import java.util.Scanner;

public class ReversArray {
    Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        ReversArray ra = new ReversArray();
        int size = ra.sc.nextInt();
        int[] array = ra.readArray(size);
        System.out.println("Array Before Reversing : ");
        ra.printArray(array);
        System.out.println();
        System.out.println("Array After Reversing : ");
        ra.printArray(ra.reversArray(array));



    }

    int[] reversArray(int[] array){
        int start = 0;
        int end = array.length - 1;
        while(start < end){
            int temp = array[start];
            array[start] = array[end];
            array[end] = temp;
            start++;
            end--;
        }
        return array;
    }
    void printArray(int[] array){
        for(int i: array){
            System.out.print(i + " ");
        }
    }
    int[] readArray(int size){
        ReversArray rv = new ReversArray();
        int[] array = new int[size];
        for(int i = 0; i < array.length; i++){
            array[i] = rv.sc.nextInt();
        }
        return array;
    }
}
