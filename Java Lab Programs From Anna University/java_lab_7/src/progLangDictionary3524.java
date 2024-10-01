import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

public class progLangDictionary3524 {

    // Method to search for a programming language definition
    public static String search(String[][] pL, String str) {
        // Checking the match for programming language in dictionary
        for (int i = 0; i < 10; i++) {
            if (str.equalsIgnoreCase(pL[i][0])) // Comparing strings to find out if they are equal, ignoring case differences
                return pL[i][1];
        }
        return "";
    }

    public static void main(String[] args) {
        // Code for displaying student information and current date/time
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");
        LocalDateTime now = LocalDateTime.now();
        System.out.println("2021503524  " + "Mugundh J B  " + dtf.format(now));

        Scanner in = new Scanner(System.in);

        // Create a 2D array to store programming language definitions
        String[][] pL = {
                {"Java", "Java is a pure object-oriented programming language developed by James Gosling."},
                {"C++", "C++ is an object-oriented programming language developed by Bjarne Stroustrup."},
                {"Python", "Python is a high-level programming language known for its readability and versatility."},
                {"JavaScript", "JavaScript is a versatile scripting language commonly used for web development."},
                {"C#", "C# is a modern, object-oriented programming language developed by Microsoft."},
                {"Ruby", "Ruby is a dynamic and expressive scripting language."},
                {"PHP", "PHP is a server-side scripting language widely used for web development."},
                {"Swift", "Swift is a fast and powerful programming language developed by Apple for iOS and macOS."},
                {"Go", "Go is a statically typed, compiled language known for its efficiency and simplicity."},
                {"Rust", "Rust is a systems programming language focused on safety and performance."}
        };

        System.out.print("Enter string to be searched in dictionary: ");
        String str = in.nextLine();

        // Search for the programming language definition
        String res = search(pL, str);

        // Display the result or a message if not found
        if (res != "")
            System.out.println(str + " : " + res);
        else
            System.out.println("Programming Language not found in Dictionary");
    }
}
