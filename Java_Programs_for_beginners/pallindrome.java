import java.util.Scanner;

public class PalindromeChecker {
    
    public static boolean isPalindrome(String str) {
        // Base case: If the string is empty or has one character
        if (str.length() <= 1) {
            return true;
        }
        
        // Check the first and last characters
        if (str.charAt(0) != str.charAt(str.length() - 1)) {
            return false;
        }
        
        // Recursive call with the substring that excludes the first and last characters
        return isPalindrome(str.substring(1, str.length() - 1));
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number: ");
        String input = scanner.nextLine();
        
        // Check if the input string represents a palindrome
        if (isPalindrome(input)) {
            System.out.println(input + " is a palindrome.");
        } else {
            System.out.println(input + " is not a palindrome.");
        }
        
        scanner.close();
    }
}
