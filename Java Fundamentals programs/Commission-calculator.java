import java.util.Scanner;

public class CommissionPercent {
    public static void main(String[] args) {
//        This program calculates Commission Percentage
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the amount ");
        int n = in.nextInt();
        int commission;
        if (n < 10000) {
            commission = n * 15/100;
        } else if (n < 50000) {
            commission = n * 20/100;
        } else {
            commission = n * 25/100;
        }
        System.out.println("The commission for " + n + " will be Rs:" + commission);
    }
}
