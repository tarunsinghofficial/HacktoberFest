import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class stringMethods3524 {
    public static void main(String[] args) {
        // Code for getting the current date and time
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");
        LocalDateTime now = LocalDateTime.now();
        System.out.println("2021503524  " + "Mugundh J B  " + dtf.format(now));

        // Initialize some strings
        String s1 = "Welcome to Java";
        String s2 = s1;
        String s3 = new String("Welcome to Java");
        String s4 = s1.intern();

        // String methods
        if (s1 == s2) System.out.println("s1 and s2 are equal (== function)");
        if (s2 == s3) System.out.println("s2 and s3 are equal (== function)");
        if (s1.equals(s2)) System.out.println("s1 and s2 are equal (equals function)");
        if (s2.equals(s3)) System.out.println("s2 and s3 are equal (equals function)");
        if (s1.compareTo(s2) == 0) System.out.println("s1 and s2 are equal (compareTo function)");
        if (s2.compareTo(s3) == 0) System.out.println("s2 and s3 are equal (compareTo function)");
        if (s1 == s4) System.out.println("s1 and s4 are equal (== function)");

        // String methods and operations
        System.out.println("s1.charAt(0): " + s1.charAt(0));
        System.out.println("Index of 'j' in s1: " + s1.indexOf('j'));
        System.out.println("Index of 'to' in s1: " + s1.indexOf("to"));
        System.out.println("Last index of 'a' in s1: " + s1.lastIndexOf('a'));
        System.out.println("Last index of 'o' in s1 from index 15: " + s1.lastIndexOf("o", 15));
        System.out.println("Length of s1: " + s1.length());
        System.out.println("Substring of s1 from index 5: " + s1.substring(5));
        System.out.println("Substring of s1 from index 5 to 11: " + s1.substring(5, 11));
        System.out.println("s1 starts with 'Wel': " + s1.startsWith("Wel"));
        System.out.println("s1 ends with 'Java': " + s1.endsWith("Java"));
        System.out.println("Lowercase of s1: " + s1.toLowerCase());
        System.out.println("Uppercase of s1: " + s1.toUpperCase());
        System.out.println("Trim: " + " Welcome ".trim());
        System.out.println("Replace 'o' with 'T': " + s1.replace('o', 'T'));
        System.out.println("Replace all 'o' with 'T': " + s1.replaceAll("o", "T"));
        System.out.println("Replace first 'o' with 'T': " + s1.replaceFirst("o", "T"));

        // Traverse the character array within the string
        System.out.print("Traversing the character array: ");
        for (char ch : s1.toCharArray()) {
            System.out.print(ch);
        }
    }
}
