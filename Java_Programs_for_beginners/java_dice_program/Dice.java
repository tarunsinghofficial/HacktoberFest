import java.util.Random;

public class Dice {
    public Dice() {
        acakNilai();
    }

    int acakNilai() {
        Random nilai = new Random();
        return 1 + nilai.nextInt(6);
    }
}
