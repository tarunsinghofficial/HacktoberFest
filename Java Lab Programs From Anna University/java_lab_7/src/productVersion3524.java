import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

public class productVersion3524 {
    public static void main(String[] args) {
        // Code for displaying student information and current date/time
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");
        LocalDateTime now = LocalDateTime.now();
        System.out.println("2021503524  " + "Mugundh J B  " + dtf.format(now));

        Scanner in = new Scanner(System.in);

        System.out.print("Enter string 1: ");
        String s1 = in.nextLine();

        System.out.print("Enter string 2: ");
        String s2 = in.nextLine();

        // Split the input strings by dot (.) to compare version numbers
        String[] res1 = s1.split("\\.");
        String[] res2 = s2.split("\\.");

        System.out.println();
        // Compare version numbers component by component
        for(int i = 0; i < res1.length; i++) {
            // Accessing the substrings of version numbers and parsing them as integer
            if(Integer.parseInt(res1[i]) > Integer.parseInt(res2[i])) {
                System.out.println(s1 + " is greater than " + s2 + " as " + res1[i] + " > " + res2[i]);
                break;
            }
            else if(Integer.parseInt(res1[i]) < Integer.parseInt(res2[i])) {
                System.out.println(s2 + " is greater than " + s1 + " as " + res2[i] + " > " + res1[i]);
                break;
            }
        }
    }
}
