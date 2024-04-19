import java.util.*;
public class pascal {
    

   
    
    
    public static void main(String[] args) {
        int numRows = 5;

        for (int i = 0; i < numRows; i++) {
            int number = 1; // Initialize the first number in each row to 1
            for (int j = 0; j < numRows - i; j++) {
                System.out.print("  "); // Add spaces for formatting
            }

            for (int j = 0; j <= i; j++) {
                System.out.print("  "); // Add spaces for formatting
                System.out.print(number);
                System.out.print("  "); // Add spaces for formatting
                number = number * (i - j) / (j + 1);
            }

            System.out.println(); // Move to the next row
        }
    }
}
