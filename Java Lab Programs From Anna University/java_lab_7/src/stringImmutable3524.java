import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
public class stringImmutable3524 {
    public static void main(String[] args) {
        // Code for displaying student information and current date/time
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");
        LocalDateTime now = LocalDateTime.now();
        System.out.println("2021503524  " + "Mugundh J B  " + dtf.format(now));

        // Create a string object
        String originalString="Hello, ";

        // Concatenate another string
        originalString += "World!"; // Modifying the original string

        System.out.println("Strings are immutable in Java:\n");
        //Check if it is the same reference
        if (originalString == "Hello, World!") {
            System.out.println("The strings are the same reference.");
        } else {
            System.out.println("The strings are different references.");
        }

        //Check if the content is the same
        if (originalString.equals("Hello, World!")) {
            System.out.println("The content of the strings is the same.");
        } else {
            System.out.println("The content of the strings is different.");
        }
    }
}
