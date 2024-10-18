public class Palindrome { 

    // Function that returns true if str is a palindrome 
    static boolean isPalindrome(String str) { 
        // Normalize the string: convert to lowercase and remove non-alphanumeric characters
        StringBuilder cleanedStr = new StringBuilder();
        for (char c : str.toCharArray()) {
            if (Character.isLetterOrDigit(c)) {
                cleanedStr.append(Character.toLowerCase(c));
            }
        }
        
        // Pointers pointing to the beginning and the end of the string
        int i = 0, j = cleanedStr.length() - 1; 

        // While there are characters to compare 
        while (i < j) { 
            // If there is a mismatch 
            if (cleanedStr.charAt(i) != cleanedStr.charAt(j)) 
                return false; 

            // Increment first pointer and decrement the other 
            i++; 
            j--; 
        } 

        // Given string is a palindrome 
        return true; 
    } 

    // Driver code 
    public static void main(String[] args) { 
        String str = "TATA"; 

        if (isPalindrome(str)) 
            System.out.print("Yes"); 
        else
            System.out.print("No"); 
    } 
}
