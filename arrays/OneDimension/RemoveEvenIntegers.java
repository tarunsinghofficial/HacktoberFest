/*
Java Program to remove all the Even Numbers from the given Array of size n.
 */

package arrays.OneDimension;


import java.util.Scanner;

public class RemoveEvenIntegers {
    Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        RemoveEvenIntegers inp = new RemoveEvenIntegers();
        int size = inp.sc.nextInt();
        int[] array = readArray(size);
        printArray(removeEven(array));
    }

    static int[] removeEven(int[] array){
        int newSize = 0;

        for(int i : array){
            if((i & 1) == 0){
                newSize++;
            }
        }
        int[] newArray = new int[newSize];
        int index = 0;
        for(int i: array){
            if((i & 1) != 0){
                newArray[index++] = i;
            }
        }
        return  newArray;
    }
    static  void printArray(int[] array){
        for(int i : array){
            System.out.println(i + " ");
        }
    }
    static int[] readArray(int size){
        RemoveEvenIntegers inp = new RemoveEvenIntegers();
        int[] array = new int[size];

        for(int i = 0; i < size; i++){
            array[i] = inp.sc.nextInt();
        }
        return  array;
    }
}
