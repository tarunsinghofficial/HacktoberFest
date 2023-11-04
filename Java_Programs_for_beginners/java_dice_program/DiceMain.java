import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class DiceMain {
    public static void main(String[] args) {
        Dice dadu = new Dice();
        Scanner sc = new Scanner(System.in);
        List<Integer> kumpulanAngka = new LinkedList<>();
        int n = sc.nextInt();
        int total = 0;

        for (int i = 0; i < n; i++) {
            kumpulanAngka.add(dadu.acakNilai());
            System.out.println("Dadu ke-" + (1 + i) + " bernilai " + kumpulanAngka.get(i));
            total += kumpulanAngka.get(i);
        }
        System.out.println("Total nilai dadu keseluruhan " + total);
        sc.close();
    }
}
