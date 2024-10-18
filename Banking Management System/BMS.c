#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store account information
struct Account {
    int accountNumber;
    char accountHolderName[100];
    float balance;
};

// Function prototypes
void createAccount(struct Account *acc);
void depositMoney(struct Account *acc);
void withdrawMoney(struct Account *acc);
void checkBalance(struct Account *acc);

int main() {
    struct Account acc;
    int choice;

    while (1) {
        printf("\n=== Banking Management System ===\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(&acc);
                break;
            case 2:
                depositMoney(&acc);
                break;
            case 3:
                withdrawMoney(&acc);
                break;
            case 4:
                checkBalance(&acc);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to create a new account
void createAccount(struct Account *acc) {
    printf("Enter Account Number: ");
    scanf("%d", &acc->accountNumber);
    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]", acc->accountHolderName);
    acc->balance = 0.0;
    printf("Account created successfully!\n");
}

// Function to deposit money into the account
void depositMoney(struct Account *acc) {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    if (amount > 0) {
        acc->balance += amount;
        printf("Successfully deposited %.2f. New balance: %.2f\n", amount, acc->balance);
    } else {
        printf("Invalid amount! Please enter a positive value.\n");
    }
}

// Function to withdraw money from the account
void withdrawMoney(struct Account *acc) {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount > 0 && amount <= acc->balance) {
        acc->balance -= amount;
        printf("Successfully withdrew %.2f. New balance: %.2f\n", amount, acc->balance);
    } else {
        printf("Invalid amount! Please ensure you have sufficient balance.\n");
    }
}

// Function to check the account balance
void checkBalance(struct Account *acc) {
    printf("Current balance: %.2f\n", acc->balance);
}
