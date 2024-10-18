import java.util.Scanner;

public class StringGame {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String currentString = "";

        System.out.println("Welcome to the String Game!");
        System.out.println("Enter a string to start: ");
        currentString = scanner.nextLine();

        int choice;
        do {
            System.out.println("\nCurrent String: " + currentString);
            System.out.println("Choose an operation:");
            System.out.println("1. Reverse the string");
            System.out.println("2. Convert to uppercase");
            System.out.println("3. Find a substring");
            System.out.println("4. Concatenate another string");
            System.out.println("5. Exit");
            choice = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            switch (choice) {
                case 1:
                    currentString = new StringBuilder(currentString).reverse().toString();
                    System.out.println("String reversed.");
                    break;
                case 2:
                    currentString = currentString.toUpperCase();
                    System.out.println("Converted to uppercase.");
                    break;
                case 3:
                    System.out.println("Enter the substring to find:");
                    String substring = scanner.nextLine();
                    if (currentString.contains(substring)) {
                        System.out.println("Substring found at index: " + currentString.indexOf(substring));
                    } else {
                        System.out.println("Substring not found.");
                    }
                    break;
                case 4:
                    System.out.println("Enter the string to concatenate:");
                    String toConcat = scanner.nextLine();
                    currentString = currentString + toConcat;
                    System.out.println("String concatenated.");
                    break;
                case 5:
                    System.out.println("Exiting the game. Goodbye!");
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        } while (choice != 5);

        scanner.close();
    }
}
