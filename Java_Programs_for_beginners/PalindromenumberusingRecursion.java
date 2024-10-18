import java.util.Scanner;

public class Palindrome {
    
    // Recursive function to reverse the number
    public static int reverseNumber(int num, int reversed) {
        if (num == 0) {
            return reversed;
        }
        int remainder = num % 10;
        reversed = (reversed * 10) + remainder;
        return reverseNumber(num / 10, reversed);
    }

    // Function to check if a number is a palindrome
    public static boolean isPalindrome(int num) {
        int reversed = reverseNumber(num, 0);
        return num == reversed;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int num = scanner.nextInt();
        scanner.close();

        if (isPalindrome(num)) {
            System.out.println(num + " is a palindrome.");
        } else {
            System.out.println(num + " is not a palindrome.");
        }
    }
}
