import java.util.Scanner;

public class Commission {
    public static void main(String[] args) {

//      Calculate Commission Percentage

        Scanner input = new Scanner(System.in);

        System.out.print("Enter Buying cost : ");
        int buyingCost = input.nextInt();

        System.out.print("Enter Selling price : ");
        int sellingPrice = input.nextInt();

        int difference = sellingPrice-buyingCost;
        int commission = (buyingCost*difference)/100;

        System.out.print("Commission : " + commission + " %");
    }
}