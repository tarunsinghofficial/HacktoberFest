import java.util.*;
import java.math.BigInteger;

class test {
    static int fact(int n) {
        if (n == 0)
            return 1;
        else
            return n * fact(n - 1);
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t;
        t = sc.nextInt();
        while (t-- > 0) {
            Integer n = sc.nextInt();
            BigInteger b = BigInteger.valueOf(1);
            for (Integer i = 1; i <= n; i++)
                b = b.multiply(BigInteger.valueOf(i));
            System.out.println(b);
        }

    }
}
