package com.hanifz.modul2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Input_Buffered {
    public static void main(String[] args) throws IOException {
//        Deklarasi variable
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        String kalimat, kata;
        int angka;

        /*
        * variable kalimat -> amplop
        * bufferedReader -> kertas
        * terminal -> pulpen
        */

        System.out.print("Inputkan kata\t\t: ");
        kata = bufferedReader.readLine();

        System.out.print("Inputkan kalimat\t: ");
        kalimat = bufferedReader.readLine();

        System.out.print("Inputkan angka\t\t: ");
        angka = Integer.parseInt(bufferedReader.readLine());


        System.out.println("\nOutput kata\t: " +kata);
        System.out.println("Output kalimat\t: " +kalimat);
        System.out.println("Output angka\t: " +angka);

    }
}
