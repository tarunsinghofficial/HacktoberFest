import java.util.*;

class armstrong {
    public static void main(String[] args) {
        int n, s, r, x;        // x is a temp variable
        System.out.println("Armstrong Numbers are: ");
        for (int n = 1; n <= 1000; n++) {
            s = 0;
            x = n;
            while (x != 0) {
                r = x % 10;
                s = s + (r * r * r);
                x = x / 10;
            }
            if (s == n)
                System.out.println(n);
        }
    }