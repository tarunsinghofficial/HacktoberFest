import java.util.Scanner;

public class LuckyNumber {

    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int k = input.nextInt();
        int count = 0;
        while (n > 0) {
            int lucky = 0;
            char result[] = input.next().toCharArray();
            for (int i = 0; i < result.length; ++i) {
                if (result[i] == '4' || result[i] == '7') {
                    lucky += 1;
                }
            }
            if (lucky <= k) {
                count += 1;
            }
            n--;
        }
        System.out.println(count);
    }
} 