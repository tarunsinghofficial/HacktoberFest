import java.util.Scanner;

public class AccountTest{

    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
        Account myAccount = new Account("Stanley Brikkz", 23.44);
        System.out.println("Name: " + myAccount.getName());
        System.out.printf("Balance: $%.2f", myAccount.getBalance());
        
        System.out.println("Enter Amount To Deposit:");
        double depositAmt = input.nextDouble();
        myAccount.deposit(depositAmt);
        System.out.printf("New Balance: $%.2f", myAccount.getBalance());
    }
        
}