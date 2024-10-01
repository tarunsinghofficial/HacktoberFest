import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Locale;
import java.util.Scanner;

public class strAnagram3524 {
    // Function to check if two strings are anagrams
    public static void checkAnagrams(String str1, String str2) {
        // Initialize an array to store letter frequencies for lowercase English letters
        int[] freq = new int[26];

        // Convert both input strings to lowercase for case-insensitive comparison
        String s1 = str1.toLowerCase(), s2 = str2.toLowerCase();

        // Count the frequency of each letter in the first string
        for (int i = 0; i < s1.length(); i++)
            freq[s1.charAt(i) - 'a'] += 1;

        int flag = 0;
        // Compare the frequency of letters in the second string
        for (int i = 0; i < s2.length(); i++) {
            if (--freq[s2.charAt(i) - 'a'] < 0) {
                System.out.println(str1 + " and " + str2 + " are not anagrams");
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            System.out.println(str1 + " and " + str2 + " are anagrams");
    }

    public static void main(String[] args) {
        // Code for displaying student information and current date/time
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");
        LocalDateTime now = LocalDateTime.now();
        System.out.println("2021503524  " + "Mugundh J B  " + dtf.format(now));

        Scanner in = new Scanner(System.in);

        System.out.print("Enter a string 1: ");
        String str1 = in.nextLine();
        System.out.print("Enter a string 2: ");
        String str2 = in.nextLine();

        // Check if the lengths of the two strings are different
        if (str1.length() != str2.length())
            System.out.println(str1 + " and " + str2 + " are not anagrams");
        else
            checkAnagrams(str1, str2);  // Call the function to check if the strings are anagrams
    }
}
