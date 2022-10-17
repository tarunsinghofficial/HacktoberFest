package com.tutorial;


class Tut{
    String nama;
    String alamat;

    Tut(String name, String alamat){
        this.nama = name;
        this.alamat = alamat;
    }
}

public class Main {
    public static void main(String[] args) {
        Tut tut1 = new Tut("putra","bekasi");
        System.out.println(tut1.nama  +  tut1.alamat);
        tut1.nama = "nanda";
        System.out.println(tut1.nama  +  tut1.alamat);
    }
}
