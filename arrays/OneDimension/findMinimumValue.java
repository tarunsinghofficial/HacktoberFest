package arrays.OneDimension;

import java.util.Scanner;

public class findMinimumValue {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();
        int[] array = new int[size];

        for(int i = 0; i < array.length; i++){
            array[i] = sc.nextInt();
        }

        int min = array[0];
        for(int i = 0; i < array.length; i++){
            if(array[i] < min){
                min = array[i];
            }
        }
        System.out.println(min);

    }
}
