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
public class ArrayCopy {

public static void main(String[] args) {
    String[] a = {"Zohaib", "hassan", "Soomro", "Muet", "Jamshoro"};
    String a2[] = new String[7];
    System.arraycopy(a, 0, a2, 0, a.length);
    a2[5] = "HI";
    a2[6] = "HI 2";

    for (String string : a2) {
        System.out.println(string);
    }

}
}
