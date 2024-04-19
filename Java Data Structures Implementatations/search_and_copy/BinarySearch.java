/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package search_and_copy;

import stack.*;

/**
 *
 * @author Zohaib Hassan Soomro
 */
public class BinarySearch {

public static int search(int[] a, int x) {
    int p = 0, q = a.length - 1;
    while (p <= q) {
        int i = (p + q) / 2;
        if (a[i] == x) {
            return i;
        }
        if (a[i] < x) {
            p = i + 1;
        } else {
            q = i - 1;
        }
    }
    return -1;
}

public static void main(String[] args) {
    int array[] = {22, 33, 44, 55, 66, 77, 55, 88};
    System.out.println("Index of " + 55 + " is " + search(array, 55));
    System.out.println("Index of " + 56 + " is " + search(array, 56));
}
}
