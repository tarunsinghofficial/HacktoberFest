package Minggu5;

import java.util.Scanner;

public class MainPangkat {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("====================================");
    System.out.print("Masukkan jumlah elemen yang ingin dihitung : ");
    int elemen = sc.nextInt();
    Pangkat[] png = new Pangkat[elemen];
    for (int i = 0; i < elemen; i++) {
      System.out.print("Masukkan nilai yang akan dipangkatkan ke-" + (i + 1) + ": ");
      int bil = sc.nextInt();
      System.out.println("Masukkan nilai pemangkat ke-" + (i + 1) + ": ");
      int pang = sc.nextInt();
      png[i] = new Pangkat(bil, pang);
    }
    for (int i = 0; i < elemen; i++) {
      png[i].Menu();
      do {
        System.out.println("Pilih Menu");
        System.out.println("====================================");
        System.out.println("1. Brute Force");
        System.out.println("2. Divide Conquer");
        System.out.println("3. Keluar");
        System.out.println("Masukkan pilihan anda : ");
        int pilih = sc.nextInt();
        switch (pilih) {
          case 1:
            System.out.println("====================================");
            System.out.println("Hasil Pangkat dengan Brute Force");
            for (int j = 0; j < elemen; j++) {
              System.out.println("Nilai " + png[j].nilai + " pangkat " + png[j].pangkat + " adalah : "
                  + png[j].pangkatBF(png[j].nilai, png[j].pangkat));
            }
            break;
          case 2:
            System.out.println("====================================");
            System.out.println("hasil Pangkat dengan Divide dan Conquer");
            for (int j = 0; j < elemen; j++) {
              System.out.println("Nilai " + png[j].nilai + " pangkat " + png[j].pangkat + " adalah : "
                  + png[j].pangkatDC(png[j].nilai, png[j].pangkat));
            }
            break;
          case 3:
            System.exit(0);
        }
      } while (true);
    }
    System.out.println("====================================");
  }
}
