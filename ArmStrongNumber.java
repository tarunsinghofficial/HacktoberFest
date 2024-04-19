import java.util.Scanner;

public class ArmStrongNumber {
    public static void main(String[] args) {
        int sum = 0, count = 0;
        String msg;
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a number to check: ");
        String value = scanner.next();

        char[] numArray = value.toCharArray();
        while (count < numArray.length) {
            sum += Math.pow(Double.parseDouble(String.valueOf(Integer.parseInt(String.valueOf(numArray[count])))), numArray.length);
            count++;
        }
        if (sum == Integer.parseInt(value)) {
            msg = value + " is an ArmStrongNumber";
        }
        else {
            msg = value + " is not an ArmStrongNumber";
        }

        System.out.println(msg);
    }
}
