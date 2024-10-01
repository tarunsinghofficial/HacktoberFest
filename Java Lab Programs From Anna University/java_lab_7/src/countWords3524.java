import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

public class countWords3524 {
    public static void main(String[] args) {
        // Code for displaying student information and current date/time
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");
        LocalDateTime now = LocalDateTime.now();
        System.out.println("2021503524  " + "Mugundh J B  " + dtf.format(now));

        Scanner in = new Scanner(System.in);

        //Declaring the string variable and obtaining user input
        System.out.print("Enter a string: ");
        String str = in.nextLine();

        //Initialize the variable to track the number of words
        int count = 0;
        boolean inWord = false;

        //For loop to traverse the string
        for (char c: str.toCharArray())
        {
            if (Character.isWhitespace(c)) {
                // If a space is encountered, it indicates the end of a word
                inWord = false;
            } else {
                // If a non-space character is encountered
                // and we are not already in a word, it indicates the start of a new word
                if (!inWord) {
                    count++;
                    inWord = true;
                }
            }
        }

        System.out.println("Number of words = " + count);
    }
}
