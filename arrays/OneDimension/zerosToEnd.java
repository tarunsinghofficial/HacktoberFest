/*
Java Program to Move all the zeroes in array to end of the Array.
 */
package arrays.OneDimension;

import java.util.Scanner;

public class zerosToEnd {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();
        int[] array = new int[size];

        for(int i = 0; i < array.length; i++){
            array[i] = sc.nextInt();
        }
        int j = 0;
        for(int i = 0; i < array.length; i++){
            if(array[i] != 0 && array[j] == 0){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
//                j++;
            }
            if(array[j] != 0){
                j++;
            }
        }

        for(int a : array){
            System.out.print(a + " ");
        }
    }
}
