package arrays.OneDimension;

import java.util.Scanner;

public class SecondLargest {

    static int secondLargest(int[] array){
        int max, secondMax;
        max = secondMax = Integer.MIN_VALUE;

        for(int x : array){
            if(x > max){
                secondMax = max;
                max = x;
            }else if(x > secondMax && x != max){
                return secondMax;
            }
        }
    return secondMax;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] array;
        int size;
        size = sc.nextInt();
        array = new int[size];

        //Taking User Input for the Array.
        for(int i = 0; i < array.length; i++){
            array[i] = sc.nextInt();
        }

        System.out.println(secondLargest(array));

    }
}
