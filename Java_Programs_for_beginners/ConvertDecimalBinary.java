package Java_Programs_for_beginners;

import java.util.Arrays;

public class ConvertDecimalBinary {
    public static String convertDecimalToBinary(int num) {
        int binary[] = new int[40];
        int index = 0;
        StringBuilder res = new StringBuilder();
        while (num > 0) {
            binary[index++] = num % 2;
            num = num / 2;
        }
        for (int i = index - 1; i >= 0; i--) {
            res.append(binary[i]);
        }
        return res.toString();
    }
}
