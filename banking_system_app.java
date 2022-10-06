import java.util.Scanner;
class BankDetails {
    private String accountNumber;
    private String accountHolderName;
    private String accountType;
    private long accountBalance;
    Scanner sc = new Scanner(System.in);
    //method to open new account
    public void openAccount() {
        System.out.print("Enter Account No: ");
        accountNumber = sc.next();
        System.out.print("Enter Account type: ");
        accountType = sc.next();
        System.out.print("Enter Name: ");
        accountHolderName = sc.next();
        System.out.print("Enter Balance: ");
        accountBalance = sc.nextLong();
    }
    //method to display account details
    public void showAccount() {
        System.out.println("Name of account holder: " + accountHolderName);
        System.out.println("Account no.: " + accountNumber);
        System.out.println("Account type: " +accountType);
        System.out.println("Balance: " + accountBalance);
    }
    //method to deposit money
    public void deposit() {
        long amt;
        System.out.println("Enter the amount you want to deposit: ");
        amt = sc.nextLong();
        accountBalance = accountBalance + amt;
    }
    //method to withdraw money
    public void withdrawal() {
        long amt;
        System.out.println("Enter the amount you want to withdraw: ");
        amt = sc.nextLong();
        if (accountBalance >= amt) {
            accountBalance = accountBalance - amt;
            System.out.println("Balance after withdrawal: " + accountBalance);
        } else {
            System.out.println("Your balance is less than " + amt + "\tTransaction failed...!!" );
        }
    }
    //method to search an account number
    public boolean search(String ac_no) {
        if (accountNumber.equals(ac_no)) {
            showAccount();
            return (true);
        }
        return (false);
    }
}
public class BankingApp {
    public static void main(String arg[]) {
        Scanner sc = new Scanner(System.in);
        //create initial accounts
        System.out.print("How many number of customers do you want to input? ");
        int n = sc.nextInt();
        BankDetails C[] = new BankDetails[n];
        for (int i = 0; i < C.length; i++) {
            C[i] = new BankDetails();
            C[i].openAccount();
        }
        // loop runs until number 5 is not pressed to exit
        int ch;
        do {
            System.out.println("\n ***Banking System Application***");
            System.out.println("1. Display all account details \n 2. Search by Account number\n 3. Deposit the amount \n 4. Withdraw the amount \n 5.Exit ");
            System.out.println("Enter your choice: ");
            ch = sc.nextInt();
            switch (ch) {
                case 1:
                    for (int i = 0; i < C.length; i++) {
                        C[i].showAccount();
                    }
                    break;
                case 2:
                    System.out.print("Enter account no. you want to search: ");
                    String ac_no = sc.next();
                    boolean found = false;
                    for (int i = 0; i < C.length; i++) {
                        found = C[i].search(ac_no);
                        if (found) {
                            break;
                        }
                    }
                    if (!found) {
                        System.out.println("Search failed! Account doesn't exist..!!");
                    }
                    break;
                case 3:
                    System.out.print("Enter Account no. : ");
                    ac_no = sc.next();
                    found = false;
                    for (int i = 0; i < C.length; i++) {
                        found = C[i].search(ac_no);
                        if (found) {
                            C[i].deposit();
                            break;
                        }
                    }
                    if (!found) {
                        System.out.println("Search failed! Account doesn't exist..!!");
                    }
                    break;
                case 4:
                    System.out.print("Enter Account No : ");
                    ac_no = sc.next();
                    found = false;
                    for (int i = 0; i < C.length; i++) {
                        found = C[i].search(ac_no);
                        if (found) {
                            C[i].withdrawal();
                            break;
                        }
                    }
                    if (!found) {
                        System.out.println("Search failed! Account doesn't exist..!!");
                    }
                    break;
                case 5:
                    System.out.println("See you soon...");
                    break;
            }
        }
        while (ch != 5);
    }
}
