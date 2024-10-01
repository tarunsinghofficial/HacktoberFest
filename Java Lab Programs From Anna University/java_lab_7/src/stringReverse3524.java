import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

public class stringReverse3524 {

    // Function to perform string reverse operation
    public static void reverse(String str){
        // Since, string is immutable, converting string to char array for mutations
        char[] s = str.toCharArray();

        int n = str.length(), mid = n / 2;
        // Performing swap until mid
        for(int i = 0; i <= mid; i++){
            // Swapping the characters
            char t = s[i];
            s[i] = s[n - i - 1];
            s[n - i - 1] = t;
        }

        // Converting char array to string
        String reverse = new String(s);

        System.out.println("Reverse of string: " + reverse);
    }

    public static void main(String[] args) {
        // Code for displaying student information and current date/time
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");
        LocalDateTime now = LocalDateTime.now();
        System.out.println("2021503524  " + "Mugundh J B  " + dtf.format(now));

        Scanner in = new Scanner(System.in);
        // Getting string as input
        System.out.print("Enter a string: ");
        String str = in.nextLine();

        reverse(str); // Function to reverse the string

    }
}
