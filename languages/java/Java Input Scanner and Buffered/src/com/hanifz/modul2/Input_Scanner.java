package com.hanifz.modul2;

import java.util.Scanner;

public class Input_Scanner {
    public static void main(String[] args) {
//        Scanner nama_variable = new Scanner(System.in);
        Scanner scanner = new Scanner(System.in);
        Scanner scanner1 = new Scanner(System.in);

        int angka;
        String kata, kalimat;
        char karakter;

//        input nilai
        System.out.print("Masukan sebuah angka\t: ");
        angka = scanner.nextInt();

        System.out.print("Masukan sebuah kata\t: ");
        kata = scanner.next();

        System.out.print("Masukan sebuah karakter\t: ");
        karakter = scanner.next().charAt(0);

        System.out.print("Masukan sebuah kalimat\t: ");
        kalimat = scanner1.nextLine();

//        tampilkan nilai
        System.out.println("Angka\t: " + angka);
        System.out.println("Kata\t: " + kata);
        System.out.println("Karakter\t: " + karakter);
        System.out.println("Kalimat\t: " + kalimat);

    }
}
