import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

public class strPalindrome3524 {
    // Function to check if a given string is a palindrome
    public static boolean isPalindrome(String str) {
        int left = 0, right = str.length() - 1;
        while (left < right) {
            if (str.charAt(left++) != str.charAt(right--))
                return false; // If characters at left and right positions do not match, it's not a palindrome
        }
        return true; // If the loop completes without returning false, it's a palindrome
    }

    public static void main(String[] args) {
        // Code for displaying student information and current date/time
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");
        LocalDateTime now = LocalDateTime.now();
        System.out.println("2021503524  " + "Mugundh J B  " + dtf.format(now));

        Scanner in = new Scanner(System.in);

        System.out.print("Enter a string: ");
        String s = in.nextLine();

        // Check if the entered string is a palindrome and display the result
        if (isPalindrome(s))
            System.out.println(s + " is a Palindrome");
        else
            System.out.println(s + " is not a Palindrome");
    }
}
