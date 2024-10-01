import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

public class letterOccurance3524 {
    public static void main(String[] args) {
        // Code for displaying student information and current date/time
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");
        LocalDateTime now = LocalDateTime.now();
        System.out.println("2021503524  " + "Mugundh J B  " + dtf.format(now));

        Scanner in = new Scanner(System.in);

        System.out.print("Enter a string: ");
        String s = in.nextLine();

        int[] freq = new int[256];
        int n = s.length();

        for (int i = 0; i < n; i++)
            freq[s.charAt(i)] += 1; // Use the character itself as the index

        System.out.println("Letter Occurrence: ");
        for (int i = 0; i < 256; i++) {
            // Converting int to ASCII char code
            char ch = (char) i;
            if (freq[i] > 0)
                System.out.printf("%c - %d\n", ch, freq[i]); // Print the character 'ch'
        }
    }
}
