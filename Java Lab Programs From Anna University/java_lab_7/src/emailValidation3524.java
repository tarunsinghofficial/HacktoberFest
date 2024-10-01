import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

public class emailValidation3524 {
    public static boolean isValidEmail(String email) {
        // Check for the presence of "@" symbol for a valid email
        if (!email.contains("@")) {
            return false;
        }

        // Split the email into username and domain
        String[] parts = email.split("@");
        if (parts.length != 2) {
            return false;
        }

        // Check the validity of the username
        String username = parts[0];
        if (!isValidUsername(username)) {
            return false;
        }

        // Check the validity of the domain
        String domain = parts[1].toLowerCase();
        if (!(domain.endsWith(".com") || domain.endsWith(".in") || domain.endsWith(".edu"))) {
            return false;
        }

        // Check for a valid domain name
        if (!isValidDomain(domain)) {
            return false;
        }

        return true;
    }

    public static boolean isValidUsername(String username) {
        // Valid username: numbers[0-9], alphabets[a-zA-Z], underscore, dot, hyphen, and plus characters
        String regex = "^[0-9a-zA-Z_.+-]+$";
        return username.matches(regex);
    }

    public static boolean isValidDomain(String domain) {
        // Valid domain name: Only alphabets and hyphens are allowed
        String regex = "^[a-zA-Z-.]+$";
        return domain.matches(regex);
    }

    public static void main(String[] args) {
        // Code for getting the current date and time
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");
        LocalDateTime now = LocalDateTime.now();
        System.out.println("2021503524  " + "Mugundh J B  " + dtf.format(now));

        Scanner in = new Scanner(System.in);
        System.out.print("Enter the email: ");
        String email = in.nextLine();

        if (isValidEmail(email)) {
            String[] parts = email.split("@");
            String username = parts[0];
            String domain = parts[1];
            System.out.println("Username: " + username);
            System.out.println("Domain: " + domain);
            System.out.println("Valid Email");
        } else {
            System.out.println("Invalid Email");
        }

    }
}
