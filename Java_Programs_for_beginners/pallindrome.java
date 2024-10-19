public class PalindromeChecker {

    // Main method to test the palindrome function
    public static void main(String[] args) {
        int number = 121; // Example number
        boolean result = isPalindrome(number);
        System.out.println(number + " is a palindrome: " + result);
    }

    // Function to check if a number is a palindrome
    public static boolean isPalindrome(int number) {
        // Convert the number to string
        String str = Integer.toString(number);
        return isPalindromeHelper(str, 0, str.length() - 1);
    }

    // Recursive helper function to check palindrome
    private static boolean isPalindromeHelper(String str, int left, int right) {
        // Base case: if left index is greater than or equal to right index
        if (left >= right) {
            return true;
        }
        // Check if characters at left and right indices are the same
        if (str.charAt(left) != str.charAt(right)) {
            return false;
        }
        // Recursive call with narrowed indices
        return isPalindromeHelper(str, left + 1, right - 1);
    }
}
